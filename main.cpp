#include "P30_targetSum.h"


int main() {
    int n,a,k;
    vector<int> intVect;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        intVect.push_back(a);
    }
    scanf("%d",&k);
//    bool result = solve(intVect,k);
    bool result = solve2(intVect,0,0,k);
    cout<<result<<endl;
    return 0;
}
