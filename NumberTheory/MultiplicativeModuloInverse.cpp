#include <bits/stdc++.h>
using namespace std;
#define ll long long

class triplets{
public:
    int ans;
    int x;
    int y;

    triplets(){}

    triplets(int a,int b,int c){
        ans = a;
        x = b;
        y = c;
    }

};

triplets moduloInverse(int a,int b)
{
	/*
	if(a>b)
	{
		return moduloInverse(b,a);
	}*/
	if(a == 0)
	{
		triplets ans(b,0,1);
		return ans;
	}
	
	triplets smallAns = moduloInverse(b%a,a);
	
	triplets result;
	result.ans = smallAns.ans;
	result.x = smallAns.y - (b/a)*smallAns.x;
	result.y = smallAns.x;
	
	return result;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    int a,m;
    int test;
    cin>>test;
    
    while(test--)
    {
		cin>>a>>m;    
    
		if(__gcd(a,m) != 1){
			cout<<"Modulo Inverse of "<<a<<" mod "<<m<<" doesnt Exisit"<<endl;
		}
		else{
			triplets t = moduloInverse(a,m);
			int ans = (t.x%m + m)%m;
			cout<<"GCD of "<<a<<" and "<<m<<" is "<<t.ans<<endl;
			cout<<"Modulo Inverse of "<<a<<" mod "<<m<<" ==> "<<ans<<endl<<"======="<<endl;
		}
	}
    return 0;
}
