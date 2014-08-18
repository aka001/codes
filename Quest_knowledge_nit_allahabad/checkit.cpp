#include <iostream>
#include <cstring>

using namespace std;


long long gcd(long long a, long long b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}


int main(void) {
    long long n, x;
    cin >> n;
    long long A[3001];
    memset(A, 0, sizeof(A));
    while(n--) {
        cin >> x;
        A[x]++;
    }
    long long ans = 0;
    for(long long i = 2; i < 3001; i++) {
        ans += A[i]*(A[i]-1)/2;
        for(long long j = i+1; j < 3001; j++) {
            if(gcd(i, j) > 1)
                ans += A[i]*A[j];
        }
    }
    cout << ans << endl;
    return 0;
}
