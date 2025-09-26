#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    const int N = 1000000;
    vector<bool> primesFlag(N, true);
    vector<int> primes;

    primesFlag[0] = primesFlag[1] = false;

    for (int i = 2; i * i <= N; i++){
        if(primesFlag[i]){
            for (int j = i * i; j <= N; j += i){
                primesFlag[j] = false;
            }
        }
    }

    if(primesFlag[n]) cout << "YES";
    else cout << "NO";

    return 0;
}
