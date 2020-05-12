#include <bits/stdc++.h>
using namespace std;
vector<string> v;
vector<string> rst;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n + m; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == v[i + 1])
        {
            rst.push_back(v[i]);
        }
    }
    cout << rst.size() << '\n';
    for (int i = 0; i < rst.size(); i++)
    {
        cout << rst[i] << '\n';
    }
}
