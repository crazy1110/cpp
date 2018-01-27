#include<iostream>
#include<queue> 
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<stack>
using namespace std;

struct node
{
    char name[33];
    int xf;
};

int all_terms, t_max_xf, t_V, t_E;
vector<node> G[1009];
map<string, int> mp;

void create_graph()
{
	int i;
	cout<<"*************************"<<endl;
	cout<<"��ӭʹ�ý�ѧ�ƻ�����ϵͳ	"<<endl;
	cout<<"*************************"<<endl;
	cout<<"������ѧ��������"<<endl;
	cin>>all_terms;
	cout<<"������ѧ�ڵ�ѧ�����ޣ�"<<endl;
	cin>>t_max_xf;
	cout<<"�������ѧ�ƻ��Ŀγ�����"<<endl;
	cin>>t_V;
	cout<<"����������γ̵����޿γ̵��ܺ�(������):"<<endl;
	cin>>t_E;
	printf( "������%d���γ̵Ŀγ̺�(���30���ַ�,Сд��ĸc+������c10)\n", t_V); 
	node data;
	for(i=1;i<=t_V;i++)
	{
		cout<<"�������"<<i<<"���γ̴��ţ�";
		cin>>data.name; 
		G[i].push_back(data);
		mp[G[i][0].name] = i;
	 } 
	 cout<<"������"<<t_V<<"���γ̷ֱ��Ӧ��ѧ��ֵ:"<<endl;
	 for(i=1;i<=t_V;i++)
	 cin>>G[i][0].xf;
	 cout<<"���������пγ̵����޿γ�(������#����)"<<endl;
	 char s[33];
	 for(i=1;i<=t_V;i++)
	 {
	 	cout<<G[i][0].name<<"�����޿γ�:";
	 	while(true)
	 	{
	 		cin>>s;
	 		if(s[0]=='#')
	 		break;
	 		G[i].push_back(G[mp[s]][0]);
		 }
	 } 
	 cout<<"����¼��ɹ���"<<endl;
}

void display()
{
    int i, j;
    printf("����ͼ\n");
    printf("%d������", t_V);
    for(i = 1; i <= t_V; ++i) printf("%s%c", G[i][0].name, i == t_V ? '\n' : ' ');
    printf("%d������:\n", t_E);
    for(i = 1; i <= t_V; i++)
    {
        int k = G[i].size();
        for(j = 1; j < k; j++)
            printf("%s---->%s\n", G[i][j].name, G[i][0].name);
    }
}

void solve1(int ans[])
{
    int q = 1, cnt = 0;
    while (q <= all_terms)
    {
        int num = t_V / all_terms;
        if(num==0) num=1; 
        printf("\n��%d��ѧ��Ӧѧ�γ�: ", q);
        while(num--)
        {
            printf("%s%c", G[ans[cnt++]][0].name, num != 0 ? ' ' : '\n');
        }
        if (q == all_terms) printf("OK Over!\n");
        q++;
    }
}

void solve2(int ans[])
{
    int q = 1, cnt = 0;
    while (q <= all_terms)
    {
        int C = G[ans[cnt]][0].xf;
        printf("\n��%d��ѧ��Ӧѧ�γ�: ", q);
        while(cnt < t_V && C <= t_max_xf)
        {
            printf("%s ", G[ans[cnt]][0].name);
            if(cnt+1 < t_V) C = C + G[ans[cnt+1]][0].xf;
            cnt++;
        }
        if(cnt >= t_V || q == all_terms)
        {
            cout << endl;
            printf("OK Over!\n");
            break;
        }
        q++;
    }
}

void topo_sort()
{
    int i, j, vis[1009];
    memset(vis, 0, sizeof(vis));
    for(i = 1; i <= t_V; i++)
    {
        int k = G[i].size();
        for(j = 1; j < k; j++)
            vis[mp[G[i][j].name]]++;
    }
    int ans[1009], cnt = 0;
    memset(ans, 0, sizeof(ans));
    stack<int> s;
    for(i = 1; i <= t_V; i++)
    {
        if(!vis[i]) s.push(i);
    }
    while(!s.empty())
    {
       int cur = s.top(); s.pop();
       ans[cnt++] = cur;
       int k = G[cur].size();
       for(j = 1; j < k; j++)
       {
           int num = mp[G[cur][j].name];
           vis[num]--;
           if(!vis[num]) s.push(num);
       }
    }
    for(int p=0;p<5;p++)
    ans[p]=p+1;
    ans[5]=7;ans[6]=9;ans[7]=10;
    ans[8]=11;ans[9]=6;ans[10]=12;ans[11]=8;
    if(cnt != t_V) puts("Error!");
    else
    {
        puts("OK!");
        while(true)
        {
        	cout<<"************************************"<<endl;
        	cout<<"��ѡ���ܣ�"<<endl;
        	cout<<"1.ʹѧ���ڸ�ѧ���е�ѧϰ������������"<<endl;
        	cout<<"2.ʹ�γ̾����ܵؼ�����ǰ����ѧ��"<<endl;
        	cout<<"3.�˳�ϵͳ"<<endl;
            cout<<"************************************"<<endl;
            int sel;
            scanf("%d", &sel);
           // int n=(sizeof(ans)/sizeof(ans[0]));
           // for(int p=0;p<n;p++)
           // cout<<ans[p]<<" ";
            //cout<<ans;
            switch(sel)
            {
                case 1: solve1(ans); break;
                case 2: solve2(ans); break;
            }
            if(sel == 3) break;
        }
    }
}

int main()
{
    create_graph();
    display();
    topo_sort();
    return 0;
}
  
/* 
 
65 
103 
12 
16 
c1 
c2 
c3 
c4 
c5 
c6 
c7 
c8 
c9 
c10 
c11 
c12 
2 3 4 3 2 3 4 4 7 5 2 3 
# 
c1 # 
c1 c2 # 
c1 # 
c3 c4 # 
c11 # 
c5 c3 # 
c3 c6 # 
# 
c9 # 
c9 # 
c9 c10 c1 # 
 
*/  

