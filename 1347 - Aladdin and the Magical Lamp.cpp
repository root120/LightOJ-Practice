
#include <bits/stdc++.h>
#define FastRead ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int MAX = 16010;

struct info
{
    int tup[2], idx;

    bool operator<(const info &a) const
    {
        return tup[0] != a.tup[0] ? tup[0] < a.tup[0] : tup[1] < a.tup[1];
    }
} arr[MAX];

int Rank[18][MAX], LCP[MAX], step, len1, len2, len3;
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


int lcpBetweenIJ(int x, int y, int n) /// Taken x, y form sorted array indexes
{

    if(x == y) return n - (x +1);

    int id1, id2, j, ans;
    id1 = arr[x].idx;
    id2 = arr[y].idx;
    ans = 0;
    for(j = step-1; j>=0; j--)
    {
        if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2])
        {

            ans += (1<<j);
            id1 += (1<<j);
            id2 += (1<<j);
        }
    }
    return ans;
}

int wow(int pos)
{
    if(arr[pos].idx<=len1) return 1;
    if(arr[pos].idx<=len2+len1+1) return 2;
    return 3;
}

int main()
{
    FastRead;
    int t, x, y, res, temp, cs = 0;
    string str;
    int cnt[5];

    cin >> t;
    while(t--)
    {
        memset(LCP, 0, sizeof LCP);
        memset(Rank, 0, sizeof Rank);

        cin >> str;
        text = str + "%";
        len1 = str.size();

        cin >> str;
        text += str + "#";
        len2 = str.size();

        cin >> str;
        len3 = str.size();
        text += str + "$";



        int len = text.size();

        build_suffix_array();
        cnt[1] = cnt[2] = cnt[3] = 0;

        int ans = 0;
        int i = 0, j;
        for(j=0 ; j<len; j++)
        {

            cnt[wow(j)]++;
            while(cnt[1] && cnt[2] && cnt[3] && i<=j)
            {
                ans = max(ans, lcpBetweenIJ(i,j, len));
                cnt[wow(i)]--;
                i++;
            }

//            cout << i << " I J " << j << " " << cnt[1] << " " << cnt[2] <<" "<< cnt[3] << endl;
        }

        cout << "Case " << ++cs << ": " << ans << endl;
    }

}
