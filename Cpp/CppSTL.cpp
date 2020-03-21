#include <bits/stdc++.h>
using namespace std;

// sort overloaded function
bool cmp(int x, int y){
    return x>y;
}
int main() {
    // stl
    vector<int> A={1,34,3,2};
    for(auto e:A) cout << e << " ";
    sort(A.begin(),A.end());
    cout << "\n";
    for(auto e:A) cout << e << " ";
    // binary search
    cout << "\n";
    bool present = binary_search(A.begin(),A.end(),39);
    cout << present << "\n"; // 0
    A.emplace_back(100);
    A.emplace_back(100);
    A.emplace_back(100);
    A.emplace_back(100);
    A.emplace_back(123);
    for(auto e:A) cout << e << " ";
    //  index of element
    // first happened
    // iterator pointer
    // first elem
    // 1 2 3 34 100 100 100 100 123
    cout << "\n";
    auto it=lower_bound(A.begin(),A.end(),5);
    cout << "it====== " << *it << "\n";
    // first element which is strictly greater than last happen
    auto it2=upper_bound(A.begin(),A.end(),100);
    cout << "\n" <<*it << " " << *it2 << "\n";
    // diff, how many same elem are there
    cout << it2 -it << "\n";

    sort(A.begin(),A.end(),cmp);

    for (auto e:A) cout << e << " ";
    cout << "\n";
    // iterate by reference to do changes
    // to change actual content of the vector
    for(auto &e:A){
        e++;
        cout << e << " ";
    }
    cout << "\n";
    for (auto e:A) cout << e << " ";
    cout << "\n";
    // Removes the element present at position.
    //Ex: v.erase(v.begin()+4); (erases the fifth element of the vector v)

    // Removes the elements in the range from start to end inclusive of the start and exclusive of the end.
    //Ex:v.erase(v.begin()+2,v.begin()+5);(erases all the elements from the third element to the fifth element.)
    A.erase(A.begin()+1,A.begin()+5);
    // upper bound A+5 means upto 4th elem
    for (auto e:A) cout << e << " ";
    cout << "\n";
    // max elem in vector
    cout << *max_element(A.begin(),A.end()) << "\n";
    // min elem in vector
    cout << *min_element(A.begin(),A.end()) << "\n";
    // if you want max/min elem within a range
    // A.begin()+2 is the upper bound here
    // like Python slice
    // [i:j] == (begin()+i, begin()+j)
    // * is because ´max_element´returns an iterator
    cout << *max_element(A.begin()+1,A.begin()+3);
    cout << "\n";


    // auto lb = lower_bound(a.begin(),a.end(),f);
    // if (*lb==f){
    //     // if same elem
    //     cout << "Yes " << lb - a.begin()+1 << "\n";
    // }
    // else{
    //     cout << "No " << lb -a.begin()+1 << "\n";
    // }


    // set
    set<int> B;





  return 0;
}
