/* created by <xrssa> */
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline","fast-math","no-stack-protector") //Optimization flags
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#include <x86intrin.h> //AVX/SSE Extensions

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<b;i++)
#define fa(elem, arr) for(auto &elem:arr)
#define gcd(x,y)         __gcd(x,y)
#define lcm(x,y)        (x/gcd(x,y))*y
#define mod             1000000007
#define all(a)           a.begin(),a.end()
#define INF 1e9 // # define INF 0x3f3f3f3f 
#define EPS 1e-6

/*
int dp[31], n;
memset(dp, 0, sizeof(dp));
dp[0]=1;
dp[2]=3;
*/

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif



void solve(){
   
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    // for multiple test case use
    // int t;cin>>t;while(t--) solve();
    return 0;
}
