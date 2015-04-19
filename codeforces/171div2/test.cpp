#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <set>
#include <map>
#include <stack>
#include <fstream>
#include <deque>
#include <list>
#include <ctime>
#include <cassert>
#include <bitset>

#define SZ(a) (int(a.size()))
#define MEM(a, val) memset(a, val, sizeof(a))
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)
#define ALL(a) a.begin(), a.end()
#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define SQR(a) ((a) * (a))

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double dbl;
typedef pair<int, int> pii ;
typedef vector<int> vint;
typedef vector<LL> vLL;

const int nmax = 100009;

int F1[nmax], F2[nmax];
int a[nmax];

void update(int F[nmax], int i, int val) {
    for (; i < nmax; i = 2 * i - (i & (i - 1)))
        F[i] += val;
}

int get(int F[nmax], int i) {
    int ans = 0;
    for (; i > 0; i = i & (i - 1))
        ans += F[i];
    return ans;
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    REP(i, n) {
        scanf("%d", &a[i]);
        if (i > 0 && a[i] > a[i - 1])
            update(F1, i, 1);
        if (i > 0 && a[i] < a[i - 1])
            update(F2, i, 1);
    }
    REP(step, m) {
        int L, R;
        scanf("%d %d", &L, &R);
        --L;
        --R;
        int l = L, r = R + 1;
        while (l < r -1) {
            int mid = (l + r) / 2;
            if (get(F2, mid) - get(F2, L) == 0)
                l = mid;
            else
                r = mid;
        }
        if (get(F1, R) - get(F1, l) == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
