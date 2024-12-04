#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int sum_ascii(string str);

int main() {
    int as = sum_ascii("536B9DFC93AF");
    cout << "The ascii value of '536B9DFC93AF' is: " << as << endl;

    return 0;
}

int sum_ascii(string str)
{
    int sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        sum += (int) str[i];
    }
    return sum;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
