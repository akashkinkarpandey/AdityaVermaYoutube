#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
stack<int> ss;
void push(int a)
{
    s.push(a);
    if (ss.size() == 0 || ss.top() >= a)
        ss.push(a);
    return;
}
int getMin()
{
    if (ss.size() == 0)
        return -1;
    return ss.top();
}
int pop()
{   
    int ans=-1;
    if(s.size()!=0)
    {
    ans = s.top();
    s.pop();
    
    if (ans == ss.top())
    {
        ss.pop();
    }
    }
    return ans;
}
int main()
{
    while(1)
    {
    printf("Enter 0 for exit\n");
    printf("Enter 1 for push\n");
    printf("Enter 2 to get minimum element\n");
    printf("Enter 3 for pop\n");
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
    default:printf("Wrong Input\n");break;
    }
    }
}
