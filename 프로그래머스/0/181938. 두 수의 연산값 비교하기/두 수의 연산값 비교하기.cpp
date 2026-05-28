#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int c = stoi(to_string(a) + to_string(b));
    
    return max(c, 2 * a * b);    
}