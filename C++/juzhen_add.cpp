#include<iostream>
using namespace std;
int main()
{
    int a[3][3],i,j,k,t,c,n=0;
    int b[3][3];
    printf("请输入一个3行3列的矩阵：\n");
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        scanf("%d",&a[i][j]);
    printf("请输入另一个3行3列的矩阵\n");
    for(k=0;k<3;k++)
    for(t=0;t<3;t++)
        scanf("%d",&b[k][t]);
    printf("请选择要进行的运算：1 相加 2 相乘\n ");
    scanf("%d",&c);
        if(c==1)
        {
            for(i=0;i<3;i++)
           for(j=0;j<3;j++)
            {a[i][j]=a[i][j]+b[i][j];
            printf("%2d",a[i][j]);
            n++;
            if(n%3==0)
            printf("\n");}
        }
        else
        {
            for(i=0;i<3;i++)
           for(j=0;j<3;j++)
            {a[i][j]=a[i][j]*b[i][j];
            printf("%2d",a[i][j]);
                        n++;
            if(n%3==0)
            printf("\n");   }
        }
}
