#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();

    string isbn;
    cin >> isbn;

    int rest_sum = 0;
    int target_factor = 0;

    for (int i = 0; i < isbn.size(); i++) {
        int factor = i % 2 == 0 ? 1 : 3;

        if (isbn[i] == '*') {
            target_factor = factor;
            continue;
        }

        rest_sum += (isbn[i] - '0') * factor;
    }

    int digit;

    for (digit = 0; digit < 10; digit++) {
        if ((rest_sum + digit * target_factor) % 10 == 0) {
            break;
        }
    }
    
    cout << digit << "\n";

    return 0;
}