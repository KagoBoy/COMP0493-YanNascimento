#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main() {
    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break; 

        vector<string> desenho(N);

        for (int i = 0; i < N; i++) {
            cin >> desenho[i];
        }
        int A, B;
        cin >> A >> B;

        int factorRow = A / N;
        int factorCol = B / M;

        for (int i = 0; i < N; i++) {
            for (int repeatRow = 0; repeatRow < factorRow; repeatRow++) {
                for (int j = 0; j < M; j++) {
                    for (int repeatCol = 0; repeatCol < factorCol; repeatCol++) {
                        cout << desenho[i][j];
                    }
                }
                cout << endl;
            }
        }

        cout << endl; 
    }
        
    return 0;
}