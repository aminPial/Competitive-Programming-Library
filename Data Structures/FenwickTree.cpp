
#include <bits/stdc++.h>
using namespace std;

#define mx 10000 // depends on arr size
int arr[mx];
int tree[mx];

int base_query(int idx){
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int range_query(int i, int j){
    // j is exluded and upto j-1 (i,j-1)
    // though fenwick tree only can return sum of range (1,j)
    // but we can modify that using 2 query ops
    // i->j == 1->j - 1->i
    return base_query(j) - base_query(i); // logn + logn = 2logn
}

void update(int idx, int val, int A_size__){
    while(idx<=A_size__){
        tree[idx]+=val;
        idx += (idx & -idx);
    }
}

// util
void print(int *ar, int n){
    cout << "[" << "";
    for(int i=0; i <n;i++){
        cout << ar[i] << " ";
    }
    cout << "]"<<"\n";
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >>n;
    for (int i = 1; i <= n; ++i) { cin >> arr[i]; update(i, arr[i], n); }

    cout << "input array:\t";
    print(arr, n);
    cout << "\n";

    cout << "tree array:\t";
    print(tree, n);
    cout << "\n";
    cout << base_query(3) << "\n";
    cout << range_query(1, 4) << "\n";

    return 0;

	
}
