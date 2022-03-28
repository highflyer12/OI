#include <iostream>
#include <cstdio>
#include "vector"

using namespace std;

int solve(vector<int> intVect,int targetSum){
    if(targetSum==0) return true;
    if(targetSum!=0&&intVect.empty()) return false;
    int back = intVect.back();
    intVect.pop_back();
    bool result1 = false,result2 = false;
    if(back <=targetSum){
        result1 = solve(intVect,targetSum-back);
    }
    result2 = solve(intVect,targetSum);
    return result1||result2;
}


int main() {
    int n,a,k;
    vector<int> intVect;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        intVect.push_back(a);
    }
    scanf("%d",&k);
    bool result = solve(intVect,k);
    cout<<result<<endl;
    return 0;
}
