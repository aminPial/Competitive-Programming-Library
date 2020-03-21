/* created by <xrssa> */
// #pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
// #pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx")  //Enable AVX
// #include <x86intrin.h> //AVX/SSE Extensions
// Area of different geometric shapes
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


void convex_polygon(){
    int n;cin>>n; pair<int,int> arr[n+1];
    f(i,n){
        int x,y;
        cin>>x>>y;
        arr[i]={x,y};
    }
    arr[n]={arr[0].first, arr[0].second}; // adding first apir again
    double area=0.0;
    f(i,n){
        area+=arr[i].first*arr[i+1].second;
        area-=arr[i].second*arr[i+1].first;
    }
    cout << 0.5 * area << "\n";

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
