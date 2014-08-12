#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;

class Stream{
private:
    map<char,unsigned int> lookup;
    string input;
    int index;

public:
    Stream(const string& in) {
        this->input = in;
        this->index = 0;

    }

    char getNextCharacter() {
        char tmp = this->input[this->index++];
        this->add(tmp);
        return tmp;
    }

    bool isEnd() {
        return this->index == this->input.size()-1;
    }

    unsigned int add(char key) {
        if (this->lookup.find(key) == this->lookup.end()) {
            this->lookup[key] = 0;
        } else {
            this->lookup[key] =  this->lookup[key] + 1;
        }
    }

    void print() {
        map<char, unsigned int>::iterator  iter;
        for(iter = this->lookup.begin(); iter != this->lookup.end(); iter++) {
            cout << iter->first << " = " << iter->second << endl;
        }
    }
};

int main() {
    Stream test("ICELANDIC");
    for (int i=0; i<9; i++) {
        cout << test.getNextCharacter() << endl;
    }
    // print the map content to know the counter for each key
    test.print();
    return 0;
}

