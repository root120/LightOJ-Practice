
#include <bits/stdc++.h>

using namespace std;


char str2[2000010];

int len, main_len, arr[2000010];
string str;

void MY_process()
{
    arr[0] = 0;
    int j = 0, i;
    for( i=1; i<len; i++)
    {
        if(str[i] == str[j] && j+1<=main_len)
        {
            j++;
            arr[i] = j;
        }
        else
        {
            while(j!= 0)
            {
                j = arr[j-1];
                if(str[i] == str[j] && j+1<=main_len)
                {
                    j++;
                    arr[i] = j;
                    break;
                }
            }
        }
    }
}


int main()
{
    int k, t, i, val, tc = 0, mx;
    scanf("%d", &t);

    while(t--)
    {
        str = "";
        memset(arr, 0, sizeof arr);
        memset(str2, '\0', sizeof str2);
        scanf("%s", str2);
        len = strlen(str2);
        val  = len;
        main_len = val;

        for(i=0; i<len; i++) str += str2[i];
        reverse(str.begin(), str.end());

        for(i=val-1; i>=0; i--)
        {
            str  += str[i];
        }

//        cout << str << endl;
        len = str.size();
        MY_process();
        mx = 0;
        for( i= 0; i<len; i++)
        {
//            printf("%d ", arr[i]);
            if(mx< arr[i])
            {
                mx  = arr[i];
            }
        }
//        printf("\n");

        mx = arr[len-1];
//cout << val << " len mx " << mx << endl;
        if(mx > val)
        {
            printf("Case %d: %d\n", ++tc, val);
        }
        else
            printf("Case %d: %d\n", ++tc, val+(val-mx));
    }
}
