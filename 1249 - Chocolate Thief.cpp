
#include <bits/stdc++.h>

using namespace std;

struct str{
    string s;
    int x,y,z;
} arr[110];
bool cmp(str a, str b)
{
    return a.x * a.y * a.z > b.x * b.y * b.z ? 1:0;
}

int main()
{
    int i,j,k,m,n,t, cs = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0; i<n; i++)
        {
            cin >> arr[i].s;
            cin >> arr[i].x >> arr[i].y >> arr[i].z;
        }
        sort(&arr[0], &arr[n], cmp);
        printf("Case %d: ", cs++);
        if(arr[0].x*arr[0].y*arr[0].z == arr[n-1].x*arr[n-1].y*arr[n-1].z)
        {
            cout << "no thief"<< endl;
        }
        else cout << arr[0].s<<" took chocolate from "<< arr[n-1].s<< endl;
    }

}
