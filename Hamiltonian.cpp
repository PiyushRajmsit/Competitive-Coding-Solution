#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{

	int adj[20][20] = {0};
	int n,m;
	cin>>n>>m;

	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin>>x>>y;

		adj[x-1][y-1] = 1;
		adj[y-1][x-1] = 1;
	}


	bool **dp = new bool*[n];

	for (int i = 0; i < n; ++i)
	{
		dp[i] = new bool[1<<n];
		for (int j = 0; j < (1<<n);j++)
		{
			dp[i][j] = false;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		dp[i][1<<i] = true;
	}

	for (int i = 0; i < (1<<n); ++i)
	{
		for(int j=0;j<n;j++)
		{
			int bit = i&(1<<j);
			if(bit != 0)
			{
				for(int k=0;k<n;k++)
				{
					int also = i&(1<<k);
					
					if(also != 0 && j!= k && adj[j][k] == 1)
					{
						if(dp[k][i^(1<<j)] == true)
						{
							dp[j][i] = true;
						}
					}
				}
			}
		}
	}

	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		if(dp[i][(1<<n) - 1])
		{
			flag = true;
			break;
		}
	}
	if(flag)
	{
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}

	for (int i = 0; i < n; ++i)
		delete[] dp[i];

	delete[] dp;	

	return 0;
}
