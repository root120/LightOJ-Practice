
#include <bits/stdc++.h>
#define ll long long int

using namespace std;
ll key = 0;

string toString(ll val)
{
    stringstream ss;
    ss << val;
    string temp;
    ss >> temp;
    return temp;
}
ll dp[32][32];

ll rec(ll rem, ll cnt)
{
    if(rem == 0) return cnt;

    ll &res = dp[rem][cnt];
    if(res != -1) return res;

    res = 0;
    for(ll i=0; i<10; i++)
    {
        if(i == key) res += rec(rem-1, cnt +1);
        else res += rec(rem-1, cnt);
    }
    return res;
}

ll calc(ll val)
{
    string str = toString(val);
    ll len = str.size();
    ll res1 = 0;

    for(ll i=1; i<len; i++)
    {
        for(ll j=1; j<10; j++)
        {
            res1 += rec(i-1, 0);
        }
    }

    for(ll i=1; i< str[0] - '0'; i++)
    {
        res1 += rec(len-1, 0);
    }

    ll cnt =1;
    if(str[0] - '0' != 0) cnt = 0;

    for(ll i=1; i<len; i++)
    {
        for(ll j=0; j<str[i]-'0'; j++)
        {
            if(key == j)res1 += rec(len-i-1, cnt+1);
            else res1 += rec(len-i-1, cnt);
        }
        if(key == str[i]-'0') cnt++;
    }
    return res1;
}

int main()
{
    ll t, a, ans, b, cs = 0;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        memset(dp, -1, sizeof(dp));
        ans = calc(b+1) - calc(a);
        if(a == 0) ans++;
        cout <<"Case " << ++cs << ": "<<  ans << endl;
    }
    return 0;
