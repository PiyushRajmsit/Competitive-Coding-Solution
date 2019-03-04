// Date - 12 Jan 2018
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
Ques   : Tricks Problem
Concept : Adhoc
*/


#include <iostream>
using namespace std;
#define ll long long
 
 
int main() {
/*	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
*/
int t;
cin>>t;
ll num;
 
while(t--)
{
    int ans = 0;
    
    cin>>num;
    
    if(num == 0 || num == 1)
        cout<<0<<endl;
        
    else
    {
        while(num > 1)
        {
            if( num % 2 !=0)    
                num--;
            else{
                num = num/2;
            }
            ans++;
        }
        
        cout<<ans<<endl;
    }
    
    
}
 
 
 
return 0;
}
