// Assignment By Akhlas Hashmi - Compiler Construction
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// check if input is matches any keyword
bool is_Keyword(string String)
{
    string line;
    ifstream input("keywords.txt");
    while (getline(input, line))
    {
        if (String == line)
        {
            return true;
            break;
        }
    }
    return false;
}

// check if input is an identifier
bool is_Identifier(string String)
{
    bool check;
    if ((String[0] >= 'a' && String[0] <= 'z') || (String[0] >= 'A' && String[0] <= 'Z') || (String[0] == '_'))
    {
        for (int i = 1; i < String.length(); i++)
        {
            if (((String[i] >= 'a' && String[i] <= 'z') || (String[i] >= 'A' && String[i] <= 'Z') ||
                 (String[i] >= '0' && String[i] <= '9') || (String[i] == '_')))
                check = true;
            else
            {
                check = false;
                break;
            }
        }
        return check;
    }
    else
        return false;
}

// check if input is an operator
bool is_Operator(string String)
{
    string ln;
    ifstream input("operators.txt");
    while (getline(input, ln))
    {
        if (String == ln)
        {
            return true;
            break;
        }
    }
    return false;
}

// check if input is a float
bool is_Float(string String)
{
    int countDP = 0; // count decimal point

    if (String.length() == 0)
        return (false);
    for (int i = 0; i < String.length(); i++)
    {
        if (String[i] != '0' && String[i] != '1' && String[i] != '2' && String[i] != '3' && String[i] != '4' &&
            String[i] != '5' && String[i] != '6' && String[i] != '7' && String[i] != '8' && String[i] != '9' &&
            String[i] != '.')
            return (false);
        if (String[i] == '.')
            countDP++;
    }
    if (countDP == 1)
        return true;
    else
        return false;
}

// check if input is an integer
bool is_Integer(string String)
{
    for (int i = 0; i < String.length(); i++)
    {
        if (String[i] != '0' && String[i] != '1' && String[i] != '2' && String[i] != '3' && String[i] != '4' &&
            String[i] != '5' && String[i] != '6' && String[i] != '7' && String[i] != '8' && String[i] != '9')
            return (false);
    }
    return (true);
}

// check if input is comment
bool is_Comment(string String)
{
    if (String[0] == String[1] && String[1] == '/')
        return true;
    else if (String[0] == '/' && String[1] == '*' && String.substr(String.length() - 2) == "*/")
        return true;
    else
        return false;
}

// check if input is a separater
bool is_Separator(string String)
{
    if (String == ";" || String == "," || String == "(" || String == ")" || String == "{" || String == "}" ||
        String == "()" || String == "{}")
        return true;
    else
        return false;
}

// writes results to the file
void output(string String)
{
    ofstream out("output.txt");
    out << String;
    out.close();
}

int main()
{
    string String;

    ifstream input("input.txt");
    getline(input, String);
    cout << "Input is " << String << endl;

    if (!(is_Keyword(String)))
    {
        if (is_Identifier(String))
            output("Valid Identifier Detected");
        else if (is_Operator(String))
            output("Operator Detected");
        else if (is_Float(String))
            output("Float Number Detected");
        else if (is_Integer(String))
            output("Integer Number Detected");
        else if (is_Comment(String))
            output("Comment detected");
        else if (is_Separator(String))
            output("Separater detected");
        else
            output("Random String Detected");
    }
    else
        output("keyword Detected");
}
