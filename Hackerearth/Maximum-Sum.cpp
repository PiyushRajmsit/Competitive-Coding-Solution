// Date - 15 Feb 2018
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
Ques   : Maximum-Sum Problem
Concept : Segment Tree
*/


#include<bits/stdc++.h>
using namespace std;
 
struct node
{
  int maxi;
  int smax;
};
 
void buildtree(int* arr,node* tree,int start,int end,int treenode)
{
  if(start==end)
  {
    tree[treenode].maxi=arr[end];
    tree[treenode].smax=INT_MIN;
    return;
  }
  int mid=(start+end)/2;
 
  buildtree(arr,tree,start,mid,2*treenode);
  buildtree(arr,tree,mid+1,end,2*treenode+1);
 
  node left=tree[2*treenode];
  node right=tree[2*treenode+1];
  
  tree[treenode].maxi=max(left.maxi,right.maxi);
  tree[treenode].smax=min ( max( left.maxi , right.smax ) , max( left.smax , right.maxi ) );
  
  return;
}
 
void update(int* arr,node* tree,int start,int end,int treenode,int pos,int element)
{
  if(start==end)
  {
    arr[pos]=element;
    tree[treenode].maxi=element;
    tree[treenode].smax=INT_MIN;
    return;
  }
  int mid=(start+end)/2;
 
  if(pos>mid)
    update(arr,tree,mid+1,end,2*treenode+1,pos,element);
  else
    update(arr,tree,start,mid,2*treenode,pos,element);
 
  node left=tree[2*treenode];
  node right=tree[2*treenode+1];
  
  tree[treenode].maxi=max(left.maxi,right.maxi);
  tree[treenode].smax = min ( max(left.maxi,right.smax) , max(left.smax,right.maxi) );
 
  return;
}
 
pair<int, int> sum(node* tree,int start,int end,int treenode,int left,int right)
{
	if( start>=left && end <= right )
		return {tree[treenode].maxi,tree[treenode].smax};
 
	if(end < left || start> right)
		return {INT_MIN, INT_MIN};
 
	int mid = ( start + end ) / 2;
 
	pair<int, int> p1 = sum(tree,start,mid,2*treenode,left,right);
	pair<int, int> p2 = sum(tree,mid+1,end,2*treenode+1,left,right);
 
	pair<int, int> p3;
	p3.first = max(p1.first, p2.first);
	p3.second = min(max(p1.first, p2.second), max(p1.second, p2.first));
	return p3;
}
 
int main() {
 
	// Write your code here
  int n, test;
  cin>>n;
  int* arr=new int[n];
  node* tree=new node[3*n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  buildtree(arr,tree,0,n-1,1);
  //for(int i=0;i<n;i++)
    //cout<<tree[i]<<" ";
  cin>>test;
  while(test--)
  {
    char ch;
    cin>>ch;
 
      int l,r;
      cin>>l>>r;
    if(ch == 'Q' )
    {
      pair<int, int> p = sum(tree,0,n-1,1,l-1,r-1);
      int sum = p.first+p.second;
      cout<<sum<<endl;
    }
      else {
             update(arr,tree,0,n-1,1,l-1,r);
           }
}
 
}
