#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void multiply(ll arr[2][2], ll mat[2][2], ll p)
{

	ll f1 = ((arr[0][0] * mat[0][0])%p + (arr[0][1] * mat[1][0])%p)%p ; 
	ll f2 =	((arr[0][0] * mat[0][1])%p + (arr[0][1] * mat[1][1])%p)%p ;
	ll f3 = ((arr[1][0] * mat[0][0])%p + (arr[1][1] * mat[1][0])%p)%p ;
	ll f4 = ((arr[1][0] * mat[0][1])%p + (arr[1][1] * mat[1][1])%p)%p ;

	arr[0][0] = f1;
	arr[0][1] = f2;
	arr[1][0] = f3;
	arr[1][1] = f4;

	return;
}
void fibonacci(ll arr[2][2],ll n,ll m){

	if(n == 0 || n == 1)
		return;


	fibonacci(arr,n/2,m);
	multiply(arr,arr,m);

	ll mat[2][2] = {{0,1},{1,1}};
	if(n%2 == 1)
		multiply(arr,mat,m);


	return;
}

ll fibo(ll n,ll m)
{
	
	ll arr[2][2] = {{0,1},{1,1}};
	fibonacci(arr,n,m);
	ll ans = arr[0][1];

	return ans;
}

ll power(ll a,ll n){

	if(n == 0 || n == 1)
	{
		if(n == 0)
			return 1;
		return a;
	}

	ll smallAns = power(a,n/2);
	smallAns = (smallAns%mod * smallAns%mod)%mod;

	if(n%2 == 1)
		smallAns = (smallAns%mod * a%mod)%mod;

	return smallAns;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll first;
		ll second;
		ll n;
		cin>>first>>second>>n;
		ll ans = first;
		if(n == 0 || n == 1)
		{
			if(n == 1)
				ans = second;
			cout<<ans<<endl;
			continue;
		}
		ans = 1;


		ll g0 = 1 + first;
		ll g1 = 1 + second;
		
		ll a = fibo(n-1,mod-1);
		ll b = fibo(n,mod-1);
		
		//cout<<n<<" "<<a<<" "<<b<<endl;
		
		ll gn =  (power(g0,a)%mod  * power(g1,b)%mod)%mod;
		ans = ((gn-1)+mod)%mod;
		cout<<ans<<endl;
	}
	
	return 0;
}
