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
Ques   : Vanya and GCD Problem
Concept : Number Theory
*/


#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int gcd(int a ,int b)
{
  if(a==0)
  return b;
  if(a>b)
  return gcd(b,a);
  
  return gcd(b%a,a);
}
int main()
{
  int n;
  cin>>n;
  int *arr = new int[n+1];
  
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  
  int **mat = new int*[101];
  
  for(int i=0;i<=100;i++)
    mat[i] = new int[n+1];
  
  
  for(int i=0;i<=100;i++)
  for(int j=0;j<=n;j++)
      mat[i][j]=0;
  
  int d ;
  int store;
 //mat[d][1]=1;
  for(int i=1;i<=n;i++)
  {
    d = arr[i];
    mat[d][i]=1;
  }
  for(int i=2;i<=n;i++)
  for(int j=1;j<i;j++)
  {
    if(arr[j]<arr[i])
    {
     for(int row=1;row<=100;row++)
     {
      if(mat[row][j]>0) 
      {
     store=gcd(row,arr[i]); 
       mat[store][i] = (mat[store][i]+ mat[row][j])%mod;   
      }
     }
    }
  }  
  
 long long sum=0;
 /* for(int i=1;i<=20;i++)
  {
    cout<<endl;
    for(int j=1;j<=n;j++)
    cout<<mat[i][j]<<" ";  
  }*/
  for(int i=1;i<=n;i++)
  {
    
    sum = (sum + mat[1][i])%mod;
    
  }
  cout<<sum<<endl;
  
  
    return 0;
}
