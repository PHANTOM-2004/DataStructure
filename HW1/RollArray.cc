#include<iostream>
const int MAXN=1e5+3;

int arr[MAXN];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,k;
    std::cin>>n>>k;
    for(int i=0;i<n;i++)
        std::cin>>arr[i];
    const int start=n-k%n;
    int cnt=1;
    for(int i=start;i<n;i++,cnt++)
        std::cout<<arr[i]<<" \n"[cnt==n];
    for(int i=0;i<start;i++,cnt++)
        std::cout<<arr[i]<<" \n"[cnt==n];
    return 0;
}