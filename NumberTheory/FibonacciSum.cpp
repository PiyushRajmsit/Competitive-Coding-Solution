#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void multiply(ll first[2][2],ll second[2][2]){
    ll f1 =  ( (first[0][0]*second[0][0] )%mod + (first[0][1]*second[1][0])%mod)%mod;
    ll f2 =  ( (first[0][0]*second[0][1] )%mod + (first[0][1]*second[1][1])%mod)%mod;
    ll f3 =  ( (first[1][0]*second[0][0] )%mod + (first[1][1]*second[1][0])%mod)%mod;
    ll f4 =  ( (first[1][0]*second[0][1] )%mod + (first[1][1]*second[1][1])%mod)%mod;
    
    first[0][0] = f1%mod;
    first[0][1] = f2%mod;
    first[1][0] = f3%mod;
    first[1][1] = f4%mod;

    return;
}



void fibonacci(ll arr[2][2],ll n){
    if(n == 1 || n == 0)
    {
        return;
    }
    
    fibonacci(arr,n/2);
    multiply(arr,arr);
    
    ll m[2][2] = {{0,1},{1,1}};    
    
    if(n%2 == 1)
        multiply(arr,m);

    return;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll a,b;
	cin>>a>>b;
  
    ll arr1[2][2] = {{0,1},{1,1}};
    ll arr2[2][2] = {{0,1},{1,1}};
    fibonacci(arr1,a+1);
	fibonacci(arr2,b+2);
	
	ll ans = ((arr2[0][1]%mod- arr1[0][1]%mod) + mod)%mod;

	cout<<ans<<endl;


    return 0;
}
    
