//
// Created by fly high on 2022/3/28.
//

#ifndef OI_P30_TARGETSUM_H
#define OI_P30_TARGETSUM_H

#include <iostream>
#include <cstdio>
#include "vector"

using namespace std;

/*
 * 我的解法：递归思路是从后往回退，强调利用好每层递归的结果----优点是在树、图等数据结构中很好用；缺点是在知道全局答案后无法实现快速退出全部递归。
 */
bool solve(vector<int> intVect,int targetSum){
    if(targetSum==0) return true;
    if(targetSum!=0 && intVect.empty()) return false;
    int back = intVect.back();
    intVect.pop_back();
    bool result1 = false,result2 = false;
    if(back <=targetSum){
        result1 = solve(intVect,targetSum-back);
    }
    result2 = solve(intVect,targetSum);
    return result1||result2;
}

/*
 * 书上的解法：递归思路是状态迭代（把状态反映在参数上，每层递归返回的结果没那么重要）
 */
bool solve2(vector<int> intVect,int index,int pSum,int target){
    //Base 情况
    if(index == intVect.size()) return pSum==target;//程序沿着某条路径搜索完了所有的数据,考察当前Sum是否==target；
    //两条分支：选或不选
    if(solve2(intVect,index+1,pSum+intVect[index],target)) return true;
    if(solve2(intVect,index+1,pSum,target)) return true;
    return false;
}

#endif //OI_P30_TARGETSUM_H
