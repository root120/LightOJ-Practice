
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll i,a,b,c,val,ans = 0, t, mod, cs = 0, len;
    string str;
    cin >> t;
    while(t--)
    {
        cin >> str;
        cin >> mod;
        //cout << mod << endl;
        len  = str.size();
        ans  = 0;
        for(i = 0; i<len; i++)
        {
            if(str[i] == '-') continue;
            val = str[i] - '0';
            ans *= 10, ans += val, ans %= mod;
            //cout << ans << endl;
        }
        ans %= mod;
        printf("Case %lld: ", ++cs);
        if(ans == 0)
        {
            cout << "divisible" << endl;
        }
        else cout << "not divisible" << endl;
    }
    return 0;

}
