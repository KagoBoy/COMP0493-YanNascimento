#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findCard(vector<int> princess, vector<int> prince) {
    vector<bool> used(53, false);

    for (int card : princess) used[card] = true;
    for (int card : prince) used[card] = true;

    sort(princess.begin(), princess.end());
    sort(prince.begin(), prince.end());

    for (int i = 1; i <= 52; ++i) {
        if (used[i]) continue; 

        vector<int> new_prince = prince;
        new_prince.push_back(i);
        sort(new_prince.begin(), new_prince.end());

        bool prince_wins = true;
        do {
            int wins = 0;
            for (int j = 0; j < 3; ++j) {
                if (new_prince[j] > princess[j]) ++wins;
            }
            if (wins < 2) { 
                prince_wins = false;
                break;
            }
        } while (next_permutation(new_prince.begin(), new_prince.end()));

        if (prince_wins) return i; 
    }

    return -1; 
}

int main() {
    while (true) {
        vector<int> princess(3), prince(2);

        for (int i = 0; i < 3; ++i) cin >> princess[i];
        for (int i = 0; i < 2; ++i) cin >> prince[i];

        if (princess[0] == 0 && princess[1] == 0 && princess[2] == 0 && prince[0] == 0 && prince[1] == 0) break;

        cout << findCard(princess, prince) << endl;
    }
    return 0;
}
