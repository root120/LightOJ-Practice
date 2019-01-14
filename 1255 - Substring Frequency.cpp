
#include <bits/stdc++.h>
#define ll long long
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

string str1, str2;

ll a[1000010], len1, len2;

void process()
{
    ll  i, j = 0;
    a[0] =  0;
    for(i=1; i<len1; i++)
    {
        // cout << i << endl;
        if(str2[i] == str2[j])
        {
            j++;
            a[i] = j;
        }
        else
        {
            while(j != 0)
            {
                // cout << "j " << j << endl;
                j = a[j-1];
                if(str2[j] == str2[i])
                {
                    j++;
                    a[i] = j;
                    break;
                }
            }
        }
    }
}
ll MY_check(ll cnt)
{
    ll j = 0, p = 0;
    for(ll i=0; i<len1; i++)
    {
        if(str1[i] == str2[j])
        {
            //p++;
            j++;
            if(j == len2)
            {
                cnt++;
            }
        }
        else
        {
            while(j!=0)
            {
                j = a[j-1];
                if(str1[i] == str2[j])
                {
                    j++;
                    break;
                }
            }
        }
    }
    return cnt;
}

ll Check()
{
    ll  i, j = 0, cnt = 0;

    for(i=0; i<len1; i++)
    {
        if(str1[i] == str2[j])
        {
            j++;
            if(j == len2)
            {
                cnt++;
            }
        }
        else
        {
            while(j != 0)
            {
                j = a[j-1];
                if(str1[i] == str2[j])
                {
                    j++;
                    if(j == len2)
                    {
                        cnt++;
                    }
                    break;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    FastRead;
    ll t, i, j, k, cs = 0;
    cin >> t;
    while(t--)
    {
        // cout << t <<endl;
        memset(a, 0, sizeof a);

        cin >> str1;
        cin >> str2;


        len1 = str1.size();
        len2 = str2.size();

        process();

    ll ans = Check();
      //  ll ans = MY_check(0);

        ++cs;
        cout << "Case "<< cs<<": " << ans << endl;;
    }
}

