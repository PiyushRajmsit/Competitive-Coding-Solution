#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*
 * 
 * 
 *  Fermats theorem Says that
 *  a^p mod p = a mod p]
 *  where p is a prime number
 * 
 *  So, Evaluating above Theorem and dividing with a both sides a^2
 *   a^(p-2) mod p = a ^ (-1) mod p = ModInvserse(a,p);
 * 
 *  ModInverse(a,p) = a^(p-2) mod p;
 * 	
 * 
 * 
 * 	Wilson Theorem Says that 
 *  
 *  (p-1)! mod p = p-1; 
 * 	where p is prime
 *  
 *  Using above Theorem
 *  when n < p
 *  n! mod p = (p-1)!/(n+1)*(n+2)*(n+3)............(p-1) mod p
 *  
 *  = (p-1) * ModInvserse(n+1,p)*ModInvserse(n+2,p).........ModInvserse(p-1,p); 
 * 
 * 
 */
 
ll power_2(ll a,ll n,ll p)
{
	if(n == 0)
		return 1;
		
	if(n == 1)
		return a;
	 
	ll smallAns = power_2(a,n/2,p);
	smallAns = (smallAns%p * smallAns%p)%p;
	
	if(n%2 == 1)
		smallAns = (smallAns%p * a%p)%p;
		
		
	 return smallAns%p;
}
 
ll inverse(ll num,ll prime)
{
	ll res = power_2(num,prime-2,prime) % prime;
	
	return res;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		
		ll n,p;
		cin>>n>>p;
				
		if(n >= p){
			cout<<0<<endl;
			continue;
		}
		
		ll ans = 1; 
		for(int i=n+1;i<=p-1;i++)
		{
			ll curr_inv = inverse(i ,p);
			ans = (ans%p * curr_inv%p)%p;
		}
		ans = ((ans%p)*(p-1))%p;
		
		cout<<ans<<endl;
	}
	
	return 0;
}
