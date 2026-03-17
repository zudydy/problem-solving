#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int N, T, P, total_t = 0;
    int size[6] = {0};

    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> size[i];
    }
    cin >> T >> P;
    
    for (int i = 0; i < 6; i++) {
        total_t += (size[i] / T + (size[i] % T > 0 ? 1 : 0));
    }

    cout << total_t << "\n";
    cout << N / P << " " << N % P << "\n";
    
    return 0;
}