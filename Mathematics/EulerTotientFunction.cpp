/* created by <xrssa> */
// #pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
// #pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx")  //Enable AVX
// #include <x86intrin.h> //AVX/SSE Extensions
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


// for single number O(n**0.5) square root TC
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        // divisors
        if (n % i == 0) {
            // cout << " i ___ " << i << "\n";
            while (n % i == 0){
                n /= i;
                // cout << "n becomes " << n << "\n";
            }
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// phi sieve
// Since this approach is basically identical to the Sieve of Eratosthenes, the complexity will also be the same: O(nloglogn)

void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    f(i,n+1){
        cout << i << " " << phi[i] << "\n";
    }
    //0 0
    //1 1
    //2 1
    //3 2
    //4 2
    //5 4
    //6 2
    //7 6
    //8 4
    //9 6
    //10 4
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << phi(52) << "\n"; // 4
    // phi_sieve
    phi_1_to_n(52);
    return 0;
}


