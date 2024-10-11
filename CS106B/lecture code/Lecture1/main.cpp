#include <iostream>
#include "console.h"
using namespace std;


int testInput() {
    int limit;
    cout << "please input what you want:";
    cin >> limit;
    return limit;
}
// The C++ compiler will look for a function
// called "main"
int main() {
    int limit = 0;
    limit = testInput();
    int result = limit * limit;
    cout << "The two of power is " <<result;
    return 0;  // must return an int to indicate
              // successful program completion
}
