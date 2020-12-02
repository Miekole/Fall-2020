//function getDate

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

string getDate() {

    time_t rawtime;
    struct tm* timeinfo;

    char buffer[80];
    time(&rawtime);

    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);

    std::string str(buffer);

    return str;

}



string getTime() {

    time_t rawtime;

    struct tm* timeinfo;

    char buffer[80];
    time(&rawtime);

    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), " %H:%M:%S", timeinfo);

    std::string str(buffer);

    return str;

}

int main()
{
    ifstream file;
    ofstream write_file;
    string contents;

    file.open(getDate() + ".txt");


    file.close();
    write_file.open(getDate() + ".txt", ofstream::app);
    write_file << getTime() + " access\n";
    write_file.close();


    system("pause");
    return 0;
}