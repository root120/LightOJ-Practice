
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str[105];
    char s[100];
    int i,j,k,l,tc,n,b = 0;
    cin >> tc;
    while(tc--)
    {
        printf("Case %d:\n", ++b);
        i = 0, l = 0;
        str[l] = "http://www.lightoj.com/";
        while(scanf("%s", &s)==1)
        {
            if(strcmp(s,"QUIT") == 0) break;
            else if(strcmp(s,"VISIT") == 0)
            {
                cin >> s;
                cout << s << endl;
                str[++i] = s;
                l = i;
            }
            else if(strcmp(s,"BACK") == 0)
            {
                if(i-1<0) printf("Ignored\n");
                else
                {
                    cout << str[--i] <<endl;

                }

            }
            else
            {
                if(i+1 > l) printf("Ignored\n");
                else
                {
                    cout << str[++i] << endl;
                }
            }
        }
    }
}
