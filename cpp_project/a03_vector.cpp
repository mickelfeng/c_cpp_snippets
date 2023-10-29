#include <bits/stdc++.h>

void sort();

void init();

using namespace std;

int main() {
    init();
    // sort();
    return 0;
}

void init() {
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(3);
    vi.push_back(0);
    sort(vi.begin(), vi.end()); /// /小到大

    for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++) { cout << *it << " "; }

    cout << "\nSorted \n";
    for (auto x: vi)
        cout << x << " ";
    reverse(vi.begin(), vi.end()); /// 从大道小
    cout << "\nRev Sorted \n";
    for (auto x: vi)
        cout << x << " ";

}

void sort() {
    vector<int> v{1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    sort(v.begin(), v.end());
    cout << "Sorted \n";
    for (auto x: v)
        cout << x << " ";
}
