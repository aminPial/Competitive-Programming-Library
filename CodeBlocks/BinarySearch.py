# https://leetcode.com/problems/ugly-number-iii/discuss/387539/cpp-Binary-Search-with-picture-and-Binary-Search-Template
from math import gcd
lcm=lambda a,b:(a*b) // gcd(a,b)
class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        lo,hi=1,2*int(1e9)
        ab=lcm(a,b)
        bc=lcm(b,c)
        ac=lcm(a,c)
        abc=lcm(a,bc)
        while lo<hi:
            mid=(lo+hi)//2
            cnt1=sum([mid//k for k in [a,b,c,abc]])
            cnt2=sum([mid//j for j in [ab,bc,ac]])
            cnt=cnt1-cnt2
            if cnt<n:
                lo=mid+1
            else:
                hi=mid
        return lo # val of F(n) such that >=n