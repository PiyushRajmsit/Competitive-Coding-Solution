// Date - 12 Dec 2017
/*
Solution By: Piyush Raj

/=============\   /===========\
||	      ||  ||	      ||
||	      ||  ||          ||
||	      ||  ||	      ||
||=============   ||==========||
||		  ||  \\
||		  ||   \\
||		  ||	\\
||		  ||	 \\
                           

Platform : Hackerearth
Ques   : Cibil
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
struct node{
    
    int a;
    int b;
    int index;
    string s1;
    
};
 
bool cmp(node a1,node b1)
{
    
    if(a1.a!=b1.a)
    {
        return a1.a>b1.a;
    
    }
    
    if(b1.b != a1.b)
    {
        return a1.b<b1.b;
    }
    
    if(a1.s1 != b1.s1)
    {
        int x1;
        int y1;
        char ch1,ch2;
        
        int l1 = a1.s1.length();
        int l2 = b1.s1.length();
        int i=0,j=0;
        
        while(i<l1 && j<l2)
        {
             ch1=a1.s1[i];
             ch2 = b1.s1[j];
            
            x1=ch1;
            y1=ch2;
            
            if(x1!=y1)
            {
                return x1>y1;
            }
           i++;
           j++;
        }
        i=l1-i;
        j=l2-j;
        
        
        return i>j;
    }
    
    else
    {
        return a1.index<b1.index;
    }
    
    
    
}
 
int main() {
	int t;
	cin>>t;
	int x,y;
	string s2;
	while(t--)
  {
     int n,k;
     cin>>n;
     
     node *arr = new node[n];
     
     for(int i=0;i<n;i++)
      {
         cin>>arr[i].s1;
         cin>>arr[i].a;
         cin>>arr[i].b;
         arr[i].index = i;
          
      }
      sort(arr,arr+n,cmp);
      
      cin>>k;
      
    /*  for(int i=0;i<n;i++)
        cout<<arr[i].s1<<" "<<arr[i].a<<" "<<arr[i].b<<endl;
      */
      cout<<arr[k-1].s1<<" "<<arr[k-1].a<<endl;
      
  }
	
}
