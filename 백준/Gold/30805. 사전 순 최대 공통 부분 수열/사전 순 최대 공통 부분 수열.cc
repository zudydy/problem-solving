#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Data {
    int value;
    int index;

    bool operator < (const Data& other) const {
        if (value == other.value) {
            return index < other.index;
        }
        return value > other.value;
    }
};

void find_common_sequence(vector<int>& common_sequence, const vector<int>& a, const vector<int>& b) {
    vector<Data> array(a.size());
    for (int i = 0; i < a.size(); i++) {
        array[i] = {a[i], i};
    }
    sort(array.begin(), array.end());

    int ai = -1, bi = -1;
    for (auto data : array) {
        bool is_find = false;

        for (int i = 0; i < b.size(); i++) {
            if (data.value == b[i]) {
                is_find = true;
                ai = data.index;
                bi = i;
                break;
            }
        }

        if (is_find) {
            break;
        }
    }

    if (ai == -1) {
        return;
    }

    common_sequence.push_back(b[bi]);
    find_common_sequence(common_sequence, vector<int>(a.begin() + ai + 1, a.end()), vector<int>(b.begin() + bi + 1, b.end()));
}

int main() {
    FASTIO();

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> common_sequence;
    find_common_sequence(common_sequence, a, b);

    cout << common_sequence.size() << "\n";
    for (auto c : common_sequence) {
        cout << c << " ";
    }
    cout << "\n";

    return 0;
}