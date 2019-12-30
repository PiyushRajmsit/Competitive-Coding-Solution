// Date - 18 Feb 2018
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
Ques   :  Roy and Coin Boxes Problem
Concept : DP
*/

#include<bits/stdc++.h>
 
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
 
    int  l[n+1];
    int  r[n+1];
 
    for(int i=0;i<n+1;i++){
        l[i] = 0;
        r[i] = 0;
    }
 
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a;
        cin>>b;
        l[a]++;
        r[b]++;
    }
 
    int for_box[n+1];
 
    for_box[1] = l[1];
 
    int max = 0;
    for(int i=2;i<n+1;i++){
        for_box[i] = l[i]-r[i-1]+for_box[i-1];
        if(max < for_box[i]){
          max = for_box[i];
        }
    }
  //  cout<<max<<endl;
  /*  for(int i=0;i<n+1;i++)
    cout<<for_box[i]<<" ";
    
    cout<<endl;
    */
    int for_coin[n+1];
 
    for(int i=0;i<n+1;i++){
        for_coin[i] = 0;
    }
 
    for(int i=1;i<n+1;i++){
        for_coin[for_box[i]]++;
    }
    
    /*for(int i=0;i<max+1;i++)
    cout<<for_coin[i]<<" ";
    */
    //cout<<endl;
//    for_coin[0] = 0;
 
    long long  for_atleast[1000011];
 
    for(int i=0;i<1000011;i++){
        for_atleast[i]  = 0;
    }
   
 
    //for_atleast[max]  = for_coin[max];
 
    for(int i=n;i>=0;i--){
        for_atleast[i] = for_atleast[i+1] + for_coin[i];
    }
 
  /*  for_atleast[0] = n;
    
    for(int i=0;i<8;i++)
    cout<<for_atleast[i]<<"  ";
    */
    //for_atleast[0] = 0;
 
 
 
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a;
        cin>>a;
    		    cout<<for_atleast[a]<<endl;
    }
    
 
    return 0;
}
