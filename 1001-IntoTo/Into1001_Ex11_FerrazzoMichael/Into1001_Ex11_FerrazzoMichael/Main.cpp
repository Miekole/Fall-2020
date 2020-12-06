#include <iostream>
#include <time.h>

using namespace std;
int main()
{
    char line[150];
    int vowels, consonants, digits, spaces;
    vowels = 0;
    consonants = 0;
    digits = 0;
    spaces = 0;

    cout << "Enter a string: ";
    cin.getline(line, 150);

    for (int i = 0; line[i] != '\0'; ++i)
    {
        if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' ||
            line[i] == 'o' || line[i] == 'u' || line[i] == 'A' ||
            line[i] == 'E' || line[i] == 'I' || line[i] == 'O' ||
            line[i] == 'U')
        {
            ++vowels;
        }
        else if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
        {
            ++consonants;
        }
    }

    cout << endl;

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;

    cout << "To Upper: ";
    for (int i = 0; line[i] != '\0'; ++i)
    {
       putchar (toupper(line[i]));
    }
    cout << endl;
    cout << "To Lower: ";
    for (int i = 0; line[i] != '\0'; ++i)
    {
        putchar(tolower(line[i]));
    }

    cout << endl;
    cout << endl;
    cout << "press enter to finish";
    cin.get();
    return 0;
}