#include <iostream>
#include <set>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    
    int n;
    cin >> n;

    vector<int> fruits(n);
    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    set<int> s;
    int current_window_index = 0, next_window_index = 0;
    int max_length = 0;
    for (int i = 0; i < n; i++) {        
        if (s.size() == 0) {
            s.insert(fruits[i]);
            continue;
        }

        if (s.size() == 1) {
            s.insert(fruits[i]);
            next_window_index = i;
            continue;
        }

        if (s.find(fruits[i]) != s.end()) {
            if (fruits[i] != fruits[i - 1]) {
                next_window_index = i;
            }

            continue;
        }

        max_length = max(max_length, i - current_window_index);
        current_window_index = next_window_index;
        next_window_index = i;
        s = { fruits[current_window_index], fruits[i] };
    }

    max_length = max(max_length, n - current_window_index);

    cout << max_length << "\n";

    return 0;
}
