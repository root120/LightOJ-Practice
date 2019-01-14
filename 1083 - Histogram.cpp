#include <bits/stdc++.h>
#define ll long long int

using namespace std;
ll arr[30010];

int main()
{
    ll t, cs = 0, i,j,n, k;
    stack < ll> st1;
    stack < ll> st2;
    scanf("%lld", &t);
    while(t--)
    {
        while(!st1.empty())
        {
            st1.pop();
            st2.pop();
        }
        scanf("%lld", &n);
        for(i=0; i<n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        st1.push(arr[0]);
        st2.push(0);
        ll val;
        ll ans = 0, mx = 0, renge, f_val, f_renge;
        for(i=1; i<n; i++)
        {

            val = st1.top();
            if(val == arr[i]) continue;
            if(val < arr[i])
            {
                st1.push(arr[i]);
                st2.push(i);
            }
            else
            {
                renge = i;
              // cout << i << " " << st1.size() <<  endl;
                while(!st1.empty() && st1.top()>=arr[i])
                {
                    val = st1.top();
                    renge = st2.top();
                    mx = (i -renge) * val;
                    ans = max(ans,mx);
                    st1.pop();
                    st2.pop();
                }
                st1.push(arr[i]);
                st2.push(renge);
            }
        }

        f_renge = n-1;
        while(!st1.empty())
        {
            val = st1.top();
            renge = st2.top();
            mx = (f_renge - renge+1) * val;
            ans = max(ans, mx);
            st1.pop();
            st2.pop();
        }
        printf("Case %lld: %lld\n", ++cs, ans);
    }
    return 0;
}
/*1
8
12 14 1 31 19 23 31 5*/

