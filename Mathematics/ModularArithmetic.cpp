/* created by <xrssa> */
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline","fast-math","no-stack-protector") //Optimization flags
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#include <x86intrin.h> //AVX/SSE Extensions

#include <bits/stdc++.h>
using namespace std;

// (A*B) % p
uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m)
{
   long double x;
   uint64_t c;
   int64_t r;
   if (a >= m) a %= m;
   if (b >= m) b %= m;
   x = a;
   c = x * b / m;
   r = (int64_t)(a * b - c * m) % (int64_t)m;
   return r < 0 ? r + m : r;
}

// (A**B) % p
uint64_t pow_mod(uint64_t a, uint64_t b, uint64_t m)
{
    uint64_t r = m==1?0:1;
    while (b > 0) {
        if (b & 1)
            r = mul_mod(r, a, m);
        b = b >> 1;
        a = mul_mod(a, a, m);
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}
