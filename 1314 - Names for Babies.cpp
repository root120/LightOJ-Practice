
#include <bits/stdc++.h>
#define FastRead ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int MAX = 10010;

struct info
{
    int tup[2], idx;

    bool operator<(const info &a) const
    {
        return tup[0] != a.tup[0] ? tup[0] < a.tup[0] : tup[1] < a.tup[1];
    }
} arr[MAX];

int Rank[18][MAX], LCP[MAX], step;
string text;

void build_suffix_array()
{
    int n = text.size(), jump;

    for(int j=0; j<n; j++)
    {
        Rank[0][j] = text[j];
        memset(arr[j].tup, 0, sizeof(arr[j].tup));
    }

    for(step = 1, jump = 1; jump <=n; step++, jump <<= 1)
    {
        for(int j=0; j<=n; j++)
        {
            arr[j].idx = j;
            arr[j].tup[0] = Rank[step-1][j];
            arr[j].tup[1] = j + jump < n ? Rank[step-1][j+jump] : -1;
        }
        sort(arr, arr+n);

        for(int j=1; j<n; j++)
        {
            Rank[step][arr[j].idx] = arr[j].tup[0] == arr[j-1].tup[0] &&
                                     arr[j].tup[1] == arr[j-1].tup[1] ? Rank[step][arr[j-1].idx]:j;
        }
    }

}

void build_LCP_array(void)
{
    LCP[0] = 0;
    int n = text.size(), i, j, id1, id2;

    for(i=1; i<n; i++)
    {
        id1 = arr[i-1].idx;
        id2 = arr[i].idx;
        LCP[i] = 0;

        for(j = step-1; j>=0; j--)
        {
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2])
            {
                LCP[i] += (1<<j);
                id1 += (1<<j);
                id2 += (1<<j);
            }
        }
    }

}

int main()
{
    FastRead;
    int t, x, y, res, temp, cs = 0;

    cin >> t;
    while(t--)
    {
        memset(LCP, 0, sizeof LCP);
        memset(Rank, 0, sizeof Rank);
        cin >> text;
        text += "$";
        build_suffix_array();
        build_LCP_array();

        int len = text.size();
        cin >> x >> y;
        int ans = 0;

        for(int i=1; i<len; i++)
        {
            res = len - arr[i].idx-1;

            temp = res - LCP[i];

            if(y<res) temp -= (res-y);
            if(LCP[i]<x) temp -= (x-LCP[i]-1);

            ans += max(0, temp);
        }
        cout << "Case " << ++cs << ": " << ans << endl;
    }

}
