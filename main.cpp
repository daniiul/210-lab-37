#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_has_index(string str);

int main() {
    ifstream inputFile("lab-37-data.txt");

    if(!inputFile.is_open())
    {
        cout << "File failed to open!" << endl;
        return 0;
    }

    map<int, list<string>> hash_table;

    string temp;
    while(getline(inputFile, temp))
    {
        int index = gen_hash_index(temp);
        t
    }



    return 0;
}

int gen_hash_index(string str)
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
