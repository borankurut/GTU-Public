#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string correctBlank(const string& str);

string correctUpperCase(const string& str);

int main(int argc, char *argv[]){
    string str;

    char c;
    
    int ix; 
    for(ix = 0; ix < 100 && c != '.'; ++ix){
        cin.get(c);
        str += c;
    }

    cout << correctBlank(correctUpperCase(str));

    return(0);
}

string correctBlank(const string& str){
    string corrected;
    corrected += str[0];

    int ix;
    for(ix = 1; ix < str.length(); ++ix)
        if(str[ix] != ' ' || corrected[corrected.length() - 1] != ' '){
            if(str[ix] != '\n')
                corrected += str[ix];
            else if(corrected[corrected.length() - 1] != ' ') //\n\n\n
                corrected += ' ';

        }

    return(corrected);
}

string correctUpperCase(const string& str){
    string corrected(str);
    corrected[0] = static_cast<char>(toupper(corrected[0]));
    int ix;
    for(ix = 1; ix < corrected.length(); ++ix)
        corrected[ix] = tolower(corrected[ix]);

    return(corrected);
}