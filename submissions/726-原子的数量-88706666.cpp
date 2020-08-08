/**
 * Submission ID: 88706666
 * Question ID: 726
 * Question Title: 原子的数量
 * Question URL: https://leetcode-cn.com/problems/number-of-atoms/
 * Solution Time: 2020-07-17 16:24:57
 * Solution Test Result: 28 / 28
 * Solution Status: Accepted
 * Solution Memory: 7.7 MB
 * Solution Runtime: 12 ms
 */

class Solution {
public:

    struct CharWithPos
    {
        char ch;
        int pos;
    };

    std::map<std::string, int> __countOfAtoms(const std::string &formula, int i, int j)
    {
        int cnt, k;
        std::string atom;
        std::map<std::string, int> ret;
        std::stack<CharWithPos> st;

        while (i < j)
        {
            if (formula[i] == '(')
            {
                st.push({formula[i], i});
                i++;

                if (!atom.empty())
                {
                    ret[atom]++;
                    atom.clear();
                }
            }
            else if (formula[i] == ')')
            {
                k = st.top().pos + 1;
                st.pop();

                auto mp = __countOfAtoms(formula, k, i);

                if (i != j - 1 && isdigit(formula[i + 1]))
                    sscanf(&formula[i + 1], "%d", &cnt);
                else
                    cnt = 1;

                for (i = i + 1; i < j && isdigit(formula[i]); ++i)
                    ;

                for (auto it = mp.begin(); it != mp.end(); ++it)
                    ret[it->first] += it->second * (cnt - 1);
            }
            else if (isupper(formula[i]))
            {
                k = i++;

                for (; i < j && islower(formula[i]); ++i)
                    ;

                if (!atom.empty())
                    ret[atom]++;

                atom = formula.substr(k, i - k);
            }
            else if (isdigit(formula[i]))
            {
                sscanf(&formula[i], "%d", &cnt);

                for (; i < j && isdigit(formula[i]); ++i)
                    ;

                ret[atom] += cnt;
                atom.clear();
            }
        }

        if (!atom.empty())
            ret[atom]++;

        return ret;
    }

    string countOfAtoms(string formula) {
        std::string ret;

        if (formula.empty())
            return ret;

        auto mp = __countOfAtoms(formula, 0, formula.size());
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            ret += it->first;
            if (it->second > 1)
                ret += std::to_string(it->second);
        }

        return ret;
    }
};
