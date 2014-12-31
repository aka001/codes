#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
using namespace std;
string S1,S2;
vector<char> S3;
map<int , vector<vector<char> > > X;
map<vector<char> , int > Y;
string s1,s2;
int n,size=99999;
bool ok(){
	//map<char,int> YES;
	int i=0,j=0;
	for(;i<S3.size() && j<s1.length();i++)
		if(S3[i]==s1[j]){j++;}
	if(j<s1.length()) return false;
	i=0,j=0;
	for(;i<S3.size() && j<s2.length();i++)
		if(S3[i]==s2[j]){j++;}
	if(j<s2.length()) return false;
	return true;
}
void backtrack(int i,int j)
{
	//cout<<i<<" "<<j<<endl;
	if(!Y[S3] && ok()){/*for(int i=0;i<S3.size();i++) cout<<S3[i]; cout<<endl;*/ Y[S3]=1;if(S3.size()<=size){ X[S3.size()].push_back(S3); size=S3.size(); }return;}
	if(( i>=S1.length() && j>=S2.length())|| Y[S3]) return;
	//for(int i=0;i<S3.size();i++) cout<<S3[i]; cout<<endl;

	if(i<S1.length() ) {S3.push_back(S1[i]); backtrack(i+1,j); S3.pop_back(); }
	if(j<S2.length() ) {S3.push_back(S2[j]); backtrack(i,j+1); S3.pop_back(); }
	if(i<S1.length() &&  j<S2.length() && S1[i] == S2[j]) { S3.push_back(S2[j]); backtrack(i+1,j+1); S3.pop_back();}
	if(i>=S1.length() && j<S2.length() ){S3.push_back(S2[j]);backtrack(i,j+1); S3.pop_back();}
	if(j>=S2.length() && i<S1.length()){S3.push_back(S1[i]);backtrack(i+1,j); S3.pop_back(); }
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		X.clear();
		S3.clear();
		Y.clear();
		cin>>s1>>s2;
		S1=s1,S2=s2;
		//sort(S1.begin(),S1.end());
		//sort(S2.begin(),S2.end());
		int N;
		cin>>N;
		n=N;
		size=99999;
		backtrack(0,0);
		//cout<<N<<endl;
		if(X[size][N-1].size()==size){
			//for(int j=0;j<X[size].size();j++,cout<<endl)
			for(int i=0;i<X[size][N-1].size();i++)
				cout<<(X[size][N-1][i]);
			//cout<<endl;
		}
		else
			cout<<"NO ANSWER";
		cout<<endl;
	}
	return 0;
}
