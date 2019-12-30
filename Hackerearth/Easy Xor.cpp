// Date - 21 March 2018
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
Ques   :  Easy Xor Problem
Concept : Bitwise Xor
*/

#include<bits/stdc++.h>
using namespace std;
 
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int *arr = new int[n];
    
    int bits[5];
    
    for(int i=0;i<5;i++)
        bits[i] = 0;
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
     
     for(int j=0;j<n;j++)   
        {
            int k = arr[j];
            
            
            for(int i=0;i<4;i++)
            {
                int ans = (k>>i)&1;
                
                if(ans == 1)
                    {
                     bits[4-i] = bits[4-i]+1;     
                    }
            }
            
        }
    int sum = 0;
    for(int i=1;i<=4;i++)
    {
        
        int k = bits[i];
        
        if(k <=4)
        {
            
            sum = sum + k*(1<<(4-i));
        }
        
        else{
            if(k %2 == 1)
                sum = sum + 3*(1<<(4-i));
            else{
                
                sum = sum + 4*(1<<(4-i));
            }
            
        }
        
    }
    
    cout<<sum<<endl;
    
    
    return 0;
}
