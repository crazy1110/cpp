#include<iostream>
using namespace std;
int main()
{
    int a[3][3],i,j,k,t,c,n=0;
    int b[3][3];
    printf("������һ��3��3�еľ���\n");
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        scanf("%d",&a[i][j]);
    printf("��������һ��3��3�еľ���\n");
    for(k=0;k<3;k++)
    for(t=0;t<3;t++)
        scanf("%d",&b[k][t]);
    printf("��ѡ��Ҫ���е����㣺1 ��� 2 ���\n ");
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
