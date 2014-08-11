#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct point {
    double x, y;
    point() {
        this->x =0;
        this->y = 0;
    }
    point(double _x, double _y) {
        this->x = _x;
        this->y = _y;
    }
};

point reference(0, 0);

double distance(const point& p) {
    double diff_x = (p.x - reference.x) * (p.x - reference.x);
    double diff_y = (p.y - reference.y) * (p.y - reference.y);
    return sqrt(diff_x + diff_y);
}

vector<point> makeRandomList(int count) {
    vector<point> list(count);
    for (int i=0; i<count; i++) {
        point tmp(rand() % 1000 + 1, rand() % 1000 + 1);
        list[i] = tmp;
    }
    return list;
}

bool operator<(const point& a, const point& b) {
    return distance(a) < distance(b);
}

void printNearest(vector<point>& list, int k, const point& ref) {
    reference = ref;
    cout << "The list size: " << list.size() << endl;
    cout << "The reference point is " << ref.x << "," << ref.y << endl;
    // use stable sorting algorithm to sort the list
    std::stable_sort(list.begin(), list.end());
    cout << "head " << k << " items: " << endl;
    for (int i=0; i< k; i++) {
        cout << list[i].x << ", " << list[i].y << endl;
    }
}

int main() {
    srand (time(NULL));
    vector<point> list = makeRandomList(100);
    point ref_tmp(rand() % 1000 + 1, rand() % 1000 + 1);
    printNearest(list, 10, ref_tmp);
    return 0;
}

