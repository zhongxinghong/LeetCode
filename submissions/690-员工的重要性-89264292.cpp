/**
 * Submission ID: 89264292
 * Question ID: 690
 * Question Title: 员工的重要性
 * Question URL: https://leetcode-cn.com/problems/employee-importance/
 * Solution Time: 2020-07-19 12:00:12
 * Solution Test Result: 108 / 108
 * Solution Status: Accepted
 * Solution Memory: 14.5 MB
 * Solution Runtime: 44 ms
 */

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

    int __getImportance(const std::vector<Employee *> &employees, int id)
    {
        int ret = employees[id]->importance;
        for (int i = 0; i < employees[id]->subordinates.size(); ++i)
            ret += __getImportance(employees, employees[id]->subordinates[i]);
        return ret;
    }

    int getImportance(vector<Employee*> employees, int id)
    {
        int i = 0, n = -1;
        std::vector<Employee *> emps(2048, NULL);

        for (i < 0; i < employees.size(); ++i)
            emps[employees[i]->id] = employees[i];

        return __getImportance(emps, id);
    }
};
