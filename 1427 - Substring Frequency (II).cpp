
#include <bits/stdc++.h>

using namespace std;

int ss;
int ch[250010][30];
char ptrn[510][510];
int num[250010];
int f[250010];

void _init()
{
    ss = 0;
    memset(ch, 0, sizeof(ch));
    memset(num, 0, sizeof(num));
    memset(f, 0, sizeof(f));
}

void _insert(char s[])
{
    int u = 0;
    int len = strlen(s);
    for(int i=0; i<len; i++)
    {
        int c = s[i] - 'a';
        if(!ch[u][c])
            ch[u][c] = ++ss;
        u = ch[u][c];
    }
    num[u] = 0;
}

void _build_fail()
{
    queue < int > qu;
    int i;

    for(i = 0; i<26; i++)
    {
        if(ch[0][i])
            qu.push(ch[0][i]);
    }

    int r, u, v;

    while(!qu.empty())
    {
        r = qu.front();
        qu.pop();

        for(i=0; i<26; i++)
        {
            u = ch[r][i];
            if(!u) continue;

            qu.push(u);
            v = f[r];

            while(v && ch[v][i]==0)
                v = f[v];
            f[u] = ch[v][i];
        }
    }
}

void _search(char s[])
{
    int j = 0;
    int len = strlen(s);
    for(int i = 0; i<len; i++)
    {
        int c = s[i] - 'a';
        while(j && ch[j][c] == 0)
            j = f[j];
        j = ch[j][c];

        int tmp = j;
        while(tmp)
        {
            num[tmp]++;
            tmp = f[tmp];
        }
    }
}

int wow(char s[])
{
    int u = 0;
    int len = strlen(s);
    for(int i=0; i<len; i++)
    {
        int c = s[i]-'a';
        u = ch[u][c];
    }
    return num[u];
}

int main()
{
    int t, i, j, k,n, cs = 0;
    char txt[1000010];

    scanf("%d", &t);
    while(t--)
    {
        _init();

        scanf("%d", &n);
        scanf("%s", &txt);

        for(i=0; i<n; i++)
        {
            scanf("%s", &ptrn[i]);
            _insert(ptrn[i]);
        }

        _build_fail();
        _search(txt);

        printf("Case %d:\n", ++cs);

        for(i=0; i<n; i++)
        {
            int ans = wow(ptrn[i]);
            printf("%d\n",ans);
        }

    }
}
