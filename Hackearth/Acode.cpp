// Date - 1 feb 2018
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
Ques   : Acode-Alpha code Problem
Concept : DP
*/
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long count_comb(string str, int size,int arr[],int index)
{
  if(size == 0)
  {
    return 1;
  }
  if(size == 1 )
  {
    if(str[index]!='0')
      return 1;
   
    return 0;
  }
  if(arr[size]>0)
  {
    return arr[size];
  }
  
  long long output=0;
   if(str[index]!='0')
   output = count_comb(str,size-1,arr,index+1);
     
    if(str[index] =='2')
    {
if(str[index+1]=='0'||str[index+1]=='1'||str[index+1]=='2'||str[index+1]=='3'||str[index+1]=='4'||str[index+1]=='5'||str[index+1]=='6')
      {
  output =  (output + count_comb(str,size-2,arr,index+2) ) % mod;
}   
    } 
  else 
    if(str[index]=='1')
    output =  (output + count_comb(str,size-2,arr,index+2) ) % mod;
  
  arr[size] = output;
  
  return output;
}
 
 
int main()
{
  string s1;
  int *arr = new int[5002];
  while(1)
  {
    cin>>s1;
    if(s1[0]=='0')
      return 0;
  for(int i=0;i<=s1.size();i++)
    arr[i]=0;
    
    long long result = count_comb(s1,s1.size(),arr,0) % mod;
    
    cout<<result<<endl;    
  }
   
  return 0;
}
