#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
 
const int MAX = 100009;
const int MAXINT = 1000000000;
 
int n;
vvii G(MAX);
vi D(MAX, MAXINT);
 
void Dijkstra(int s)
{
    set<ii> Q;
    D[s] = 0;
    Q.insert(ii(0,s));
 
    while(!Q.empty())
    {
        ii top = *Q.begin();
        Q.erase(Q.begin());
        int v = top.second;
        int d = top.first;
 
        for (vii::const_iterator it = G[v].begin(); it != G[v].end(); it++)
        {
            int v2 = it->first;
            int cost = it->second;
            if (D[v2] > D[v] + cost)
            {
                if (D[v2] != 1000000000)
                {
                    Q.erase(Q.find(ii(D[v2], v2)));
                }
                D[v2] = D[v] + cost;
                Q.insert(ii(D[v2], v2));
            }
        }
    }
}
 
int main()
{
    int m, s, t = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, w = 0;
        scanf("%d %d", &a, &b);
        G[a].push_back(ii(b, 0));
        G[b].push_back(ii(a, 1));
    }
 
    Dijkstra(1);
    if(D[n]==MAXINT)
	    printf("-1\n");
    else
	    printf("%d\n", D[n]);
    return 0;
}










