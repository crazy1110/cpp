#include<bits/stdc++.h>
using namespace std;

struct node
{
	char name[33];
	int xf;
}

int all_terms,t_max_xf,t_V,t_E;
vector<node> G[1009];
map<string,int> mp;

void create_graph()
{
	int i;
	cout<<"		��ӭʹ�ý�ѧ�ƻ�����ϵͳ	"<<endl;
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
		cout<<"�������"<<i<<"��";
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
	 	cout<<G[i][0].name<<"�����޿γ�:"<<endl;
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



