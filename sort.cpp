#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void print(const string& prefix, int number[], int len)
{
    cout << prefix;
    for(int i=0; i<len; i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;
}

void bubble(int number[], int len)
{
    print("bubble sort before: ", number, len);

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

    print("bubble sort after: ", number, len);
}

void cocktail(int number[], int len)
{
    print("cocktail sort before: ", number, len);

    int bottom = 0, top = len-1;
    int temp;
    bool swapped = true;
    while (swapped)
    {
        swapped = false;

        // put biggest to the rightest place
        for (int i=bottom; i<top; i++)
        {
            if (number[i] > number[i+1])
            {
                temp = number[i];
                number[i] = number[i+1];
                number[i+1] = temp;
                swapped = true;
            }
        }
        top--;

        // put smallest to the leftest place
        for (int i=top; i>bottom; i--)
        {
            if (number[i] < number[i-1])
            {
                temp = number[i];
                number[i] = number[i-1];
                number[i-1] = temp;
                swapped = true;
            }
        }
        bottom++;
    }

    print("cocktail sort after: ", number, len);
}


void selection(int* number, int len)
{
}

int main()
{
    int number[12] = {95,45,15,78,84,51,24,12,56,74,11,23};
    bubble(number, 12);

    int number2[12] = {95,45,15,78,84,51,24,12,56,74,11,23};
    cocktail(number2, 12);


    return 0;
}

