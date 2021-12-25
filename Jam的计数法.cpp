#include <bits/stdc++.h>
using namespace std;
int i, j, s, w, t, t1, a[200], rbb, lbb, cnt, k;
string st, st2, rb, lb;
bool f;
int main()
{
    cin >> s >> t >> w;
    cin >> st;
    lbb = s;
    rbb = t;
    t1 = 0;
    st2 = "";
    for (i = 0; i < st.size(); i++)
    {
        t1++;
        if (int(st[i] - 96) < 10)
        {
            st2 += '0';
            st2 += char(int(st[i] - 96) + 48);
        }
        else
        {
            st2 += char(int(st[i] - 96) / 10 + 48);
            st2 += char(int(st[i] - 96) % 10 + 48);
        }
        a[t1] = int(st[i] - 96);
    }
    cnt = 0;
    while (cnt != 5)
    {
        a[t1]++;
        for (j = t1; j >= 1; j--)
            if (a[j] > rbb)
            {
                a[j] = lbb;
                a[j - 1] += 1;
            }
        //for (j=1;j<=t1;j++)
        //cout<<char(a[j]+96);
        if (a[0] != 0)
            break;
        f = true;
        for (j = 1; j <= t1; j++)
            for (k = j + 1; k <= t1; k++)
                if (a[j] >= a[k])
                {
                    f = false;
                    break;
                }
        if (f == true)
        {
            for (j = 1; j <= t1; j++)
                cout << char(a[j] + 96);
            cout << endl;
            cnt++;
        }
    }
    return 0;
}
