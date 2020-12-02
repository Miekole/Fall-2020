/*
    Michael Ferrazzo - 101321516
        Oct 17, 2020
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream file;
    string line;

    file.open("test.txt");

    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "File does not exist" << endl;
    }

    file.close();
    system("pause");
    return 0;
}