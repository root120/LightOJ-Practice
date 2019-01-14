
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,k,m,n, temp, t, cs = 0;
    string str;

    scanf("%d", &t);
    while(t--)
    {
        deque< int> dq;
        scanf("%d%d", &n, &m);
        printf("Case %d:\n", ++cs);
        while(m--)
        {
            cin >> str;
            if(str == "pushLeft")
            {
                cin >> temp;
                if(dq.size() == n)
                {
                    cout <<"The queue is full" << endl;
                }
                else
                {

                    dq.push_front(temp);
                    cout << "Pushed in left: " << temp << endl;
                }
            }
            else if(str == "pushRight")
            {
                cin >> temp;
                if(dq.size() == n)
                {
                    cout <<"The queue is full" << endl;
                }
                else
                {

                    dq.push_back(temp);
                    cout << "Pushed in right: " << temp << endl;
                }
            }
            else if(str == "popLeft")
            {
                if(dq.size() == 0)
                {
                    cout <<"The queue is empty" << endl;
                }
                else
                {
                    temp = dq.front();
                    cout << "Popped from left: " << temp << endl;
                    dq.pop_front();
                }
            }
            else
            {
                if(dq.size() == 0)
                {
                    cout <<"The queue is empty" << endl;
                }
                else
                {
                    temp = dq.back();
                    cout << "Popped from right: " << temp << endl;
                    dq.pop_back();
                }
            }

        }
    }
}
