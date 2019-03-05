// Date - 15 April 2018
/*
Solution By: Piyush Raj

/=============\   /===========\
||           ||   ||          ||
||           ||   ||          ||
||           ||   ||          ||
||=============   ||===========/
||                ||  \\
||                ||   \\
||                ||    \\
||                ||     \\
                           

Platform : Codeforces
Ques   : New Year Transportations Problem
Concept : DFS
*/


#include <iostream>
#include <vector>
using namespace std;
int n;
bool vst[30001];
int mp[30001];
void dfs(int k)
{
	vst[k]=true;
	if (!vst[mp[k]])
		dfs(mp[k]);
}
int main()
{
	int t,i,td;
	cin>>n>>t;
	for (i=1;i<n;i++)
	{
		cin>>td;
		mp[i]=i+td;
	}
	dfs(1);
	if (vst[t])
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
