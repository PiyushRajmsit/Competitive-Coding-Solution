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

triplets extendedEuclid(int a,int b)
{
    
    if(a>b){
        return extendedEuclid(b,a);
    }
    
    if(a == 0)
    {
        triplets ans(b,0,1);
        return ans;
    }

    triplets smallans = extendedEuclid(b%a,a);

    int ans = smallans.ans;
    int x = smallans.y - (b/a)*smallans.x;
    int y = smallans.x;

    triplets result(ans,x,y);

    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    int a,b;
    
    cin>>a>>b;
        
    
    triplets t = extendedEuclid(a,b);
    cout<<a<<" "<<b<<endl;
    cout<<t.ans<<" "<<t.x<<" "<<t.y<<endl;
    
    
    return 0;
}
