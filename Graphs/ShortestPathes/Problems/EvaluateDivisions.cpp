#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void preprocessing();

void buildGraph();

void dijekstra();

int main()
{
    DPSolver;
    preprocessing();
    buildGraph();
    dijekstra();
    return 0;
}