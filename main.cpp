#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string str);
int menu();

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

    int in = menu();

    while(in != 6)
    {
        if(in == 1)
        {
            int ct = 0;
            for(auto i : hash_table)
            {
                cout <<"       " i.first <<  "     ";
                for (auto j : i.second)
                    cout << j;
                cout << endl;
                ct++;
                if (ct == 99)
                    break;
            }
        }
        else if (in == 2)
        {
            string key;
            cout << "       Which key would you like to find: ";
            cin >> key;
            auto it = hash_table.find(key);
            if (it != hash_table.end())
            {
                cout <<"       " it.first <<  "     ";
                for (auto j : it.second)
                    cout << j;
                cout << endl;
            }
            else
                cout <<"        " << key << " was not found" << endl;
        }
        else if (in == 3)
        {
            string code;
            cout << "       What code would you like to add: ";
            cin >> code;
            list<char> t;
            int index = gen_hash_index(code);
            for (auto i : code)
            {
                t.push_back(i);
            }
            hash_table[index] = t;

        }
        else if (in == 4)
        {
            string key;
            cout << "       Which key would you like to delete: ";
            cin >> key;
            auto it = hash_table.find(key);
            if (it != hash_table.end())
            {
                hash_table.erase(key);
                cout << endl;
            }
            else
                cout <<"        " << key << " was not found" << endl;
        }
        else if (in == 5)
        {
            string key;
            cout << "       Which key would you like to modify: ";
            cin >> key;
            auto it = hash_table.find(key);
            if (it != hash_table.end())
            {
                string data;
                cout << "      What would you like to put in this key: ";
                list<char> newlist;
                for (auto i : data)
                {
                    newlist.push_back(i);
                }

                hash_table[key] = data;
            }
            else
                cout <<"        " << key << " was not found" << endl;
        }

        in = menu();
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

int menu()
{
    int entry;
    cout << "Welcome!" << endl;
    cout << "   [1] Print First 100 Entries" << endl;
    cout << "   [2] Search for a key" << endl;
    cout << "   [3] Add a key" << endl;
    cout << "   [4] Remove a key" << endl;
    cout << "   [5] Modify a key" << endl;'
    cout << "   [6] Exit" << endl;

    do{
        cout << "Enter: ";
        cin >> entry;
    } while(entry < 0 || entry > 6);

    return entry;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
