#include <iostream>
using namespace std;

int main() {

    int num, i;
    bool isPrime = true;
    i:
    cout << "\nEnter a positive integer: ";
    cin >> num;
    
    // 0 and 1 are not prime numbers
    if (num <= 1) {
        cout << num << " is neither prime nor composite." << endl;
        return 0;
    }
    
    // Check if num is divisible by any number from 2 to num-1
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }
    
    if (isPrime)
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is a composite number." << endl;
        goto i;
    
    return 0;
}