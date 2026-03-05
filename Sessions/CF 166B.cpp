#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Point {
    ll x, y;
};

ll cross(Point a, Point b, Point c) {
    ll x1 = b.x - a.x;
    ll y1 = b.y - a.y;
    ll x2 = c.x - a.x;
    ll y2 = c.y - a.y;
    return x1 * y2 - y1 * x2;
}

bool insideConvex(vector<Point>& poly, Point p) {
    int n = poly.size();

    if (cross(poly[0], poly[1], p) <= 0) return false;
    if (cross(poly[0], poly[n-1], p) >= 0) return false;

    int l = 1, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (cross(poly[0], poly[mid], p) > 0) l = mid;
        else r = mid;
    }

    return cross(poly[l], poly[l+1], p) > 0;
}

int main() {
    int n;
    cin >> n;

    vector<Point> polygon(n);
    for (auto &p : polygon) cin >> p.x >> p.y;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        Point p;
        cin >> p.x >> p.y;

        if (!insideConvex(polygon, p)) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}
