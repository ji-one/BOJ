#include <bits/stdc++.h>
using namespace std;
vector<char> v;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s, e;
    cin >> s >> e;

    int len = e.length();

    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s[i]);

        if (v.size() >= len && v.back() == e[len - 1])
        {
            int j;
            for (j = 0; j < len; j++)
            {
                if (v[v.size() - j - 1] != e[len - 1 - j])
                {
                    break;
                }
            }
            if (j == len)
            {
                for (int k = 0; k < len; k++)
                {
                    v.pop_back();
                }
            }
        }
    }

    if (v.empty())
        cout << "FRULA";
    else
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i];
    }

    return 0;
}
