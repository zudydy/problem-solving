#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();

    string s;
    int target;

    for (int i = 0; i < 3; i++) {
        cin >> s;
        if (s == "Fizz" || s == "Buzz" || s == "FizzBuzz") {
            continue;
        }
        
        target = stoi(s) + 3 - i;
    }

    if (target % 3 == 0) {
        if (target % 5 == 0) {
            cout << "FizzBuzz\n";
        } else {
            cout << "Fizz\n";
        }
    } else {
        if (target % 5 == 0) {
            cout << "Buzz\n";
        } else {
            cout << target << "\n";
        }
    }
    
    return 0;
}