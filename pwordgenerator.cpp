#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;
// selectArray is a utility functiojn that is used to randomly generate an integer in the range 1 to 4 (inclusively)
int selectArray()
{
    srand(time(NULL));
    int i = rand() % 5;
    if (i == 0)
        i++;
    return i;
};
// getKey is another utility function that is used to randomly generate an integer in the range 0 to 25
int getKey()
{
    srand(time(NULL));
    int key = rand() % 26;
    return key;
};

void generate_password(int length)
{
    // initializing result string password as null
    string password = "";

    // strings whose characters will be used to build a password
    string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string s_symbol = "!@#$%^&*";
    string number = "0123456789";

    // initialize local variables
    int key, count_alphabet = 0, count_ALPHABET = 0, count_number = 0, count_s_symbol = 0;

    // Count will store length of the password being created, will initially be 0
    int count = 0;
    while (count < length)
    {
        // selectArray will return a number 1 to 4 and will use to select one of the above-defined strings
        // 1 for alphabet, 2 for ALPHABET, 3 for number, 4 for symbol
        int k = selectArray();

        // first character is always letter, capitalized or not, the condition will be covered by the code
        if (count == 0)
        {
            k = k % 3;
            if (k == 0)
                k++;
        };
    switch (k)
        {
        // if the following conditions check the minimum requirements of the alphabet
        // character has been fulfilled or not in case it has and meets the requirements of others, characters
        // that are left will break
        case 1:
            if ((count_alphabet == 2) && (count_number == 0 || count_ALPHABET == 0 || count_ALPHABET == 1 || count_s_symbol == 0))
                break;
            key = getKey();
            password = password + alphabet[key];
            count++;
            break;

        case 2:
            if ((count_ALPHABET == 2) && (count_number == 0 || count_alphabet == 0 || count_alphabet == 1 || count_s_symbol == 0))
                break;
            key = getKey();
            password = password + ALPHABET[key];
            count_ALPHABET++;
            count++;
            break;

        case 3:
            if ((count_number == 1) && (count_alphabet == 0 || count_alphabet == 1 || count_ALPHABET == 1 || count_ALPHABET == 0 || count_s_symbol == 0))
                break;
            key = getKey();
            key = key % 10;
            password = password + number[key];
            count_number++;
            count++;
            break;

        case 4:
            if ((count_s_symbol == 1) && (count_alphabet == 0 || count_alphabet == 1 || count_ALPHABET == 0 || count_ALPHABET == 1 || count_number == 0))
                break;
            key = getKey();
            key = key % 6;
            password = password + s_symbol[key];
            count_s_symbol++;
            count++;
            break;
        };
        cout << "\n-----------------------\n";
        cout << "      Password     \n";
        cout << "\n-----------------------\n";
        cout << " " << password;
        cout << "\n\n Press any key to continue\n";
        getchar();
    };
};

int main()
{
    int opt, length;
    // menu
    do
    {
        cout << "\n-------------------------------\n";
        cout << " My Password Generator\n";
        cout << "--------------------------------\n\n";
        cout << "   1. Generate Password"
             << "\n";
        cout << "   2. Exit"
             << "\n\n";
        cout << "Press key 1 to Generate a password and key 2 to exit: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Enter length: ";
            cin >> length;
            // if length < 7, the program should show an error

            if (length < 7)
            {
                cout << "\nError: Minimum length of password should be 7\n";
                cout << "Press any key to try again \n";
                getchar();
            }
            // if password is longer than 100 characters
            else if (length > 100)
            {
                cout << "\nError: Maximum length of password should be 100\n";
                cout << "Press any key to try again \n";
                getchar();
            }
            // otherwise call generate_password() function to generate a password
            else
                generate_password(length);
            break;

        default:
            // if it's both invalid it will show an error
            if (opt != 2)
            {
                cout << "\n Invalid Choice \n";
                cout << "Please press 1 to generate password and 2 to exit\n";
                cout << "Press any key to try again \n";
                getchar();
            };
            break;
        };
    }
    while (opt != 2);

    return 0;
};
