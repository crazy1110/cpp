#include"stdio.h"
#include"malloc.h"

int main()
{
    int n,k,m;
    int i,j;
    int sub=0,p=0,flag=0; 
    int *queue;
    scanf("%d %d %d",&n,&k,&m);
    queue=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        queue[i]=0;
     /*sub是用来存放多余的桃子。flag是用来控制循环用的。*/
    while(flag<n)
    {
        for(j=0;j<n;j++)
        {
            if(queue[j]>=m) /*这只猴子已经领满m个桃子。*/
                continue;
            else if((queue[j]+p%k+1<m)&&(sub==0))
            /*这只猴子还要继续领取他的桃子。*/
            {
                queue[j]=queue[j]+p%k+1;
                p++;
            }
            else if((sub==0)&&(queue[j]+p%k+1>=m))
            /*这只猴子刚领满m个桃子。*/
            {
                sub=queue[j]+(p%k)+1-m;
                queue[j]=m;
                p++;
                flag++;
                printf("%d ",j+1);
            }
            else if((sub+queue[j]<m)&&(sub!=0))
            /*这只猴子还要继续领取他的桃子。*/
            {
                queue[j]=queue[j]+sub;
                sub=0;
            }
            else if((queue[j]+sub>=m)&&(sub!=0))
            /*这只猴子刚领满m个桃子。*/
            {
                sub=sub+queue[j]-m;
                queue[j]=m;
                flag++;
                printf("%d ",j+1);
            }
        }
    }
}


