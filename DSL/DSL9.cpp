#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

bool isPalindrome(const string& str) {
    stack<char> s;
    for (char ch : str) {
        s.push(ch);
    }
    for (char ch : str) {
        if (ch != s.top()) {
            return false;
        }
        s.pop();
    }
    return true;
}

bool checkPalindromeWithPreprocessing(const string& str) {
    string cleanedStr = "";
    for (char ch : str) {
        if (isalnum(ch)) {
            cleanedStr += tolower(ch);
        }
    }
    return isPalindrome(cleanedStr);
}

void printReverseUsingStack(const string& str) {
    stack<char> s;
    for (char ch : str) {
        s.push(ch);
    }
    cout << "Reversed String: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    cout << "\nChecking if the string is a palindrome...\n";
    if (checkPalindromeWithPreprocessing(input)) {
        cout << "The string is a palindrome.\n";
    } else {
        cout << "The string is not a palindrome.\n";
    }

    cout << "\nPrinting the string in reverse order:\n";
    printReverseUsingStack(input);

    return 0;
}
