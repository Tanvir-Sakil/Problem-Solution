#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    LL testCase;
    cin>>testCase;
    LL cont =0;
    while(testCase--)
    {
        cont++;
        LL n,q;

        cin>>n>>q;
        LL arr[n],dp[n];

        memset(dp,0,sizeof(dp));
        memset(arr,0,sizeof(arr));

        while(q--)
        {
            LL l,r,x;
            cin>>l>>r>>x;
            dp[l-1]+=x;
            dp[r]-=x;
        }
        for(LL i=0; i<n; i++)
        {
            if(i==0)
            {
                arr[i]=dp[i];
            }
            else
            {
                arr[i] = dp[i]+arr[i-1];
            }
        }
        cout<<"Case "<<cont<<": ";
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
