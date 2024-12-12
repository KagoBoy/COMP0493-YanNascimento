#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int N;
    while(cin >> N){
        vector<string> telefones(N);
        for(int i = 0; i < N; i++){
            cin >> telefones[i];
        }
        sort(telefones.begin(), telefones.end());
        int e = 0;
        for (int i = 1; i < N; i++){
            int j = 0;
            while (j < telefones[i].size() && telefones[i][j] == telefones[i-1][j]){
                j++;
            }
            e += j;
        }
        
        cout << e << endl;
    }
 
    return 0;
}