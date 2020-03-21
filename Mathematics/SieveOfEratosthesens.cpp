#include <bits/stdc++.h>
using namespace std;

bool check(int N, int pos){ return (bool) (N & (1<<pos));}
int Set(int N, int pos) { return N | (1<<pos);}

// const int N=1000000+5; // upto N range, prime numbers, change
// int status[N<<5];
//
//
// void sieve(){
//    int sqrt_N=int(sqrt(N));
//    for(int i=3;i<=sqrt_N;i+=2){
//        // +=2 for escaping even numbers
//        // we check upto sqrt(N)
//        if (check(status[i>>5],i&31)==0) {
//            // status[idx]==0 then we chop i*i ->...
//            // i%32 th bit of [i/32]th index
//            for (int j = i * i; j <= N; j += i<<1) // i << 1==2*i
//            {
//                // status[j/32]=Set(status[j/32], j%32);
//                status[j>>5]=Set(status[j>>5], j&31);
//            }
//        }
//    }

    // puts("2");
    // for(int i=3;i<=N;i+=2)
    //     if( check(status[i/32],i%32)==0)
    //         cout << i << "\n";
// }

const int N = 1000000;
bool stat[N+5];
void siv()
{
    int sq = sqrt(N);for(int i =4;i<=N;i+=2)stat[i]=1;
    for(int i=3;i<=sq;i+=2)if(!stat[i])for(int j=i*i;j<=N;j+=2*i)stat[j]=1;
    stat[1]=1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    siv();

    int q;cin>>q;
    while(q--) {
        int n;
        cin >> n;
        if(stat[n]==0) cout << n << " is a prime number." << "\n";
        else cout << n << " is not a prime number." << "\n";
    }

    return 0;

}

/*
 // normal sieve
 bool status[1100002];
void siv()
{
	int N=1000000;
	int sq=sqrt(N);
	for(int i=4;i<=N;i+=2) status[i]=1;
	for(int i=3;i<=sq;i+=2){
		if(status[i]==0)
		{
			for(int j=i*i;j<=N;j+=i) status[j]=1;
		}
	}
	status[1]=1;

}


 */