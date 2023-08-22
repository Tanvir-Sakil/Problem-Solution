#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> prefixFunction(string s) {
    vector<int> p(s.size());
    int j = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        while (j > 0 && s[j] != s[i])
            j = p[j-1];

        if (s[j] == s[i])
            j++;
        p[i] = j;
    }
    return p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll testCase;
    cin>>testCase;

    while(testCase--)
    {
        ll n;
        cin>>n;
        ll sum=0;
        string s;
        cin>>s;
        vector<int>vec;
        vec = prefixFunction(s);

        for(auto it : vec )
        {
            sum +=it;
        }
        cout<<sum<<endl;
    }
}
