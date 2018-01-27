#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
#include<cmath>  
using namespace std;  
struct ssr  
{  
    int x,y;  
} re[100005];  
  
bool cmp( ssr x,ssr y)  
{  
    return x.y>y.y;  
}  
  
int main()  
{  
    int n;  
    while(cin>>n)  
    {  
        for(int i=1; i<=n; i++)  
        {  
            scanf("%d %d",&re[i].x,&re[i].y);///下x人，上y人  
        }  
        sort(re+1,re+1+n,cmp);  
        long long sum=0;///此处要用long long  
          
        int flag=1;  
        for(int i=n; i>=1; i--)  
        {  
            sum+=re[i].x-re[i].y;///此处的sum相当于r  
              
            if(sum<re[i].x)///sum必须大于x  
            {  
                flag=0;  
                break;  
            }  
  
        }  
        if(flag)  
        {  
            printf("Yes\n");  
        }  
        else  
        {  
            printf("No\n");  
        }  
  
    }  
    return 0;  
}
