#include<bits/stdc++.h>
using namespace std;
 
int twomod(int a)
{
  if(a%2==1)
  return 2;
  
  return 1;
}
 
void buildtree(int *arr,int *tree,int start,int end,int treenode)
{
  if(start==end)
  {
    tree[treenode]=arr[start];
    return;
  }
  
  int mid = (start+end)/2;
  
  buildtree(arr,tree,start,mid,2*treenode);
  buildtree(arr,tree,mid+1,end,2*treenode + 1);
  
  int pr = twomod(end-mid);
 
  tree[treenode] = (  ( pr*(tree[2*treenode]% 3) )%3  + tree[2*treenode + 1] %3  )%3;
  
  return;
}
 
 
 
void update(int *tree,int start,int end,int index,int treenode)
{
if(start==end)  
{
  if(tree[treenode] == 0)
  tree[treenode]=1;
  
  return;
}
 
  int mid = (start+end)/2;  
   
  if(index<=mid)
  {
  update(tree,start,mid,index,2*treenode);  
  }
  else{
  update(tree,mid+1,end,index,2*treenode + 1);  
  }
 
  int pr = twomod(end-mid);
 
  tree[treenode] = (  ( pr*(tree[2*treenode]% 3) )%3  + tree[2*treenode + 1] %3  )%3;
  
  return;  
}
 
int query(int *tree,int start,int end,int left,int right,int treenode)
{
  
  // totally outside
  if(start > right || end < left)
  return 0;
  
  // totally inside
  if(start>=left && end<=right)
  {
    return tree[treenode] * twomod(right-end);
  }
  //partially in and out
   int mid = (start+end)/2;
     
  //left sub-tree
     int ans1 = query(tree,start,mid,left,right,2*treenode);
     
   //right sub-tree
    int ans2 = query(tree,mid+1,end,left,right,2*treenode + 1);
  
    int ans3;
  //  int pr = twomod(end-mid);
    
     ans3 = ((ans1)%3 + ans2%3)%3;
      
 return ans3; 
}
int main() 
{
 
  
  int n;
  string s1;
  cin>>n;
   
  int *arr = new int[n];
  int *tree = new int[4*n];
  
  cin>>s1;
   
  for(int i=0;i<n;i++)
  {
  arr[i] = s1[i]-48;
   
  }
 
  buildtree(arr,tree,0,n-1,1);
  //cout<<tree[1]<<endl;
  
  int q;
  cin>>q;
  int ans;
  int choice,idx1,idx2;
  while(q--)
  {
    cin>>choice;
   
    if(choice==1)
    {
      cin>>idx1;
      update(tree,0,n-1,idx1,1);
   //  cout<<tree[1]<<endl; 
    }
    else if(choice==0)
    {
      cin>>idx1>>idx2;
      ans = query(tree,0,n-1,idx1,idx2,1);
        cout<<ans<<endl;
    }
  }
  
  return 0;
}
