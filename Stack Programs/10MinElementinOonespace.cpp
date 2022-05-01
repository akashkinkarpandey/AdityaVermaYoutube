#include<iostream>
#include<stack>
using namespace std;
stack<int>s;
int minelement;
int getMin()
{
    if(s.size()==0)
    {
    cout<<"Empty Stack\n";
    return -1;
    }
    return minelement;
}
int top()
{
    if(s.size()==0)
    {
    cout<<"Empty Stack\n";
    return -1;
    }
    else
    {
        if(s.top()>=minelement)
        return s.top();
        else if(s.top()<minelement)
        return minelement;
    }
    return 0;
}
void push(int x)
{
    if(s.size()==0)
    {
        s.push(x);
        minelement=x;
    }
    else
    {
        if(x>=minelement)
        s.push(x);
        else if(x<minelement)
        {
            s.push(2*x-minelement);
            minelement=x;
        }
    }
}
int pop()
{
    int t;
    if(s.size()==0)
    {
        cout<<"Nothing to pop\n";
        return 0;
    }
    else
    {
        if(s.top()>=minelement)
        {
            t=s.top();
            s.pop();
            
        }
        else if(s.top()<minelement)
        {
            t=s.top();
            minelement=2*minelement-s.top();
            s.pop();          
        }
    }
    return t;
}
int main()
{
    while(1)
    {
    printf("Enter 0 for exit\n");
    printf("Enter 1 for push\n");
    printf("Enter 2 to get minimum element\n");
    printf("Enter 3 for pop\n");
    printf("Enter 4 for top element\n");
    int n;
    cin >> n;
    switch (n)
    {
    case 0:printf("Thanks for exiting\n");return 0;
    case 1:
        printf("Enter a number to be pushed\n");
        int a;
        cin >> a;
        push(a);break;
    case 2:printf("Minimum element is %d\n",getMin());break;
    case 3:printf("%d has been popped out\n",pop());break;
    case 4:printf("Top element is %d\n",top());break;
    default:printf("Wrong Input\n");break;
    }
    }
}
