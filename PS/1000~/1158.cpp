#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    deque<int> dq;

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }
    cout << "<";
    while (!dq.empty())
    {
        for (int i = 0; i < k - 1; i++)
        {
            int x = dq.front();
            dq.pop_front();
            dq.push_back(x);
        }

        cout << dq.front();
        if(dq.size()!=1) cout<<", ";
        dq.pop_front();
    }
    cout << ">";
}
