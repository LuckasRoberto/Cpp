#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;
#define ll long long
//Let's code together 
/* Lucas Nogueira - Problema: Fractal street */
ll pw[40];

void rec(ll n,ll s,ll &x,ll &y){
    if(n==1)
    {
        if(s==1)x=1,y=1;
        else if(s==2)x=1,y=2;
        else if(s==3)x=2,y=2;
        else x=2,y=1;
        return;
    }
    if(s<=pw[n-1])rec(n-1,s,y,x);
    else if(s<=2*pw[n-1])rec(n-1,s-pw[n-1],x,y),y+=(1<<n-1);
    else if(s<=3*pw[n-1])rec(n-1,s-2*pw[n-1],x,y),x+=(1<<n-1),y+=(1<<n-1);
    else rec(n-1,s-3*pw[n-1],y,x),x=(1<<n)+1-x,y=(1<<n-1)+1-y;
}

int main(){
    int t;
    cin >> t;

    pw[0] = 1;
    for(int i = 1; i <= 40; i++) pw[i] = 4*pw[i-1];

    while(t--){
          ll n, h, o;
          ll ox, oy, hx, hy;

          cin >> n >> h >> o;
          
          rec(n, h, hx, hy);
          rec(n, o, ox, oy);
          
          double res = 10*sqrt((double)(hx-ox)*(hx-ox)+(double)(hy-oy)*(hy-oy));
          printf("%.0f\n",res);
    }
}