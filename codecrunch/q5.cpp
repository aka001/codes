#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
int main()
{
	map<string,string> day;
	day["2"]="A";
	day["22"]="B";
	day["222"]="C";
	day["3"]="D";
	day["33"]="E";
	day["333"]="F";
	day["4"]="G";
	day["44"]="H";
	day["444"]="I";
	day["5"]="J";
	day["55"]="K";
	day["555"]="L";
	day["6"]="M";
	day["66"]="N";
	day["666"]="O";
	day["7"]="P";
	day["77"]="Q";
	day["777"]="R";
	day["7777"]="S";
	day["8"]="T";
	day["88"]="U";
	day["888"]="V";
	day["9"]="W";
	day["99"]="X";
	day["999"]="Y";
	day["9999"]="Z";
	day["0"]=" ";
	day["1"]="";
	day["#"]="";
	day["*"]="";

	int t;
	cin >> t;
	while(t--)
	{
		string input;
		cin >> input;
		string temp="";
		int flag=0;
		string ans="";
		for(int i=0;i<input.length();i++)
		{
			if(i==0)
			{
				temp+=input[i];
			}
			else
			{
				if(input[i]==input[i-1])
				{
					temp+=input[i];
				}
				else
				{
					ans+=day[temp];
					temp="";
					temp+=input[i];

				}
			}
		}
		ans+=day[temp];
		temp="";
		cout << ans <<endl;	
	}
	return 0;
}
