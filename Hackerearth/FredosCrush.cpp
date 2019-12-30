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


		for(int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x-1][y-1] = 1;
			adj[y-1][x-1] = 1;
		}

		bool **dp = new bool*[n];
		int col = 1<<n;
		for(int i=0;i<n;i++)
		{
			dp[i] = new bool[col+1];
			for(int j=0;j<col+1;j++)
				dp[i][j] = false;
		}

		for (int i = 0; i < n; ++i)
		{
			dp[i][1<<i] = true;
		}


		for(int i=0;i<(1<<n);i++)
		{

			for(int j=0;j<n;j++)
			{
				int jthbit = i&(1<<j);

				if(jthbit != 0 )
				{
					for(int k=0;k<n;k++)
					{
						int kthbit = i&(1<<k);
						
						if(kthbit != 0  && j!= k && adj[j][k] == 1)
						{
							if(dp[k][i^(1<<j)] )
							{
								dp[j][i] = true;
							}
						}	

					}
				}

			}
		}

		int a = -1;
		int b = 1000;
		
		for(int i=0;i<n;i++)
		{
			int row_ans = -1;
			int max_row_set_bits = 0;
			for(int j=0;j<col;j++)
			{

				if(dp[i][j] == true)
				{
					int bit_count = 0;
					int sum = 0;
					for(int k = 31;k>=0;k--)
					{
						int bit = j&(1<<k);

						if(bit != 0)
						{
							bit_count++;
							sum = sum + (k+1);
						}
					}

					if(bit_count >= max_row_set_bits)
					{
						row_ans = max(row_ans,sum);
						max_row_set_bits = bit_count;
					}
				}
			}
            //cout<<row_ans<<" | ";
			a = max(a,row_ans);
			b = min(b,row_ans);
		}

        int g = __gcd(a,b);
		a = a/g;

		b = b/g;

		cout<<a<<" "<<b;
		cout<<endl;
	}


	return 0;
}
