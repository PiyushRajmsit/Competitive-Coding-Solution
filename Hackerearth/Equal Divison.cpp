// Date - 5 March 2018
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
Ques   : Equal Divison Problem
Concept : Adhoc
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    
    int n;
    cin>>n;
    
    ll *ai = new ll[n];
    ll *bi = new ll[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>ai[i]>>bi[i];
    }
    
    ll  sum  = 0;
    ll rem,add;
    
    /*
    for(int i=0;i<n;i++)
    { 
    }
    */
    for(int i=n-1;i>=0;i--)
    {
      
      ai[i] = ai[i] + sum;
      
       rem = ai[i]%bi[i];    
     
        if(rem == 0)
            add = 0;
            else
            {
       add = bi[i]-rem;
            }
       ai[i] = ai[i] + add;
      sum = sum + add;
    //  cout<<add<<endl;
        
    }
    cout<<sum<<endl;
    return 0 ;
}
