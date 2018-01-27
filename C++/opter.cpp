#include<iostream>
#include<stack>
#include<cstring>  
#include<cstdio>  
#include<cctype> 
using namespace std;
stack <char> opter;
stack <double> opval;
char getPriority(char theta1, char theta2)   //��ȡtheta1��theta2֮������ȼ�  
{  
    const char priority[][7] =     //���������ȼ���ϵ  
    {  
        { '>','>','<','<','<','>','>' },  
        { '>','>','<','<','<','>','>' },  
        { '>','>','>','>','<','>','>' },  
        { '>','>','>','>','<','>','>' },  
        { '<','<','<','<','<','=','0' },  
        { '>','>','>','>','0','>','>' },  
        { '<','<','<','<','<','0','=' },  
    };  
  
    int index1 = getIndex(theta1);  
    int index2 = getIndex(theta2);  
    return priority[index1][index2];  
}  
int getIndex(char theta)   //��ȡtheta����Ӧ������  
{  
    int index = 0;  
    switch (theta)  
    {  
    case '+':  
        index = 0;  
        break;  
    case '-':  
        index = 1;  
        break;  
    case '*':  
        index = 2;  
        break;  
    case '/':  
        index = 3;  
        break;  
    case '(':  
        index = 4;  
        break;  
    case ')':  
        index = 5;  
        break;  
    case '#':  
        index = 6;  
    default:break;  
    }  
    return index;  
}  
  double calculate(double b, char theta, double a)   //����b theta a  
{  
    switch (theta)  
    {  
    case '+':  
        return b + a;  
    case '-':  
        return b - a;  
    case '*':  
        return b * a;  
    case '/':  
        return b / a;  
    default:  
        break;  
    }  
}  
  
double getAnswer()   //���ʽ��ֵ  
{  
    opter.push('#');      //���Ƚ�'#'��ջopter  
    int counter = 0;      //��ӱ���counter��ʾ�ж��ٸ����������ջ��ʵ�ֶ�λ������������  
    char c = getchar();  
    while (c != '#' || opter.top() != '#')   //��ֹ����  
    {  
        if (isdigit(c))   //���c��'0'~'9'֮��  
        {  
            if (counter == 1)   //counter==1��ʾ��һ�ַ�Ҳ�����֣�����Ҫ�ϲ�������12*12��Ҫ��12�������ǵ�����1��2  
            {  
                double t = opval.top();  
                opval.pop();  
                opval.push(t * 10 + (c - '0'));  
                counter = 1;  
            }  
            else  
            {  
                opval.push(c - '0');     //��c��Ӧ����ֵ��ջopval  
                counter++;  
            }  
            c = getchar();  
        }  
        else  
        {  
            counter = 0;   //counter����  
            switch (getPriority(opter.top(), c))   //��ȡ�����ջopterջ��Ԫ����c֮������ȼ�����'>'��'<'��'='��ʾ  
            {  
            case '<':               //<��c��ջopter  
                opter.push(c);  
                c = getchar();  
                break;  
            case '=':               //=��opterջ��Ԫ�ص������������ŵĴ���  
                opter.pop();  
                c = getchar();  
                break;  
            case '>':               //>�����  
                char theta = opter.top();  
                opter.pop();  
                double a = opval.top();  
                opval.pop();  
                double b = opval.top();  
                opval.pop();  
                opval.push(calculate(b, theta, a));  
            }  
        }  
    }  
    return opval.top();   //����opvalջ��Ԫ�ص�ֵ  
}  
  int main()  
{  
    //freopen("test.txt", "r", stdin);  
    int t;     // ��Ҫ����ı��ʽ�ĸ���  
    cin >> t;  
    getchar();  
    while (t--)  
    {  
        while (!opter.empty())opter.pop();  
        while (!opval.empty())opval.pop();  
        double ans = getAnswer();  
        cout << ans << endl<< endl;  
        getchar();  
    }  
    return 0;  
}  
