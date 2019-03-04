// Date - 9 Feb 2018
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
                           

Platform : Hackerearth
Ques   :  Sonya puts the blocks in the box Problem
Concept : DP
*/



#include <bits/stdc++.h>
using namespace std;
long long dp[101][1001];
bool dp2[101][1001];
long long dp3[101][1001];
#define ll long long
#define min -999999999999999
ll maxSum(ll arr[], ll n, ll k)
{
    ll res = 0;
    for (ll i=0; i<k; i++)
       res += arr[i];
 	ll curr_sum = res;
    for (ll i=k; i<n; i++)
    {
       curr_sum += arr[i] - arr[i-k];
       res = max(res, curr_sum);
    }
 
    return res;
}
long long getans(ll **arr,long long l,long long n,long long len[],long long m)
{
  if(l==n||m==0)
    return 0;
  if(dp2[l][m]==true)
	return dp[l][m];
    
  long long temp,leng,val=0,ans=0;
  long long test=0,max=0;
  
  for(int i=0;i<=m&&i<=len[0];i++)
  {
    if(dp3[l][i]==min)
    	dp3[l][i]=maxSum(arr[l],len[0],i);
    max=dp3[l][i];
      
    test=getans(arr,l+1,n,len+1,m-i);
    temp=max+test;
    if(ans<temp)
      ans=temp;
  }
    
  dp[l][m]=ans;
  dp2[l][m]=true;
  return ans;
}
int main()
{
  long long n,m,len[101];
  cin>>n>>m;
  memset(dp2,false,sizeof(dp2));
  for(int i=0;i<101;i++)
  {
    for(int j=0;j<1001;j++)
      dp3[i][j]=min;
  }
  ll ** arr=new ll*[n];
  for(int i=0;i<n;i++)
  {
    scanf("%lld",&len[i]);
    if(len[i]>0)
    {
    arr[i]=new ll[len[i]+1];
      	for(long long j=0;j<len[i];j++)
    	{
      		scanf("%lld",&arr[i][j]);
      	
    	}
    }
    else
     {   i--;n--;}
  }
 
 
  long long ans=getans(arr,0,n,len,m);
  printf("%lld",ans);
  
  
    return 0;
}
