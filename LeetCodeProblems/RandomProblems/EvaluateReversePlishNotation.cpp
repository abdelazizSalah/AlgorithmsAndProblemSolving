#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main()
{
    DPSolver;
    // vector<string> tokens = {"2", "1", "+", "3", "*"};
    // vector<string> tokens = {"4", "13", "5", "/", "+"};
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    stack<int> numbers;
    for (string tok : tokens)
    {
        if (isdigit(tok[0]) || (tok.size() > 1 && isdigit(tok[1])))
            numbers.push(stoi(tok));
        else
        {
            // this is an operation
            int second_operand = numbers.top();
            numbers.pop();
            int first_operand = numbers.top();
            numbers.pop();
            if (tok == "+")
                numbers.push(first_operand + second_operand);
            else if (tok == "-")
                numbers.push(first_operand - second_operand);
            else if (tok == "/")
                numbers.push(first_operand / second_operand);
            else if (tok == "*")
                numbers.push(first_operand * second_operand);
        }
    }
    cout << numbers.top();
    return 0;
}