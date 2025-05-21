#include <iostream>
#include <conio.h>
using namespace std;

int main(){

    int n;
i:
    cout << "Enter a no. : " << endl;
    cin >> n;

    if (n < 1 || n == 1) {
        cout << "Not prime." << endl;
    }
    else if (n > 1) {
        bool isPrime = true; // assume it's prime

        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                cout << "Not prime." << endl;
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << "A prime no." << endl;
        }
    }

    goto i;
    return 0;
}
