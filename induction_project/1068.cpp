#include <bits/stdc++.h>
using namespace std;

int main() {

    string expression;
    while (getline(cin, expression)) {

        stack<char> parentheses;
        bool isCorrect = true;

        for (char ch : expression) {
            if (ch == '(') {
                parentheses.push(ch);
            } else if (ch == ')') {
                if (parentheses.empty()) {
                    isCorrect = false;
                    break;
                }
                parentheses.pop();
            }
        }
        
        if (!parentheses.empty()) {
            isCorrect = false;
        }

        cout << (isCorrect ? "correct" : "incorrect") << endl;
    }

    return 0;
}