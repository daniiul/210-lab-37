#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string str);

int main() {
    ifstream inputFile("lab-37-data.txt");

    if(!inputFile.is_open())
    {
        cout << "File failed to open!" << endl;
        return 0;
    }

    map<int, list<char>> hash_table;

    string temp;
    while(getline(inputFile, temp))
    {
        list<char> t;
        int index = gen_hash_index(temp);
        for (auto i : temp)
        {
            t.push_back(i);
        }
        hash_table[index] = t;
    }

    int ct = 0;

    for(auto i : hash_table)
    {
        cout << i.first <<  "     ";
        for (auto j : i.second)
            cout << j;
        cout << endl;
        ct++;
        if (ct == 99)
        {
            break;
        }
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
