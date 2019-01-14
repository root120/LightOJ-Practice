
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

 ll  dv[1010];

struct str{
    int ind, val;
} arr[1010];

bool cmp(str x, str y)
{
    if( x.val == y.val && x.ind > y.ind) return true;
    if(x.val < y.val) return true;
    return false;
}

void divisor()
{
    int i,j,k;

    for(i=1; i<= 1005; i++)
    {
        for(j=1; j<=sqrt(i); j++)
        {
            if(i%j==0)
            dv[i] += 2;
            if(j*j == i) dv[i] -= 1;
        }
    }
}

int main()
{
    divisor();
    for(int i=0; i<1005; i++)
    {
        arr[i].ind = i;
        arr[i].val = dv[i];
    }

    sort(&arr[0], &arr[1001], cmp);

    ll t,temp,i, cs = 1;
    cin >> t;
    while(t--)
    {
        cin >> temp;
        printf("Case %d: ", cs++);
        cout << arr[temp].ind<< endl;
    }
}

