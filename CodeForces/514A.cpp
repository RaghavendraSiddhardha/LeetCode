#include <iostream>
#include <string>
using namespace std;

int main() {
    string x;
    cin >> x;

    for (int i = 0; i < x.length(); ++i) {
        if (x[i] - '0' >= 5) {
            if (!(i == 0 && x[i] == '9')) {
                x[i] = '9' - x[i] + '0';
            }
        }
    }

    cout << x;

    return 0;
}
