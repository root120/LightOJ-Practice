
#include <bits/stdc++.h>
using namespace std;
int row,col,cnt;
char arr[30][30];
int dx[10] = {-1,0,0,1};
int dy[10] = {0,-1,1,0};
void gnrt_ans(int r, int c)
{
    cnt++;
    int ro,co;
    arr[r][c] = '#';
    for(int i=0; i<4; i++)
    {
        ro = r + dx[i];
        co = c + dy[i];
        if(ro>0 && ro<= row && co > 0 &&  co <= col && arr[ro][co] == '.')
        {
            gnrt_ans(ro,co);
        }
    }

}
int main()
{
    int i,j,k,tc,r,c,d = 0;
    char ch;
    cin >> tc;
    while(tc--)
    {
        cin >> col >> row;

        for(i=1; i<=row; i++)
        {
            for(j=1; j<=col; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j] == '@')
                {
                    r= i;
                    c = j;
                }
            }
        }
        cnt=0;
        gnrt_ans(r,c);
        printf("Case %d: %d\n", ++d, cnt);

    }

}
