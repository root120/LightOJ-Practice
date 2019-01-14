
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool check(ll y)
{
    if((y%4 == 0 && y%100 != 0) || (y%400 == 0))
        return true;
}

int main()
{
    ll i,j,k,m,n,cs= 0, y1, y2, y, d1, d2, t, cnt, val, h1, h2;
    string str1, str2;
    cin >> t;
    while(t--)
    {
        cin >> str1;
        scanf("%lld, %lld", &d1, &y1);
        cin >> str2;
        scanf("%lld, %lld", &d2, &y2);
        y = 0;
        cnt  = 0;

        if(check(y1))
        {
            if(str1 != "January" && str1 != "February")
            {
                y1++;
            }

        }
        y1--;

        if(check(y2))
        {
            if(str2 == "January")
            {
               y2--;
            }
            else if(str2 == "February" && d2 < 29)
            {
                y2--;
            }
            else y++;
        }

        h1=(y1/4-y1/100+y1/400);
        h2=(y2/4-y2/100+y2/400);
        cnt = h2 - h1;
        printf("Case %lld: ", ++cs);
        cout << cnt << endl;
    }
    return 0;
}

