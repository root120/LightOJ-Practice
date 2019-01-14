
 /****************#####    بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم   #####******************
__________________________________________________________________________
######################     Foysol Ahmed Shuvo    #########################
######################        MU-CSE-35C        #########################
*************************************************************************/

#include <bits/stdc++.h>
#define ll long long int
#define M 1000003

using namespace std;

ll fac[M];

void factorial()
{
    fac[0] = 1;
    for(int i = 1; i<M; i++)
    {
        fac[i] = fac[i-1] * i;
        fac[i] %= M;
    }
}

ll FindInverse(ll q,ll pow)
{
    if(pow == 0) return 1;
    else if(pow %2 == 1){
        ll stp1 = q %M;
        ll stp2 = FindInverse(q, pow-1) % M;
        return((stp1%M * stp2%M)%M);
    }
    else if(pow %2 == 0)
    {
        ll stp3 = FindInverse(q, pow/2) % M;
        return (stp3%M * stp3%M)%M;
    }
}

int main()
{
    factorial();
    ll t, i, j, n, k, cs = 0, p, q;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        p = fac[n];
        q = (fac[n-k]* fac[k]) %M;
        j = FindInverse(q, M-2);
        q = (p%M * j%M) %M;
        printf("Case %lld: ", ++cs);
        cout << q << endl;
    }
    return 0;
}
