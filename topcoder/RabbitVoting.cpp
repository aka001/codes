#include<bits/stdc++.h>
using namespace std;
class RabbitVoting {
	public:
	string getWinner(vector <string> names, vector <string> votes) 
	{
		int sz,i,j,str,cnt=0,mit;
		int arr[100];
		for(i=0;i<100;i++)
			arr[i]=0;
		sz=names.size();
		for(i=0;i<sz;i++)
		{
			if(votes[i]==names[i])
				continue;
			for(j=0;j<sz;j++)
			{
				if(votes[i]==names[j])
				{
					arr[j]++;
					break;
				}
			}
		}
		mit=0;
		for(i=0;i<sz;i++)
		{
			if(arr[i]>mit)
				mit=arr[i];
		}
		for(i=0;i<sz;i++)
		{
			if(arr[i]==mit)
			{
				cnt++;
				str=i;
			}
		}
		if(cnt>1)
			return "";
		else
			return names[str];
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing RabbitVoting (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1431544709;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RabbitVoting _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string names[] = { "Alice", "Bill", "Carol", "Dick" };
				string votes[] = { "Bill", "Dick", "Alice", "Alice" };
				_expected = "Alice";
				_received = _obj.getWinner(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}
			case 1:
			{
				string names[] = { "Alice", "Bill", "Carol", "Dick" };
				string votes[] = { "Carol", "Carol", "Bill", "Bill" };
				_expected = "";
				_received = _obj.getWinner(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}
			case 2:
			{
				string names[] = { "Alice", "Bill", "Carol", "Dick" };
				string votes[] = { "Alice", "Alice", "Bill", "Bill" };
				_expected = "Bill";
				_received = _obj.getWinner(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}
			case 3:
			{
				string names[] = { "Alice", "Bill" };
				string votes[] = { "Alice", "Bill" };
				_expected = "";
				_received = _obj.getWinner(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}
			case 4:
			{
				string names[] = { "WhiteRabbit", "whiterabbit", "whiteRabbit", "Whiterabbit" };
				string votes[] = { "whiteRabbit", "whiteRabbit", "whiteRabbit", "WhiteRabbit" };
				_expected = "whiteRabbit";
				_received = _obj.getWinner(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}
			/*case 5:
			{
				string names[] = ;
				string votes[] = ;
				_expected = ;
				_received = _obj.getWinner(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string names[] = ;
				string votes[] = ;
				_expected = ;
				_received = _obj.getWinner(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string names[] = ;
				string votes[] = ;
				_expected = ;
				_received = _obj.getWinner(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
