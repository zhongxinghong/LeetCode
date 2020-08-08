/**
 * Submission ID: 89028060
 * Question ID: 1000035
 * Question Title: 婴儿名字
 * Question URL: https://leetcode-cn.com/problems/baby-names-lcci/
 * Solution Time: 2020-07-18 16:30:33
 * Solution Test Result: 41 / 41
 * Solution Status: Accepted
 * Solution Memory: 113.8 MB
 * Solution Runtime: 1872 ms
 */

class Solution {
public:

    class disjoint_set
    {
    public:
        disjoint_set(int n)
        {
            ps = std::vector<int>(n);
            for (int i = 0; i < n; ++i)
                ps[i] = i;
        }

        int find(int x)
        {
            if (x == ps[x])
                return x;
            ps[x] = find(ps[x]);
            return ps[x];
        }

        void merge(int x, int y)
        {
            ps[find(y)] = find(x);
        }

    private:
        std::vector<int> ps;
    };

    struct name_freq_s
    {
        std::string name;
        int freq;

        name_freq_s() {}

        name_freq_s(const std::string &s)
        {
            int i;
            for (i = s.size() - 1; i > -1 && s[i] != '('; --i)
                ;

            name = s.substr(0, i);
            sscanf(&s[i + 1], "%d", &freq);
        }

        bool operator<(const name_freq_s &other)
        {
            if (name != other.name)
                return name < other.name;
            return freq < other.freq;
        }
    };

    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms)
    {
        int n = names.size(), i, j, k, sum;
        std::vector<name_freq_s> name_freqs(n);
        std::map<std::string, int> indices;
        std::string s1, s2, s;
        disjoint_set djs(n);
        std::vector<std::vector<int>> eqclz(n);
        std::vector<std::string> ret;

        for (i = 0; i < n; ++i)
            name_freqs[i] = name_freq_s(names[i]);

        std::sort(name_freqs.begin(), name_freqs.end());

        for (i = 0; i < n; ++i)
            indices[name_freqs[i].name] = i;

        for (i = 0; i < synonyms.size(); ++i)
        {
            for (k = j = 1; synonyms[i][j] != ','; ++j)
                ;

            s1 = synonyms[i].substr(k, j - k);

            for (k = ++j; synonyms[i][j] != ')'; ++j)
                ;

            s2 = synonyms[i].substr(k, j - k);

            auto it1 = indices.find(s1);
            if (it1 == indices.end())
                continue;

            auto it2 = indices.find(s2);
            if (it2 == indices.end())
                continue;

            djs.merge(it1->second, it2->second);
        }

        for (i = 0; i < n; ++i)
            eqclz[djs.find(i)].push_back(i);

        for (i = 0; i < n; ++i)
        {
            if (eqclz[i].empty())
                continue;

            for (sum = 0, j = 0; j < eqclz[i].size(); ++j)
                sum += name_freqs[eqclz[i][j]].freq;

            s = name_freqs[eqclz[i][0]].name + "(" + std::to_string(sum) + ")";
            ret.push_back(s);
        }

        return ret;
    }
};
