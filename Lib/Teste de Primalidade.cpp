#include <iostream>
#include <cmath>
using namespace std;

// Força bruta
bool isPrimeBrute(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// Otimizado
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    int num = 17;
    cout << num << " é primo (bruto)? " << (isPrimeBrute(num) ? "Sim" : "Não") << endl;
    cout << num << " é primo (otimizado)? " << (isPrime(num) ? "Sim" : "Não") << endl;
    return 0;
}