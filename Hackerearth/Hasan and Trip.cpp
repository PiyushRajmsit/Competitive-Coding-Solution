// Date - 5 Feb 2018
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
Ques   : Hasan Trip Problem
Concept : Adhoc
*/



#include <bits/stdc++.h>
using namespace std;
double dist(double x1,double y1,double x2,double y2)
{
  
  double d1 = (x2-x1)*(x2-x1);
  double d2 = (y2-y1)*(y2-y1);
  double d3 = sqrt(d1+d2);  
  //cout<<d3<<endl;
  return d3;
}
int main()
{
  
  int n;
  cin>>n;
  double *x = new double[n];
  double *y = new double[n];
  double *happy = new double[n];
  double d1,d2;
  double *joy = new double[n];
  for(int i=0;i<n;i++)
  {
    cin>>x[i]>>y[i]>>happy[i];
    joy[i]=0;
  }
  joy[0]=happy[0];
  
  for(int i=1;i<n;i++)
    joy[i]=happy[i]+happy[0] - dist(x[0],y[0],x[i],y[i]);
   
  
  for(int i=1;i<n;i++)
  {
  /*    d1=dist(x[i-2],y[i-2],x[i],y[i]); 
      d2=dist(x[i-1],y[i-1],x[i],y[i]);
   joy[i]=joy[i-1]+happy[i]-d2;
  if(joy[i-2]+happy[i]-d1>joy[i-1]+happy[i]-d2)
    joy[i]=joy[i-2]+happy[i]-d1;*/ 
   for(int j=0;j<i;j++) 
   {
    d1 = dist(x[i],y[i],x[j],y[j]); 
     if(happy[i]+joy[j]-d1>joy[i])
       joy[i] = happy[i]+joy[j]-d1;
     
   }
  }
  printf("%lf",joy[n-1]);
  /*for(int i=0;i<n;i++)
 printf("%lf\n",joy[i]);
*/    return 0;
}
