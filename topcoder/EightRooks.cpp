#include<bits/stdc++.h>
using namespace std;
class EightRooks 
{
	public:
	string isCorrect(vector <string> board) 
	{
		int i,sz,ans=0,cnt=0,colvis[8],rowvis[8],flag=1,j;
		sz=board.size();
		for(i=0;i<8;i++)
		{
			colvis[i]=rowvis[i]=0;
		}
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				if(board[i][j]=='R')
				{
					cnt++;
					if(colvis[j] || rowvis[i])
					{
						flag=0;
						break;
					}
					colvis[j]=rowvis[i]=1;
				}
			}
		}
		if(flag && cnt==8)
			return "Correct";
		else
			return "Incorrect";
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
		cout << "Testing EightRooks (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1430939626;
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
		EightRooks _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"R.......",
				                  ".R......",
				                  "..R.....",
				                  "...R....",
				                  "....R...",
				                  ".....R..",
				                  "......R.",
				                  ".......R"};
				_expected = "Correct";
				_received = _obj.isCorrect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"........",
				                  "....R...",
				                  "........",
				                  ".R......",
				                  "........",
				                  "........",
				                  "..R.....",
				                  "........"};
				_expected = "Incorrect";
				_received = _obj.isCorrect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"......R.",
				                  "....R...",
				                  "...R....",
				                  ".R......",
				                  "R.......",
				                  ".....R..",
				                  "..R.....",
				                  ".......R"};
				_expected = "Correct";
				_received = _obj.isCorrect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"......R.",
				                  "....R...",
				                  "...R....",
				                  ".R......",
				                  "R.......",
				                  ".......R",
				                  "..R.....",
				                  ".......R"};
				_expected = "Incorrect";
				_received = _obj.isCorrect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........"};
				_expected = "Incorrect";
				_received = _obj.isCorrect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.isCorrect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.isCorrect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.isCorrect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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