#include <iostream>
#include <cstdlib>

using namespace std;

void print(int number[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;
}

void bubble(int number[], int len)
{
    print(number, len);
    int temp;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len-1-i;j++)
        {
            if(number[j]>number[j+1])
            {
                temp=number[j];
                number[j]=number[j+1];
                number[j+1]=temp;
            } //if end
        }
    }
    print(number, len);
}

int main()
{
    int number[12] = {95,45,15,78,84,51,24,12,56,74,11,23};
    bubble(number, 12);

    return 0;
}

