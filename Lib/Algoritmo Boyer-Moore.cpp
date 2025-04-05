#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(string str, int size, vector<int>& badchar) {
    for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (int i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void BoyerMoore(string text, string pattern) {
    int m = pattern.size();
    int n = text.size();
    vector<int> badchar(NO_OF_CHARS, -1);

    badCharHeuristic(pattern, m, badchar);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            cout << "Padrão encontrado no índice " << s << endl;
            s += (s + m < n) ? m - badchar[text[s + m]] : 1;
        } else {
            s += max(1, j - badchar[text[s + j]]);
        }
    }
}

int main() {
    string text = "ABAAABCD";
    string pattern = "ABC";
    BoyerMoore(text, pattern);
    return 0;
}