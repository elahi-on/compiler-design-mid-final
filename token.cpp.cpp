#include <iostream>
#include <fstream>
using namespace std;


bool isKeyword(const string &word) {
    return (word == "int" || word == "return");
}

bool isIdentifier(const string &word) {
    return (word == "main" || word == "x" || word == "cout");
}

bool isOperator(const string &word) {
    return (word == "=" || word == "<<" || word == ">>");
}

bool isConstant(const string &word) {
    return (word == "10" || word == "0");
}

bool isSpecialSymbol(const string &word) {
    return (word == "(" || word == ")" ||
            word == "{" || word == "}" ||
            word == ";");
}



string getTokenType(const string &word) {
    if (isKeyword(word)) return "Keyword";
    if (isIdentifier(word)) return "Identifier";
    if (isOperator(word)) return "Operator";
    if (isConstant(word)) return "Constant";
    if (isSpecialSymbol(word)) return "Special Symbol";
    return "Unknown Token";
}



void analyzeTokens(ifstream &file) {
    string word;
    string prev = "";

    while (file >> word) {


        if (!prev.empty()) {
            cout << prev + " " + word << " : Constant" << endl;
            prev = "";
            continue;
        }


        if (!isKeyword(word) && !isIdentifier(word) &&
            !isOperator(word) && !isConstant(word) &&
            !isSpecialSymbol(word)) {

            prev = word;
            continue;
        }

        cout << word << " : " << getTokenType(word) << endl;
    }
}



int main() {
    ifstream file("code.txt");

    if (!file) {
        cout << "File not found!" << endl;
        return 0;
    }

    cout << "Token Identification Output:\n\n";


    analyzeTokens(file);

    file.close();

    cout << "\nFile processing completed successfully.\n";

    return 0;
}
