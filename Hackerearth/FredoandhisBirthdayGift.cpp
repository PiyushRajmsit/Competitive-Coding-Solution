#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{

	int t;
	cin>>t;

	while(t--)
	{
		int n,m;
		cin>>n>>m;

		int adj[20][20] = {0};
		
		for (int i = 0; i < m; ++i)
		{
			int x,y;
			cin>>x>>y;
			adj[x-1][y-1] = 1;
			adj[y-1][x-1] = 1;
		}

		int **dp = new int*[n+1];
		int col = 1<<n;
		for (int i = 0; i < n; ++i)
		{
			dp[i] = new int[col+4];

			for (int j = 0; j< col+4; ++j)
				dp[i][j] = -1;
		}
		
		for(int i=0;i<n;i++)
		{
		    dp[i][1<<i] = 0;
		}

		for (int i = 0; i < col; ++i)
		{
			for(int j=0;j<n;j++)
			{
				int bit = i&(1<<j);

				if(bit != 0)
				{
					for(int k = 0;k<n;k++)
					{
						int kthbit = i&(1<<k);

						if(kthbit != 0 && j!= k && adj[j][k] == 1)
						{
							if(dp[k][i^(1<<j)] != -1)
							{
								dp[j][i] = max(dp[k][i^(1<<j)] + 1,dp[j][i]);
							}
						} 
					}

				}

			}
		}
		for(int i=0;i<n;i++)
		{
			int ans = 0;
		    for(int j=0;j<(1<<n);j++)
		    	ans = max(dp[i][j],ans);

		    cout<<ans<<" ";
		}

		cout<<endl;

		for (int i = 0; i < n; ++i)
			delete[] dp[i];

		delete[] dp;

	
	}

		


	return 0;
}
