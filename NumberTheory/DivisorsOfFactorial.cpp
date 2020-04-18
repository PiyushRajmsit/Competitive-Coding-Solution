#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
       
    int test;
    cin>>test;
    vector<int> allPrime;
    bool *prime = new bool[50011];

    for(int i=0;i<50010;i++)
        prime[i] = false;

    for(int i=2;i*i<=50010;i++)
    {
        if(!prime[i])
        {
            for(int j = i*i;j<=50010;){
                prime[j] = true; 
                j += i;
            }
        }

    }

    allPrime.push_back(2);

    for(int i=3;i<=50010;i+=2)
    {
        if(!prime[i])
            allPrime.push_back(i);
    }
    
    int size = allPrime.size();
    
    while(test--)
    {
        int n;
        cin>>n;
        ll ans = 1;
        int j = 0;
        while(j<size && allPrime[j] <= n)
        {

            ll primeElement = allPrime[j];
            
            ll start = primeElement;
            ll prod = 0;
            while(start<=n)
            {
                prod += n/start;
                start = start*primeElement;
            }
            ans = (ans%mod * (prod+1)%mod)%mod;
            j++;
        }

        cout<<ans<<endl;
    }
	allPrime.clear();
    delete[] prime;    
    return 0;
}
