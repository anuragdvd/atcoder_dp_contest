// D Knapsack-1 :: https://atcoder.jp/contests/dp/tasks/dp_d


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
    si(w);
    ll a[n]; ll val[n];
    fr(i,0,n)
    {
        cin>>a[i]>>val[i];
    }
    
    
    ll dp[n+1][w+1];
    fr(i,0,n+1)
        fr(j,0,w+1)
            dp[i][j]=0;
    
    for(int i=1;i<n+1;i++)
    {
        fr(j,1,w+1)
        {
            if(a[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i-1]]+val[i-1]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
  
    cout<<dp[n][w];
    
}