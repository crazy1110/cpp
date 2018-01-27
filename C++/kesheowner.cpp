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
	cout<<"		欢迎使用教学计划编制系统	"<<endl;
	cout<<"请输入学期总数："<<endl;
	cin>>all_terms;
	cout<<"请输入学期的学分上限："<<endl;
	cin>>t_max_xf;
	cout<<"请输入教学计划的课程数："<<endl;
	cin>>t_V;
	cout<<"请输入各个课程的先修课程的总和(边总数):"<<endl;
	cin>>t_E;
	printf( "请输入%d个课程的课程号(最多30个字符,小写字母c+数字如c10)\n", t_V); 
	node data;
	for(i=1;i<=t_V;i++)
	{
		cout<<"请输入第"<<i<<"个";
		cin>>data.name; 
		G[i].push_back(data);
		mp[G[i][0].name] = i;
	 } 
	 cout<<"请输入"<<t_V<<"个课程分别对应的学分值:"<<endl;
	 for(i=1;i<=t_V;i++)
	 cin>>G[i][0].xf;
	 cout<<"请输入下列课程的先修课程(输入以#结束)"<<endl;
	 char s[33];
	 for(i=1;i<=t_V;i++)
	 {
	 	cout<<G[i][0].name<<"的先修课程:"<<endl;
	 	while(true)
	 	{
	 		cin>>s;
	 		if(s[0]=='#')
	 		break;
	 		G[i].push_back(G[mp[s]][0]);
		 }
	 }
	 cout<<"数据录入成功！"<<endl;
}

void display()
{
    int i, j;
    printf("有向图\n");
    printf("%d个顶点", t_V);
    for(i = 1; i <= t_V; ++i) printf("%s%c", G[i][0].name, i == t_V ? '\n' : ' ');
    printf("%d条弧边:\n", t_E);
    for(i = 1; i <= t_V; i++)
    {
        int k = G[i].size();
        for(j = 1; j < k; j++)
            printf("%s---->%s\n", G[i][j].name, G[i][0].name);
    }
}



