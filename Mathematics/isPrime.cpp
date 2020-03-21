
#include <bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if(n<=1) return false;
    else if(n<=3) return true;
    else if(n%2==0 || n%3==0) return false;
    int i=5;
    while (i*i<=n){
        if (n%i==0 or n%(i+2)==0) return false;
        i+=6;
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=1;i<1000;i++)
    cout << i << " " << isprime(i) <<"\n";    

    return 0;

	
}
