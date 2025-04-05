#include <iostream>
#include <vector>
using namespace std;

// Implementação analítica (com programação dinâmica)
int binomialCoeffDP(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][k];
}

// Implementação recursiva
int binomialCoeffRec(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binomialCoeffRec(n-1, k-1) + binomialCoeffRec(n-1, k);
}

// Versão otimizada em espaço
int binomialCoeff(int n, int k) {
    vector<int> dp(k+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            dp[j] = dp[j] + dp[j-1];
        }
    }
    return dp[k];
}

int main() {
    int n = 5, k = 2;
    cout << "Coeficiente binomial DP: " << binomialCoeffDP(n, k) << endl;
    cout << "Coeficiente binomial Recursivo: " << binomialCoeffRec(n, k) << endl;
    cout << "Coeficiente binomial Otimizado: " << binomialCoeff(n, k) << endl;
    return 0;
}