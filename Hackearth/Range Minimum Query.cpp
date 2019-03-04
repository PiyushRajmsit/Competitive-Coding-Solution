// Date - 12 Feb 2018
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
Ques   : Range Minimum Query Problem
Concept : Segment Tree
*/



#include<bits/stdc++.h>
using namespace std;
 
void buildtree(int *arr,int *tree,int start,int end ,int treenode)
{
  
  if(start==end)
  {
    tree[treenode]=arr[start];
    return;
  }
  
  int mid = (start+end)/2;
   
  buildtree(arr,tree,start,mid,2*treenode);
  buildtree(arr,tree,mid+1,end,2*treenode + 1);
  
  tree[treenode] = min(tree[2*treenode] , tree[2*treenode+1]);
  return ;
  
}
 
void update(int *arr,int *tree,int start,int end,int treenode,int index,int value)
{
	if(start==end)
	{
		arr[index] = value;
		tree[treenode] = value;
		return;
	}
	
	int mid = (start+end)/2;
	
	if(index<=mid)
	{
		update(arr,tree,start,mid,2*treenode,index,value);
	}
	else{
		update(arr,tree,mid+1,end,2*treenode + 1,index,value);
	}
	
	tree[treenode] = min(tree[2*treenode],tree[2*treenode + 1]);
 
     return;
}
 
 
int query(int *tree,int start,int end,int treenode,int left,int right)
{
  // if totally outside the range
  if(start > right ||  end < left )
  {
    return 2147483640;
  }
  
  // if totally inside the range
  if(start >= left && end <=right)
  {
    return tree[treenode];
  }
  
  
  // partiall inside and partially outside
  int mid = (start+end)/2;
  
  int op1 = query(tree,start,mid,2*treenode,left,right);
  int op2 = query(tree,mid+1,end,2*treenode+1,left,right);
  int ans = min(op1,op2);
  
  return ans;
}
 
 
int main() {
 
  int n,q;
  
  cin>>n>>q;
  
  int *arr = new int[n];
  arr[0]=0;
  int *tree = new int[3*n];
  
  for(int i=0;i<n;i++)
    cin>>arr[i];
    
   buildtree(arr,tree,0,n-1,1);
  
  
   /* for(int i=1;i<2*n;i++)
     cout<<tree[i]<<" ";
  */
  //cout<<endl;
  char ch;
  int x,y;
  int ans;
  
     while(q--)
     {
        cin>>ch>>x>>y;
      
       if(ch=='u')
        { 
         update(arr,tree,0,n-1,1,x-1,y);
       }
       else{
           ans = query(tree,0,n-1,1,x-1,y-1);    
       cout<<ans<<endl; 
       }
           
     }
  
 
        return 0;
}
