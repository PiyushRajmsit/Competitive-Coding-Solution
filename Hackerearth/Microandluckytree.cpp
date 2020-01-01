#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll dp[300][100010];
ll do_dfs(int curr,int mask,int n,int m,int parent,vector<int> *adj,int *bit)
{
	if(dp[mask][curr] != -1)
	{
		return dp[mask][curr];
	}
	
	ll ans = 0;
	if(adj[curr].size() == 1 && adj[curr][0] == parent)
	{
		for (int i = 1;i<=m; ++i)
		{
			if((mask&bit[i]) == 0)
			{
				ans++;
			}
		}
		//cout<<curr<<" "<<ans<<" "<<mask<<"||";
		dp[mask][curr] = ans;
		return ans;
	}


    int now_mask = mask;
	for(int i=1;i<=m;i++)
	{
		if(parent == -1)
			now_mask = bit[i];

		ll a = 1;
		for(int j=0;j<adj[curr].size();j++)
		{

			int nxt = adj[curr][j];
			if(nxt != parent)
				a = (a * do_dfs(nxt,now_mask&bit[i],n,m,curr,adj,bit))%mod;
		}
		
		ans = (ans+a)%mod;
	}
    //cout<<curr<<" "<<ans<<" "<<mask<<"|";
	dp[mask][curr] = ans%mod;
	return ans%mod;
}

int main(int argc, char const *argv[])
{


	int n,m;
	cin>>n>>m;

	memset(dp, -1, sizeof(dp));
    
	int prime[] = {2,3,5,7,11,13,17,19};
	
	int *bit = new int[40];
	
	for (int i = 1; i <=m ; ++i)
	{
		bit[i] = 0;
		int b = 0;
		for(int j=0;j<8;j++)
		{
			if(i%prime[j] == 0)
			{
				b = b|(1<<j);
			}
		}

		bit[i] = b;

	}


	vector<int> *adj = new vector<int>[n+1];

	for (int i = 0; i < n-1; ++i)
	{
		int s,e;
		cin>>s>>e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	ll ans = do_dfs(1,0,n,m,-1,adj,bit);
		

	cout<<ans<<endl;

	delete[] bit;


	return  0;
}
