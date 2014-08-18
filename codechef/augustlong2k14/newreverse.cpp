#include<stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#define si(n) scanf("%d",&n)
using namespace std;

typedef vector<vector<pair<int,float> > > Graph;
class Comparator
{
	public:
		int operator() ( const pair<int,float>& p1, const pair<int,float> &p2)
		{
			return p1.second>p2.second;
		}
};

void dijkstra(const Graph  &G,const int &source,const int &destination,vector<int> &path)
{
	vector<float> d(G.size());
	vector<int> parent(G.size());
	for(unsigned int i = 0 ;i < G.size(); i++)
	{
		d[i] = std::numeric_limits<float>::max();
		parent[i] = -1;
	}
	priority_queue<pair<int,float>, vector<pair<int,float> >, Comparator> Q;
	d[source] = 0.0f;
	Q.push(make_pair(source,d[source]));
	while(!Q.empty())
	{
		int u = Q.top().first;
		if(u==destination) break;
		Q.pop();
		for(unsigned int i=0; i < G[u].size(); i++)
		{
			int v= G[u][i].first;
			float w = G[u][i].second;
			if(d[v] > d[u]+w)
			{
				d[v] = d[u]+w;
				parent[v] = u;
				Q.push(make_pair(v,d[v]));
			}
		}
	}
	path.clear();
	int p = destination;
	path.push_back(destination);
	while(p!=source)
	{
		p = parent[p];
		path.push_back(p);
	}
}

int main()
{
	/* Graph
	   GRAPH TYPE = UNDIRECTED
	   NUMBER OF VERTICES = 6 indexed from 0 to 5
	   NUMBER OF EDGES = 9
	   edge 0->1 weight = 7
	   edge 0->2 weight = 9
	   edge 0->5 weight = 14
	   edge 1->2 weight = 10
	   edge 1->3 weight = 15
	   edge 2->5 weight = 2
	   edge 2->3 weight = 11
	   edge 3->4 weight = 6
	   edge 4->5 weight = 9
	   */
	int n,m,i,x,y;
	si(n);
	si(m);
	Graph g;
	g.resize(n);
	for(i=0;i<m;i++)
	{
		si(x);
		si(y);
		g[x].push_back(make_pair(0,y));
		g[y].push_back(make_pair(1,x));
	}
	vector<int> path;
	dijkstra(g,1,n,path);
	for(int i=path.size()-1;i>=0;i--)
		cout<<path[i]<<"->";
	return 0;
}
