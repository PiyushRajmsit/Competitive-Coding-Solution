// Date - 15 April 2018
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
                           

Platform : Codeforces
Ques   : Star Sky Problem
Concept : DP
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,q,c;
  int t1,x1,y1,x2,y2,s1;
  
  // star x1 y1 s1
  int star[101][101][12];

  // bright x1 y1 s1
  int bright[101][101][12];
  
  for(int i=0;i<=100;i++)
  for(int j=0;j<=100;j++)
    for(int k=0;k<=11;k++)
    {
      star[i][j][k] = 0;
      bright[i][j][k] = 0;
    }
  
  
  cin>>n>>q>>c;
  
  
  for(int i=0;i<n;i++)
  {
    cin>>x1>>y1>>s1;
    star[x1][y1][s1] = star[x1][y1][s1] + 1;
  }
  
  // filling bright[1][1]
  
  for(int t=0;t<=c+1;t++)
  {
  for(int i=0;i<=c;i++)
  {
   bright[1][1][t] = bright[1][1][t] + ( (i+t)%(c+1))*star[1][1][i]; 
  }
  }
  //cout<<bright[1][1][3]<<endl;

  // filling horizontal  
  
  for(int t=0;t<=c+1;t++)
  {
    for(int x=2;x<=100;x++)
    {
      bright[x][1][t] = bright[x-1][1][t];
      for(int i=0;i<=c;i++)
      {
         
        bright[x][1][t] = bright[x][1][t] + ((i+t)%(c+1))*star[x][1][i];
      } 
  }
  }
  //cout<<bright[2][1][3]<<endl;
  
  // filling vetical
   for(int t=0;t<=c+1;t++)
  {
    for(int y=2;y<=100;y++)
    {
      bright[1][y][t] = bright[1][y-1][t];
      for(int i=0;i<=c;i++)
      {
         
        bright[1][y][t] = bright[1][y][t] + ((i+t)%(c+1))*star[1][y][i];
      } 
  }
  }
  
  
  // filling the entire grid
  
  for(int t=0;t<=c+1;t++)
  {
    for(int x=2;x<=100;x++)
  {
      for(int y=2;y<=100;y++)
      {
       bright[x][y][t] = bright[x-1][y][t]+bright[x][y-1][t] - bright[x-1][y-1][t];
        for(int i=0;i<=c;i++)
        {
          bright[x][y][t] = bright[x][y][t] + ((i+t)%(c+1)) * star[x][y][i];
        } 
      }  
    }
  }
// cout<<bright[5][5][0]<<" "<<bright[5][5][1]<<" "<<bright[5][5][2]<<" "<<bright[5][5][3]<<" "<<bright[5][5][4]<<" "<<endl;
  int ti;
  for(int i=0;i<q;i++)
  {
    cin>>ti>>x1>>y1>>x2>>y2;
    
    int ans = bright[x2][y2][ti%(c+1)] - bright[x2][y1-1][ti%(c+1)] - bright[x1-1][y2][ti%(c+1)] + bright[x1-1][y1-1][ti%(c+1)];
    cout<<ans<<endl;
    
  }
    
    return 0;
}
