#include <iostream>
#include <string>
using namespace std;

bool simulateDFA(string input) {
    char state = 'A';

    for (char ch : input) {

        switch (state) {
            case 'A':
                if (ch == 'a') state = 'B';
                else if (ch == 'b') state = 'C';
                else return false;
                break;

            case 'B':
                if (ch == 'a') state = 'D';
                else if (ch == 'b') state = 'F';
                else return false;
                break;

            case 'C':
                if (ch == 'a') state = 'B';
                else if (ch == 'b') state = 'F';
                else return false;
                break;

            case 'D':
                if (ch == 'a') state = 'D';
                else if (ch == 'b') state = 'F';
                else return false;
                break;

            case 'E':
                if (ch == 'a') state = 'B';
                else if (ch == 'b') state = 'F';
                else return false;
                break;

            case 'F':
                if (ch == 'a') state = 'B';
                else if (ch == 'b') state = 'F';
                else return false;
                break;
        }
    }


    return true;
}

int main() {
    string testCases[5] = {"a", "ab", "baba", "aaab", "abba"};

    for (int i = 0; i < 5; i++) {
        cout << "Input: " << testCases[i] << " -> ";
        if (simulateDFA(testCases[i]))
            cout << "Accepted" << endl;
        else
            cout << "Rejected" << endl;
    }

    return 0;
}
