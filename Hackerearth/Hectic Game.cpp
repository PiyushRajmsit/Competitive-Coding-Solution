// Date - 7 March 2018
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
Ques   : Hectic Game Problem
Concept : Bit Opeartions
*/


#include <bits/stdc++.h>
using namespace std;
 
struct task{
    
    int start;
    int end;
};
 
 
bool cmp(task a,task b)
{
    if(a.end != b.end)
     return a.end<b.end;
    
    return a.start > b.start;
}
 
int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        task* arr = new task[n];
        
        for(int i=0;i<n;i++)
        {
            
            cin>>arr[i].start>>arr[i].end;
        }
        
        sort(arr,arr+n,cmp);
        
        
        bool *s = new bool[n];
        
        
        for(int i=0;i<n;i++)
          s[i] = false;
          
          vector<int> a;
          vector<int> b;
         
         bool select = true;
         char ch = 'a';
         int  k = 0;
         int last = -1;
         while(select)
         {
             
         select = false;
             k = 0;
             last = -1;
         for(int i=0;i<n;i++)
         {
             if(s[i] == false && arr[i].start > last)
             {
                 last = arr[i].end;
                 select = true;
                 s[i] = true;
                 k++;
             }
         }
           if(select)
           {
           if(ch == 'a')
           {
              a.push_back(k);
              ch = 'b';
           }
             else {
                 b.push_back(k);
                 ch = 'a';
             }
           } 
         
             
         }
         
         int suma = 0;
         int sumb = 0;
         
   //      cout<<"SIzes  "<<a.size()<<"  "<<b.size()<<endl;
         
         for(int i=0;i<a.size();i++)
         {
             suma = suma^a[i];
        //     cout<<a[i]<<" ";
         }
         cout<<endl;
         for(int i=0;i<b.size();i++)
         {
             sumb = sumb^b[i];
          //   cout<<b[i]<<" ";
         }
         cout<<endl;
         if(suma > sumb)
           cout<<"Alice"<<endl;
           
        else if(suma == sumb)
           cout<<"Tie"<<endl;
         
        else {
           cout<<"Bob"<<endl;
        }
         
    }
    
    
    
    return 0;
}
