#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
 * Finding total number of Positive Integral solution pairs(x,y) for 
 *  Ax + By = D
 * 	A,B,D are given
 * 
 *  Solution Breakdown:
 *  total_terms = (d/b - y1)/a  + 1;
 *  
 * 	Where y1 is smallest possible value of y
 *  y1 = (d/b)%a
 * 
 * 	y1 = (d % a) * ModInverse(b,a)
 *  
 *  
 * 
 */

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

triplets ModInverse(int a,int b)
{
	if(a == 0)
	{
		triplets ans(0,1,b);
		return ans;
	}
	
	triplets smallAns = ModInverse(b%a,a);
	triplets result;
	result.ans = smallAns.ans;
	result.x = smallAns.y - (b/a)*smallAns.x;
	result.y = smallAns.x;
	return result;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    int a,b,d;
    int test;
    cin>>test;
    
    while(test--)
    {
		cin>>a>>b>>d;	
		int ans = 0;
		int g = __gcd(a,b);
		a = a/g;
		b = b/g;
		
		if(d%g)
		{
			ans = 0;
		}
		else
		{
			d = d/g;
			triplets answer = ModInverse(b,a);
			int modInverse_b_a = (answer.x + a)%a;
			int y1 = (d%a) * modInverse_b_a;
			
			if(y1 < 0 || b*y1 > d)
			{
				ans = 0;
			}
			else
			{
				int termsCount =  (d/b - y1)/a + 1;
				ans = termsCount;
			}
		}
		cout<<ans<<endl;
		
	}
    return 0;
}
