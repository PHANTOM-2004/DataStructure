#include<iostream>
#include<iomanip>

int main()
{
    double sum=0;
    for(int i=1;i<=12;i++)
    {
        double x;
        std::cin>>x;
        sum+=x;
    }
    sum/=12;
    std::cout<<"?"<<std::setprecision(2)<<std::setiosflags(std::ios::fixed)<<sum<<'\n';
    return 0;
}