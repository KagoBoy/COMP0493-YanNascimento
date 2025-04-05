#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define d 256

void RabinKarp(string text, string pattern, int q) {
    int M = pattern.size();
    int N = text.size();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == M)
                cout << "Padrão encontrado no índice " << i << endl;
        }

        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    int q = 101; // número primo
    RabinKarp(text, pattern, q);
    return 0;
}