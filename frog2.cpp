// Frog 2 :: https://atcoder.jp/contests/dp/tasks/dp_b

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

typedef long long int ll;

using namespace std;

int main()
{
    si(n);
    si(k);
    ll a[n+1];
    fr(i,1,n+1)   cin>>a[i];
    ll dp[n+1];
    dp[1]=0;
    dp[2]=abs(a[2]-a[1]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(j<i)
                dp[i]=min(dp[i-j]+abs(a[i-j]-a[i]),dp[i]);
        }
    }
    cout<<dp[n];
}