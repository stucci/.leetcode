#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> id_employee_map;
    int sum_importance=0;
    int getImportance(vector<Employee*> employees, int id) {
        for(auto emp : employees){
            id_employee_map[emp->id] = emp;
        }
        getImportanceHelper(id);
        return sum_importance;
    }
    void getImportanceHelper(int id){
        sum_importance += id_employee_map[id]->importance;
        for(auto sub_id : id_employee_map[id]->subordinates){
            getImportanceHelper(sub_id);
        }
    }
};
// @lc code=end

