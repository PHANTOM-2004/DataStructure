#include<iostream>


int main()
{
    int n,m;
    std::cin>>n>>m;
    int a=1,b=0;
    for(int i=1;i<=n;i++)
    {
        b=(a+m)%i;
        a=b;
    }
    std::cout<<b<<'\n';
    return 0;
}