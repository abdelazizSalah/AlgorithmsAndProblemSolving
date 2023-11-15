# 2 Methods | Using Built in function | Using Tabulation approch | C++ solution
![image.png](https://assets.leetcode.com/users/images/a47795b1-3c5f-4df0-ad0b-ee826d2b9c18_1699853830.4195557.png)

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
* All we need to do is to count the number of ones in each number from 0 to the given n. 
* The naive approch is to just convert each number into string of bits, and iterate over its bits, and start counting the **set** bits.
* but this is not efficient.
* so instead we can go to use the built in function which do this job, or we can use our manual technique using DP.  
# Approach
<!-- Describe your approach to solving the problem. -->
* I have solved the problem using two approches.
## 1. Using built in method __builtin_popcount.
* __builtin_popcount is a built in method, which takes an integer k, and returns the number of set bits. [Read more about it.](https://www.geeksforgeeks.org/cpp-__builtin_popcount-function/)
* So all we need is to define a vector of size n + 1. 
* start iterating from i = 0 to n+1 (exit when i > n).
    1. assign v[i] = __builtin_popcount(i)
* return v.
* but acctually this logic takes a lot of time, and it do a lot of redundant calculations.
* so I went to the DP tabulation solution. 

## 2. Tabulation solution.  
![image.png](https://assets.leetcode.com/users/images/a3f2f40e-53fa-4f98-bb46-c3b06e99e9ba_1699853885.7755206.png)

![image.png](https://assets.leetcode.com/users/images/199493c9-6496-447f-b4bd-6512a4eeac23_1699853910.0915344.png)

* by tracing the sequence
    * 0 -> 000000000
    * 1 -> 000000001
    * 2 -> 000000010
    * 3 -> 2 + 1 -> 000000011
    * 4 -> 000000100
    * 5 -> 4 + 1 -> 000000101
    * 6 -> 4 + 2 -> 000000110
    * 7 -> 4 + 3 -> 000000111
    * 8 -> 8  -> 000001000
    * 9 -> 8 + 1 -> 000001001
    * 10 -> 8 + 2 -> 000001010
    * 11 -> 8 + 3 -> 000001011
    * 12 -> 8 + 4 -> 000001100

* So from that we can conclude that we can use the previously computed results, and just increment what we got previously to compute the new results. 
* and we should set v[2^i] = 1 = v[2] = v[4] = v[8] ....
- so.
1. base cases for this is when 
    1. i = 0 return {0}     
    1. i = 1 return {0,1}     
    1. i = 2 return {0,1,1}     
2. create a vector of size n + 1.
3. insert seeds.
    1. v[0] = 0.
    2. v[1] = 1.
    3. v[2] = 1.
4. we need to keep tracking of the last power of 2 and the next power of 2.
5. so initialize a power variable with value = 2. 
6. the first power we have is 2^1, and we should start from 1 again when i = 2^ power + 1, which is 2^2 here, so we should define **nextStop** at 2^power.
7. and this power value will get incremented at each station of 2^x, so when i == 4 we should increment it, and same when i == 8, == 16 and so on...
8. then we need to iterate from 3 to n + 1.
    1. if i == nextStop (2 ^ x)  
        1. we should set v[i] = 1
        2. the previousPower should be equal to the previous stop
        3. then we need to increment the previous power by one.
        4. then set the next stop to 2^power.
    5. else
        1. the current value = v[lastPower] + v[i - lastPower]
        2. ie: v[3] = v[2] + v[1]
        3. ie: v[10] = v[8] + v[10 - 8]
        4. ie: v[17] = v[16] + v[17 - 16] and so on. 
9. now we are finished, so just return the vector v.   

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
1. For the tabulation approch, we just need one iteration to solve the problem, so it is O(n). 
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
1. O(n) which is needed for the vector in which we store the results.
# Code
```
class Solution {
public:

    #define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // using DP and tabulation method.
    vector<int> countBits(int n)
    {
        DPSolver;
        /// base cases (all the seeds are base cases).
        if(n == 0) 
            return {0}; 
        if (n == 1)
            return {0,1};
        if (n == 2)
            return {0,1,1};
        vector<int> v(n + 1);
        int power = 2;
        v[0] = 0;
        v[1] = v[2] = 1;
        long powersOfTwo = pow(2, power - 1);
        double nextStop = pow(2, power);
        for (int i = 3; i <= n; i++)
            if (i == nextStop)
            {
                v[i] = 1;
                powersOfTwo = nextStop;
                nextStop = pow(2, ++power);
            }
            else
                v[i] = v[powersOfTwo] + v[i - powersOfTwo];

        return v;
    } 
    //! using the built in method
    vector<int> countBitsUsingBuiltInFunction(int n)
        {
            DPSolver;
            
            vector<int> v(n + 1);
            //! using built in function which counts the number of set bits.
            for (int i = 0; i <= n; i++)
                v[i] = __builtin_popcount(i);
            return v;
        }

    
};
```