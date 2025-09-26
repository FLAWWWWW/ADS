#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    const int N = 10000;
    vector<bool> primesFlag(N, true);
    vector<int> primes;

    primesFlag[0] = primesFlag[1] = false;

    for (int i = 2; i * i <= N; i++){
        if(primesFlag[i]){
            for (int j = i * i; j <= N; j += i){
                primesFlag[j] = false; // данное число не является простым, так как оно делится на i
            }
        }
    }

    for(int i = 2; i <= N; i++){
        if(primesFlag[i]) primes.push_back(i);
    }

    cout << primes[primes[n - 1] - 1];

    return 0;
}
