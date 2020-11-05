#ifndef C935_H
#define C935_H
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /**
    * @param setList: The input set list
    * @return: the cartesian product of the set list
    */
    vector<vector<int>> getSet(vector<vector<int>> &setList) {
        // Write your code here
        vector<vector<int>> res;//存放最终结果
        vector<vector<int>> temp;//存放中间结果
        for (auto c : setList[0])
            res.push_back({ c });
        //对于setList[i],此时的结果为res,笛卡尔积为res中的每个数组分别添加setList[i]的每个元素
        for (int i = 1; i < setList.size(); ++i)
        {
            for (auto c : res)
            {
                for (auto t: setList[i])
                {
                    vector<int> v = c;
                    v.push_back(t);
                    temp.push_back(v);
                }
            }
            res = temp;
            temp.clear();
        }
        return res;
    }
};
#endif