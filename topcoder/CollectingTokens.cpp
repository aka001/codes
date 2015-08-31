#include<bits/stdc++.h>
using namespace std;
class CollectingTokens {
	public:
	int maxTokens(vector <int> A, vector <int> B, vector <int> tokens, int L) {
		
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
		cout << "Testing CollectingTokens (999.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1440891161;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 999.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CollectingTokens _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1};
				int B[] = {2};
				int tokens[] = {7,1};
				int L = 6;
				_expected = 8;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}
			case 1:
			{
				int A[] = {3,1};
				int B[] = {2,2};
				int tokens[] = {2,3,9};
				int L = 5;
				_expected = 14;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}
			case 2:
			{
				int A[] = {1,2,5,3};
				int B[] = {4,4,1,4};
				int tokens[] = {6,1,6,4,4};
				int L = 3;
				_expected = 16;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}
			case 3:
			{
				int A[] = {9,1,7,10,5,8,3,4,2};
				int B[] = {6,6,9,6,6,1,1,6,6};
				int tokens[] = {4,2,1,6,3,7,8,5,2,9};
				int L = 4;
				_expected = 26;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}
			case 4:
			{
				int A[] = {25,22,35,42,40,9,32,12,37,44,23,1,24,28,20,4,26,33,11,48,34,6,16,50,46,17,8,43,18,30,31,36,39,13,
				          10,45,3,47,15,2,29,19,7,14,41,49,38,27,21};
				int B[] = {5,5,25,25,25,42,25,40,5,35,25,32,42,9,32,23,40,25,20,33,26,37,12,1,48,24,22,25,11,24,48,34,18,9,50,42,16,40,1,
				          10,47,22,48,44,48,1,4,46,47};
				int tokens[] = {6,9,4,9,5,8,6,4,4,1,4,8,3,4,5,8,5,6,4,9,7,9,7,9,5,2,7,2,7,7,5,9,5,8,5,7,1,9,3,9,3,6,4,5,5,4,7,9,2,2};
				int L = 48;
				_expected = 194;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}
			/*case 5:
			{
				int A[] = ;
				int B[] = ;
				int tokens[] = ;
				int L = ;
				_expected = ;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				int B[] = ;
				int tokens[] = ;
				int L = ;
				_expected = ;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				int tokens[] = ;
				int L = ;
				_expected = ;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
