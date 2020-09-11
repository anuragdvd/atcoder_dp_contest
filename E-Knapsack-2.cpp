// Knapsack-2 :: https://atcoder.jp/contests/dp/tasks/dp_e

#include<bits/stdc++.h>
#define fr(i,c,b) for(int i=c;i<b;i++)
#define frl(i,c,b) for(ll i=c;i<b;i++)
#define si(x) int x; scanf("%d", &x)
#define sll(x) ll x; scanf("%lld", &x)
#define pi(x) printf("%d", x)
#define pll(x) printf("%lld", x)
#define nl printf("\n")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define MAX 100001
#define M 1000000007
#define pb push_back
#define INF 100000001
 
typedef long long int ll;
 
 
using namespace std;
 

ll dp[100010+1]; 

int main()
{
    sll(n);
    sll(w);
    ll a[n]; ll val[n];
    ll sum=0;
    fr(i,0,n)
    {
        cin>>a[i]>>val[i];
        sum+=val[i];
    }
    memset(dp,INF,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=sum;j>=val[i-1];j--)
        {
            dp[j]=min(dp[j],dp[j-val[i-1]]+a[i-1]);    
        }
    }
    
    ll ans=0;
    for(int i=sum;i>=0;i--)
    {
        
        if(dp[i]<=w)
        {
            ans=i; break;
        }
    }
    cout<<ans;
 
}
