// Problem H - Grid 1 :: https://atcoder.jp/contests/dp/tasks/dp_h

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
    si(h); si(w);
    char ch[h+1][w+1]; fr(i,1,h+1) { fr(j,1,w+1) cin>>ch[i][j]; }
    ll dp[h+1][w+1];
    
    bool flag=false;
    
    for(int i=w;i>=1;i--)
    {
        if(ch[h][i]=='#')   flag=true;
        if(flag)    dp[h][i]=0;
        else    dp[h][i]=1;
    }
    
    flag=false;
    
    for(int i=h;i>=1;i--)
    {
        if(ch[i][w]=='#')   flag=true;
        if(flag)    dp[i][w]=0;
        else    dp[i][w]=1;
    }
    
    for(int i=h-1;i>=1;i--)
    {
        for(int j=w-1;j>=1;j--)
        {
            if(ch[i][j]=='#')   dp[i][j]=0;
            else
                dp[i][j]=(dp[i][j+1]%M+dp[i+1][j]%M)%M;
        }
    }
    
    /*fr(i,0,h+1)
    {
        fr(j,0,w+1)
            cout<<dp[i][j]<<" ";
        nl;
    }*/
    
    cout<<dp[1][1];
}