// F-LCS :: https://atcoder.jp/contests/dp/tasks/dp_f

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
    string s; cin>>s; 
    string t; cin>>t;
    int n=s.length();
    int m=t.length();
    ll dp[n+1][m+1];
    fr(i,0,n+1)
    {
        fr(j,0,m+1)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    string ans="";
   
    ll i=n,j=m;
    while(i!=0&&j!=0)
    {
        if(s[i-1]==t[j-1])
        {
            ans+=s[i-1];
            i--; j--;
        }
        else if(dp[i][j-1]>=dp[i-1][j])
        {
            j--;
        }
        else 
        {
            i--;
        }
    }
    
    
    reverse(ans.begin(),ans.end());
    
    cout<<ans;
}
