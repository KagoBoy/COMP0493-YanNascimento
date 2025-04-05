#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + 
               query(2 * node + 1, mid + 1, end, l, r);
    }

    void rangeUpdate(int node, int start, int end, int l, int r, int val) {
        if (start > end || start > r || end < l)
            return;
        if (start == end) {
            tree[node] += val;
            return;
        }
        int mid = (start + end) / 2;
        rangeUpdate(2 * node, start, mid, l, r, val);
        rangeUpdate(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void rangeUpdate(int l, int r, int val) {
        rangeUpdate(1, 0, n - 1, l, r, val);
    }
};

class SegmentTreeMinMax {
    vector<int> minTree, maxTree;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            minTree[node] = maxTree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            minTree[node] = min(minTree[2 * node], minTree[2 * node + 1]);
            maxTree[node] = max(maxTree[2 * node], maxTree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            minTree[node] = maxTree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, end, idx, val);
            minTree[node] = min(minTree[2 * node], minTree[2 * node + 1]);
            maxTree[node] = max(maxTree[2 * node], maxTree[2 * node + 1]);
        }
    }

    pair<int, int> query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return {INT_MAX, INT_MIN};
        if (l <= start && end <= r)
            return {minTree[node], maxTree[node]};
        int mid = (start + end) / 2;
        auto left = query(2 * node, start, mid, l, r);
        auto right = query(2 * node + 1, mid + 1, end, l, r);
        return {min(left.first, right.first), max(left.second, right.second)};
    }

public:
    SegmentTreeMinMax(const vector<int>& arr) {
        n = arr.size();
        minTree.resize(4 * n);
        maxTree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    pair<int, int> query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);
    SegmentTreeMinMax stmm(arr);

    cout << "Soma do intervalo [1, 4]: " << st.query(1, 4) << endl;
    st.update(2, 10);
    cout << "Nova soma do intervalo [1, 4]: " << st.query(1, 4) << endl;

    auto mm = stmm.query(1, 4);
    cout << "Mínimo no intervalo [1, 4]: " << mm.first << endl;
    cout << "Máximo no intervalo [1, 4]: " << mm.second << endl;
    return 0;
}