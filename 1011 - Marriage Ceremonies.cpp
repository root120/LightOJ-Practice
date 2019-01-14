

#include<bits//stdc++.h>
using namespace std;
int n;
int priority[20][20],dp[20][1<<15+2];

//--------------- check,set,reset funtion------------

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}

bool check(int N,int pos)
{
    return (bool) (N & (1<<pos));
}

//---------------bitmask function-------------------

int bitmask(int groom,int mask)
{
    //------------base case
    if(groom>=n)    return 0;

    //------------stop repeatation
    if(dp[groom][mask]!=-1)    return dp[groom][mask];

    //--------------
    int mx=0;
    for(int i=0;i<n;i++)
    {
        if(check(mask,i)==0)        //if this element not married before
        {
           int ans=priority[groom][i]+bitmask(groom+1,Set(mask,i));

           mx=max(mx,ans);
        }
    }
    return dp[groom][mask]=mx;
}

//------------------main function-----------------------

int main()
{
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&priority[i][j]);
            }
        }
        int ans=bitmask(0,0);
        printf("Case %d: %d\n",tt,ans);
    }
    return 0;
}
