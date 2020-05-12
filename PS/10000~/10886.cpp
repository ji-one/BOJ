#include <bits/stdc++.h>
using namespace std;
int a[2];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    int o;
    for(int i=0;i<n;i++)
    {
        cin>>o;
        a[o]++;
    }
    
    if(a[0]>a[1]) cout<<"Junhee is not cute!";
    else cout<<"Junhee is cute!";
    return 0;
}
