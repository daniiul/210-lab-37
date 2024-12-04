#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

int sum_ascii(string str);

int main() {
    ifstream inputFile("lab-37-data.txt");

    if(!inputFile.is_open())
    {
        cout << "File failed to open!" << endl;
        return 0;
    }

    int total_sum = 0;

    string temp;
    while(getline(inputFile, temp))
    {
        total_sum += sum_ascii(temp);
    }

    cout << "The sum ascii value of 'the database' is: " << total_sum << endl;

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
