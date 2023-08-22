#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;

struct process{
    ll id;
    ll start;
    ll exe;
};
vector<process>vec(n);

bool comp(process a,process b)
{
    if(a.start == b.start && a.exe!=b.exe)return a.exe<b.exe;
    else if((a.start == b.start) && (a.exe == b.exe))return a.id<b.id;
    else return a.start < b.start;
}

int main() {

    //ll n,m;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        process st;
        ll I,a,t;
        cin>>I>>a>>t;
        st.id = I;
        st.start = a;
        st.exe  = t;
        vec.push_back(st);
    }

    sort(vec.begin(),vec.end(),comp);

    auto it1 = vec.begin();

    ll st  = it1[0].start+it1[0].exe;
    it1[0].exe = it1[0].start+it1[0].exe-1;
    ll idx =0;
    for(auto it = vec.begin()+1;it!=vec.end();it++)
    {
        if(it[idx].start<st)
        {
         it[idx].start = st;
         st = st+it[idx].exe;
         it[idx].exe = it[idx].start+it[idx].exe-1;
        }
        else
        {
            it[idx].exe = it[idx].start+it[idx].exe-1;

        }
    }
    auto it2= vec.end()-1;
    long long res = it2[0].exe;
    while(m--)
    {
        ll q;
        cin>>q;

        if(q<it1[0].start || res<q)
        {
            cout<<"-1"<<" ";
            continue;
        }
        ll ans = -1;
        ll lo = 0, hi = n-1;

        while(lo <= hi)
        {
            ll mid = (lo+hi)/2;
            if((vec[mid].start <= q) && (vec[mid].exe >= q))
            {
                ans = mid;
                break;
            }
            else if(vec[mid].start >= q) hi = mid-1;
            else lo = mid+1;
        }
        if(ans==-1)cout<<"-1"<<" ";
        else cout<<vec[ans].id<<" ";
    }
    return 0;
}
