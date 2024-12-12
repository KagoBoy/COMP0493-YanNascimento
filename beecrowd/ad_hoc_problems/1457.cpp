#include <iostream>
#include <string>
using namespace std;

// Função para calcular o K-fatorial de N
long long kFatorial(int N, int K) {
    long long resultado = 1;
    while (N > 0) {
        resultado *= N;  // Multiplica pelo valor atual de N
        N -= K;          // Subtrai K de N
    }
    return resultado;
}

int main() {
    int T;
    cin >> T; // Número de instâncias

    while (T--) {
        string entrada;
        cin >> entrada; // Entrada no formato "N!!!"

        // Separar N e K
        int N = 0, K = 0;
        size_t i = 0;

        // Extrai o número N antes do '!'
        while (isdigit(entrada[i])) {
            N = N * 10 + (entrada[i] - '0');
            i++;
        }

        // Conta o número de '!' para determinar K
        K = entrada.length() - i;

        // Calcula o K-fatorial e imprime o resultado
        cout << kFatorial(N, K) << endl;
    }

    return 0;
}
