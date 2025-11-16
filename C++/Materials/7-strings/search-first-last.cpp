#include <iostream>

using namespace std;

int getLengthOfFirstWord(const char *str)
{
    int spaceInd = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            spaceInd = i;
            break;
        }
    }
    return spaceInd;
}

int getLengthOfLastWord(const char *str)
{
    int spaceInd = 0;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            spaceInd = i;
            break;
        }
    }
    return strlen(str) - spaceInd - 1;
}

int main()
{
    const int n = 20;
    char* userStr = new char[n];

    cout << "Input string: ";
    fgets(userStr, n, stdin);

    if (getLengthOfFirstWord(userStr) == 0)
    {
        cout << "There is no space symbol in your string!\n";
    }
    else
    {
        if (getLengthOfFirstWord(userStr) > getLengthOfLastWord(userStr))
        {
            cout << "The length of the 1st word is longer" << endl;
        }
        else if (getLengthOfFirstWord(userStr) < getLengthOfLastWord(userStr))
        {
            cout << "The length of the last word is longer" << endl;
        }
        else
        {
            cout << "The 1st and last words are the same length" << endl;
        }
    }
    delete[] userStr;
    return 0;
}