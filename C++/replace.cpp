#include<iostream>
#include<string>
using namespace std;

void move(string * S,int location);

void compare(string * S,string t)
{
    int length_S=S->length();
    int length_t=t.length();
    for(int i=0;i<length_S;i++)
    {
        for(int j=0;j<length_t;j++)
        {
            if((*S)[i]==t[j])
            {
                move(S,i);
            }

        }

    } 
}


void move(string * S,int location)
{
    int length_S=S->length();
    for(int i=location;i<length_S;i++)
    {
        (*S)[i]=(*S)[i+1];
    }
}

void print(string S)
{
    cout<<S<<endl;
}

int main()
{
    cout<<"请输入串s和t，实现从s中删除t的操作"<<endl; 
    string s,t;
	cin>>s>>t; 
    compare(&s,t);
    print(s);
    return 0;
}
