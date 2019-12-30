// Date - 11 March 2018
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
Ques   : Perfect Subbarray Problem
Concept : Adhoc
*/


#include <bits/stdc++.h>
using namespace std;
 
 int check(int num)
{
    
    int root = sqrt(num);
    int r1 = root*root;
    
    if(r1 == num)
     return 1;
    
    
return 0;
}
 
 
int main() {
	int n;
	cin>>n;
	
	int *arr = new int[n];
	
	
	
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	int count,ans= 0;
	for(int i=0;i<n;i++)
	{
	     count = 0;
	    
	    for(int j = i;j<n;j++)
	    {
	        count = count + arr[j];
	      ans = ans + check(count);
	    }
	    
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}
