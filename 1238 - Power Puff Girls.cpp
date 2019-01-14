#include <bits/stdc++.h>

using namespace std;
char arr[22][22];
int tarr[22][22], r,c,p ;
int dx[5] = {-1,0,0,1};
int dy[5] = {0,-1,1,0};

void bfs(int x,int y)
{
    for(int i=0; i<4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(arr[tx][ty] == 'h'){
            if(p != 0)
            {
                if(tarr[tx][ty] > tarr[x][y] + 1)
                {
                    tarr[tx][ty] = tarr[x][y] + 1;
                }
            }
            else
            tarr[tx][ty] = tarr[x][y] + 1;
            p++;
        }

        if(tx>=0 && tx<r && ty>=0 && ty<c && (arr[tx][ty] == '.' ||arr[tx][ty] == 'b'|| arr[tx][ty] == 'a' ||arr[tx][ty] == 'c') && (tarr[tx][ty] ==0||tarr[tx][ty] > tarr[x][y] +1))
        {
            tarr[tx][ty] =tarr[x][y] + 1;
            bfs(tx,ty);
        }
    }
}

int main()
{
    int i,j,k,t, fx = 0, fy = 0, cs = 0, mx, n,m;
    cin >>t;
    while(t--)
    {
        cin >> r >> c;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                cin >> arr[i][j];
            }
        }

        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(arr[i][j] == 'h')
                {
                    fx = i;
                    fy = j;
                    break;
                }
            }
        }

        mx = 0;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(arr[i][j] == 'a' || arr[i][j] == 'b' || arr[i][j] == 'c')
                {

                    memset(tarr,0, sizeof(tarr));
                    tarr[i][j] = 1;
                    p = 0;
                    bfs(i,j);
                    mx = max(mx, tarr[fx][fy]-1);
                }
            }
        }
        printf("Case %d: %d\n", ++cs, mx);
    }
}
/*1
19 19
###################
#hbc..............#
#################.#
#.......#.......#.#
#.#.#.#.#.#.#.#.#.#
#...#.......#.....#
#.#################
#.#.......#.......#
#.#.#.#.#.#.#.#.#.#
#.....#.......#...#
#################.#
#.......#.......#.#
#.#.#.#.#.#.#.#.#.#
#...#.......#.....#
#.#################
#.#.......#.......#
#.#.#.#.#.#.#.#.#.#
#.....#.......#..a#
###################*/
