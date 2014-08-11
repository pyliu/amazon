#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

/*capacity is total capacity of a string, which is longer than its actual length*/
void replaceBlank(char string[], int capacity) {
    int originalLength, numberOfBlank, newLength;
    int i, indexOfOriginal, indexOfNew;

    if(string == 0 || capacity <= 0)
        return;

    /*originalLength is the actual length of string*/
    originalLength = numberOfBlank = i = 0;
    while(string[i] != '\0') {
        ++ originalLength;

        if(string[i] == ' ')
            ++ numberOfBlank;

        ++ i;
    }

    /*newLength is the length of the replaced string*/
    newLength = originalLength + numberOfBlank * 2;
    if(newLength > capacity)
        return;

    indexOfOriginal = originalLength;
    indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
        if(string[indexOfOriginal] == ' ') {
            string[indexOfNew --] = '0';
            string[indexOfNew --] = '2';
            string[indexOfNew --] = '%';
        }
        else {
            string[indexOfNew --] = string[indexOfOriginal];
        }

        -- indexOfOriginal;
    }
}

int main() {
    string tmp("Hello World! This is a test!!");
    char* buffer = new char[tmp.length()+1+5*2];

    cout << "size: " << tmp.size() << endl;
    cout << "length: " << tmp.length() << endl;
    size_t length = tmp.copy(buffer, tmp.length(), 0);
    cout << "copied: " << length << endl;
    cout << "strlen: " << strlen(buffer) << endl;

    cout << "original: " << tmp << endl;

    replaceBlank(buffer, tmp.length()+1+5*2);
    cout << "after: " << buffer << endl;

    delete [] buffer;

    return 0;
}
