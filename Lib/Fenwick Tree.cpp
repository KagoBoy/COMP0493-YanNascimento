#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) : n(size), tree(size + 1, 0) {}

    void update(int index, int delta) {
        while (index <= n) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    FenwickTree ft(arr.size());

    for (int i = 0; i < arr.size(); i++)
        ft.update(i + 1, arr[i]);

    cout << "Soma dos primeiros 4 elementos: " << ft.query(4) << endl;
    cout << "Soma dos elementos 2 a 5: " << ft.rangeQuery(2, 5) << endl;

    ft.update(3, 10); // Adiciona 10 ao terceiro elemento
    cout << "Nova soma dos primeiros 4 elementos: " << ft.query(4) << endl;
    return 0;
}