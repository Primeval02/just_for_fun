#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;


// Prime function checking all divisors of every factor up to n
void all_divisors(long long n, vector<int>& primes) {
    long long limit = n;
    /*if (limit > 1e7) {
        cout << "Error: too many loop iterations for going through every divisor" << endl;
        return;
    }*/
    for (long long i = 2; i <= limit; i++) {
        while (n % i == 0) {
            n /= i;
            primes.push_back(i);
        }
    }
}

// Prime function checking divisors of any factor only up to sqrt(n)
void sqrt_opt(long long n, vector<int>& primes) {
    for (long long i = 2; i <= n / i; i++) {
        while (n % i == 0) {
            n /= i;
            primes.push_back(i);
        }
    }
    if (n > 1) {
        primes.push_back(n);
    }
}

void print_result (vector<int>& primes){
    // Print primes list
    for (int i = 0; i < (int)primes.size(); i++) {
        if (i > 0)
            cout << " x ";
        cout << primes[i];
    }
    cout << endl;

    // Print exponent form
    for (int i = 0; i < (int)primes.size(); i++) {
        int count = 1;
        while (i + 1 < (int)primes.size() && primes[i] == primes[i + 1]) {
            count++;
            i++;
        }

        cout << primes[i];

        if (count > 1)
            cout << "^" << count;

        if (i + 1 < (int)primes.size())
            cout << " x ";
    }
    cout << endl;

}

int main() {

    long long n;
    vector<int> primes;

    cout << "Enter a number to find the prime factorization of: ";
    cin >> n;
    
    // Prime loop checking all divisors up to n
    cout << "Checking all divisors up to " << n << ". O(n):" << endl; 
    primes.clear();
    auto start1 = chrono::high_resolution_clock::now();
    all_divisors(n, primes);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> time1 = end1 - start1;
    print_result(primes);
    cout << "Time Taken Checking Every Divisor Up To " << n << ": " << time1.count() << " seconds or "<< time1.count() * 1000000 <<" microseconds." << endl << endl;


    // Prime loop checking divisors up to sqrt(n)
    cout << "Checking divisors up to sqrt(" << n << "). O(sqrt(n)):" << endl; 
    primes.clear();
    auto start2 = chrono::high_resolution_clock::now();
    sqrt_opt(n, primes);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time2 = end2 - start2;
    print_result(primes);


    cout << "Time Taken Checking Divisors Up To " << floor(sqrt(n)) << ": " << time2.count() << " seconds or "<< time2.count() * 1000000 <<" microseconds." << endl;

    return 0;
}
