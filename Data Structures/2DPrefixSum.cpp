#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<b;i++)

#define N 1000+1 // for N x N Prefix2D matrix
// global always
int T[N][N]={0}; // init as we need first row and col to be 0
// actual values from the input
int matrix[N][N]; // this doesn't need to be initialized

void prefix2D(){

/* 
    # col +1 and row + 1 because of the padding
    # doing prefix sum
    # Formula: T[i][j] = T[i-1][j] + T[i][j-1] + matrix[i][j] - T[i-1][j-1]
    # we subtract the common extra diagonal element == T[i-1][j-1]
    # matrix[i-1][j-1] is actually [i][j] as we pad the elem by +1


*/

    int row= sizeof(matrix);
    int col=sizeof(matrix[0]);
    fab(i,1,row+1){
        fab(j,1,col+1){
            T[i][j]=T[i-1][j]+T[i][j-1]+matrix[i-1][j-1]-T[i-1][j-1];
        }
    }
}

int pref2DQuery(int i1, int j1, int i2, int j2){
    i1++;i2++;j1++;j2++;
    return T[i1][j1]-T[i1-1][j2]-T[i2][j1-1]+T[i1-1][j1-1];
}


void prefix1D(vector<int> arr){
    fab(i,1,arr.size()){
        arr[i]+=arr[i-1]; // arr[i]=arr[i] operator arr[i-1]
    }
    for(auto e:arr) cout << e << " ";
    // to query in range i,j
    // sum(i,j) = prefix[j] - (prefix[i-1] if i>0 else 0)
    cout << arr[3]-arr[1] << "\n";
    // vector<int> arr={1,2,3,4};
    // 1 3 6 10
    // arr[3]-arr[1] == arr[4(1th base)] + arr[3(1th base)]
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr={1,2,3,4};
    prefix1D(arr);


    return 0;
}

/* 
#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<b;i++)
#define N 1000+1 // for N x N Prefix2D matrix
// global always
int T[N][N]={0}; // init as we need first row and col to be 0
int matrix[N][N]={0}; // this doesn't need to be initialized

void prefix2D(int r,int c){
    fab(i,1,r+1){
        fab(j,1,c+1){
            T[i][j]=T[i-1][j]+T[i][j-1]+matrix[i-1][j-1]-T[i-1][j-1];
        }
    }
}
int pref2DQuery(int i1, int j1, int i2, int j2){
    i1++;i2++;j1++;j2++;
    return T[i1][j1]-T[i1-1][j2]-T[i2][j1-1]+T[i1-1][j1-1];
}
int main()
{
    ios::sync_with_stdio(false);
    int q;cin>>q;while(q--){
        int n,query;cin>>n>>query;
        f(i,n)f(j,n) cin>>matrix[i][j];
        prefix2D(n,n); // init pref2D ops
        f(v,query){
            int a,b,s;cin>>a>>b>>s;
            cout << pref2DQuery(a-1,b-1,a+s-1,a+s-1) << "\n";
        }
        // cout 2d array
        f(m,n+1) {
            f(v, n+1) {
                cout << T[m][v] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}


*/