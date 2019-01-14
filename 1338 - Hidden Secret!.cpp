
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,i,j,k, cs = 0;
    char ch;
    int arr1[300], arr2[300];
    string str1, str2;
    cin >> t;
    getchar();
    while(t--)
    {
        str1.clear();
        str2.clear();
        memset(arr1, 0, sizeof(arr1));
        memset(arr2, 0, sizeof(arr2));
        getline(cin, str1);
        getline(cin, str2);
        //cout << str1 << endl<<endl<< str2 << endl;
        for(i =0; i<str1.size(); i++)
        {
            ch = tolower(str1[i]);
            arr1[ch]++;
        }
        for(i =0; i<str2.size(); i++)
        {
            ch = tolower(str2[i]);
            arr2[ch]++;
        }
        k = 0;
        for(i='a';i<='z'; i++)
        {
            if(arr1[i] != arr2[i])
            {
                k = 1;
            }
        }
        if(k==0) printf("Case %d: Yes\n", ++cs);
        else
        printf("Case %d: No\n", ++cs);
    }
}
