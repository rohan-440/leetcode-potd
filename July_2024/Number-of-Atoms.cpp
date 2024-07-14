class Solution
{
public:
    string countOfAtoms(string formula)
    {
        stack<map<string, int>> st;
        st.push(map<string, int>());
        int i = 0;
        while (i < formula.size())
        {
            if (formula[i] == '(')
            {
                st.push(map<string, int>());
                i++;
            }
            else if (formula[i] == ')')
            {
                map<string, int> curr = st.top();
                st.pop();
                i++;
                string multiplier = "";
                while (i < formula.size() && isdigit(formula[i]))
                {
                    multiplier.push_back(formula[i]);
                    i++;
                }
                if (!multiplier.empty())
                {
                    int m = stoi(multiplier);
                    for (auto x : curr)
                    {
                        curr[x.first] = x.second * m;
                    }
                }
                for (auto x : curr)
                {
                    st.top()[x.first] += x.second;
                }
            }
            else
            {
                string currAtom = "";
                currAtom += formula[i];
                i++;
                while (i < formula.size() && islower(formula[i]))
                {
                    currAtom += formula[i];
                    i++;
                }
                string currCount;
                while (i < formula.size() && isdigit(formula[i]))
                {
                    currCount += formula[i];
                    i++;
                }
                int count = currCount.empty() ? 1 : stoi(currCount);
                st.top()[currAtom] += count;
            }
        }
        map<string, int> sortedMap(begin(st.top()), end(st.top()));
        string result;
        for (auto x : sortedMap)
        {
            result += x.first;
            if (x.second > 1)
            {
                result += to_string(x.second);
            }
        }

        return result;
    }
};