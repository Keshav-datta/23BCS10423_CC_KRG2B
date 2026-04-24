#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> tree;
    int n;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node+1, start, mid);
            build(arr, 2*node+2, mid+1, end);
            tree[node] = tree[2*node+1] + tree[2*node+2];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; 
        if (l <= start && end <= r) return tree[node]; 

        int mid = (start + end) / 2;
        int leftSum = query(2*node+1, start, mid, l, r);
        int rightSum = query(2*node+2, mid+1, end, l, r);
        return leftSum + rightSum;
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2*node+1, start, mid, idx, val);
            else
                update(2*node+2, mid+1, end, idx, val);

            tree[node] = tree[2*node+1] + tree[2*node+2];
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree st(arr);

    int l, r;
    cin >> l >> r;
    cout << "Range Sum: " << st.query(0, 0, n-1, l, r) << endl;

    int idx, val;
    cin >> idx >> val;
    st.update(0, 0, n-1, idx, val);

    cout << "After Update Range Sum: "
         << st.query(0, 0, n-1, l, r) << endl;

    return 0;
}
