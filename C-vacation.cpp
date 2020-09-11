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
    ll a[n]; ll b[n]; ll c[n];
    fr(i,0,n)   cin>>a[i]>>b[i]>>c[i];
    ll dp[n][3];
    dp[0][0]=a[0]; dp[0][1]=b[0]; dp[0][2]=c[0]; // this is the base case 
    
    // now the recurrence relation is dp[i][0]=a[i]+max(dp[i-1][2],dp[i-1][1])   for a and similarly for other values
    
    fr(i,1,n)
    {
        dp[i][0]=a[i]+max(dp[i-1][2],dp[i-1][1]);
        dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=c[i]+max(dp[i-1][0],dp[i-1][1]);
    }
    --n;
    ll ans=max(dp[n][0],dp[n][1]);
    cout<<max(dp[n][2],ans);
}
