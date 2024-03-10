#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using ll = long long;
using namespace std;
#pragma GCC optimize("O3", "unroll-loops")

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end()) ;
    sort(nums2.begin(), nums2.end()) ;

    vector<int> res ; 
    int lastInsertedElement = -1;

    int nums1Ptr = 0; 
    int nums2Ptr = 0; 
    int sz1 = nums1.size(); 
    int sz2 = nums2.size(); 
    int nums1Ptr = 0; 
    int nums2Ptr = 0; 

    while (nums1Ptr < sz1 && nums2Ptr < sz2) { 
        
        if (nums1[nums1Ptr] == nums2[nums2Ptr] && nums1[nums1Ptr] != lastInsertedElement){ 
            lastInsertedElement = nums1[nums1Ptr]; 
            res.push_back(nums1[nums1Ptr]); 
        }
        if(nums1[nums1Ptr] < nums2[nums2Ptr])
            nums1Ptr ++; 
        else if (nums1[nums1Ptr] > nums2[nums2Ptr])
            nums2Ptr ++; 
        else {
            nums1Ptr ++; 
            nums2Ptr ++; 

        }

        if (lastInsertedElement == nums1[nums1Ptr]) 
            nums1Ptr++;
        
        if (lastInsertedElement == nums2[nums2Ptr]) 
            nums2Ptr++;
        
    }
    return res; 
}

int main()
{
}