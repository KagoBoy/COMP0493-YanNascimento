#include <iostream>
using namespace std;

// Usando o algoritmo estendido de Euclides
int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

int main() {
    int a = 3, m = 11;
    int inv = modInverse(a, m);
    cout << "Inverso modular de " << a << " modulo " << m << " é " << inv << endl;
    cout << "Verificação: " << (a * inv) % m << " ≡ 1 mod " << m << endl;
    return 0;
}