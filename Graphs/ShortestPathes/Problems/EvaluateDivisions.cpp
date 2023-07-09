#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void readingInput(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    int noOfEquations, noOfQueries;
    cin >> noOfEquations >> noOfQueries;
    equations = vector<vector<string>>(noOfEquations);
    queries = vector<vector<string>>(noOfQueries);
    values = vector<double>(noOfEquations);
    for (auto &vec : equations)
        cin >> vec[0] >> vec[1];
    for (auto &vec : queries)
        cin >> vec[0] >> vec[1];
    for (auto &vec : values)
        cin >> vec;
}

void removeCommonChars(vector<vector<string>> &equations)
{
    // iterate over the equations and the queries, and check if they have common char in num and den remove them.
    for (auto &eq : equations)
    {
        string first = eq[0];
        string second = eq[1];

        int len1 = eq[0].size();
        int len2 = eq[1].size();
        int mnSize = INT_MAX;
        if (len1 < len2)
        {
            // first string is shorter
            mnSize = len1;
            for (int i = 0; i < mnSize; i++)
                for (int j = 0; j < len2; j++)
                    if (first[i] == second[j])
                        first.erase(i--, 1), second.erase(j--, 1), mnSize--, len2--;
            eq[0] = first;
            eq[1] = second;
        }
        else
        {
            mnSize = len2;
            for (int i = 0; i < mnSize; i++)
                for (int j = 0; j < len1; j++)
                    if (first[j] == second[i])
                        first.erase(j--, 1), second.erase(i--, 1), mnSize--, len1--;

            eq[0] = first;
            eq[1] = second;
        }
    }
}

void preprocessing(vector<vector<string>> &equations, vector<vector<string>> &queries)
{
    removeCommonChars(equations);
    removeCommonChars(queries);
}

void buildGraph();

void dijekstra();

int main()
{
    vector<vector<string>> v = {{"abc", "bc"}, {"xyz", "zzzzz"}};
    removeCommonChars(v);
    for (auto c : v)
        cout << c[0] << " ---- " << c[1];
}
// int main()
// {
//     DPSolver;
//     vector<vector<string>> equations;
//     vector<double> values;
//     vector<vector<string>> queries;
//     readingInput(equations, values, queries);
//     preprocessing(equations, queries);
//     buildGraph();
//     dijekstra();
//     return 0;
// }