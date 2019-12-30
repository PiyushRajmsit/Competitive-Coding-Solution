// Date - 2 March 2018
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
Ques   : Vasya and Rhezo Problem
Concept : Segment Tree
*/




#include<bits/stdc++.h>
using namespace std;
 
int a[1000002];
int b[1000002];
int tree[4*1000002];
 
    void fastscan(int &x)
    {
        bool neg=false;
        register int c;
        x =0;
        c=getchar();
        if(c=='-')
        {
            neg = true;
            c=getchar();
        }
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }
 
 
void buildTree(int start, int end, int treeNode){
  if(start == end){
    tree[treeNode] = start;
    return;
  }
  int mid = start + (end - start)/2;
  buildTree(start, mid, 2*treeNode);
  buildTree(mid+1, end, 2*treeNode+1);
  
  int l = tree[2*treeNode];
  int r = tree[2*treeNode+1];
  
  if(a[l] > a[r]){
    tree[treeNode] = l;
  }
  else if(a[l] < a[r]){
    tree[treeNode] = r;
  }
  else if(b[l] < b[r]){
    tree[treeNode] = l;
  }
  else if(b[l] > b[r]){
    tree[treeNode] = r;
  }
  else{
    tree[treeNode] = ((l<r)?l:r);
  }
}
 
int query(int start, int end, int treeNode, int left, int right){
  //node is completely outside the range
  if(end < left || start > right){
    return -1;
  }
  //node is completely inside the range
  if(start>=left && end<=right){
    return tree[treeNode];
  }
  //node is partially inside the range
  int mid = start + (end - start)/2;
  int l = query(start, mid, 2*treeNode, left, right);
  int r = query(mid+1, end, 2*treeNode+1, left, right);
  
  if(l == -1){
    return r; 
  }
  if(r == -1){
    return l;
  }
  
  if(a[l] > a[r]){
    return l;
  }
  else if(a[l] < a[r]){
    return r;
  }
  else if(b[l] < b[r]){
    return l;
  }
  else if(b[l] > b[r]){
    return r;
  }
  else{
    return ((l<r)?l:r);
  }  
}
 
int main() {
  int n;
  fastscan(n);
  for(int i=0;i<n;i++){
    fastscan(a[i]);
  }
  for(int i=0;i<n;i++){
    fastscan(b[i]);
  }  
  
  buildTree(0, n-1, 1);
  
  int Q;
  fastscan(Q);
  while(Q--){
    int l, r;
    fastscan(l);
    fastscan(r);
    int ans = query(0, n-1, 1, l-1, r-1) + 1;
    printf("%d\n", ans);
  }
  return 0;
}
