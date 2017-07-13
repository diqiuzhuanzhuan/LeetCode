//
// Created by diqiu on 2016/9/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/**
 * problem:
 * Given an array of integers, find out whether
 * there are two distinct indices i and j in the array
 * such that the difference between nums[i] and nums[j]
 * is at most t and the difference between i and j is at most k.
 */

class Solution {
public:
   int binaryFind(vector<int> &nums, int val)
   {
       int middle = nums.size() / 2;
       int end = nums.size() - 1;
       int begin = 0;
       while ( 1 ) {
           middle = (begin + end) / 2;
           if  ( nums[middle] < val ) {
               end = middle - 1;
           } else if ( nums[middle] > val ) {
               begin = middle + 1;
           } else {
               return middle;
           }
           if ( end < begin ) {
               break;
           }
       }
       return -1;
   }

    int binaryInsert(vector<int> &nums, int val)
    {
        int middle = nums.size() / 2;
        int end = nums.size() - 1;
        int begin = 0;
        while ( 1 ) {
            middle = (begin + end) / 2;
            if  ( nums[middle] < val ) {
                end = middle - 1;
            } else if ( nums[middle] > val ) {
                begin = middle + 1;
            } else {
                break;
            }
            if ( end < begin ) {
                break;
            }
        }
        nums.insert(nums.begin() + middle, val);

        return middle;
    }


    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        if ( size <= 1 || k == 0) {
            return false;
        }
        std::vector<int> subVec;
        subVec.reserve(k + 1);
        for ( int i = 0; i <= k; i++ ) {
            subVec.push_back(nums[i]);
        }
        std::sort(subVec.begin(), subVec.end());
        int minDiff = *subVec.end() - *subVec.begin();
        for ( int i = 1; i < subVec.size(); i++ ) {
            if ( minDiff > subVec[i] - subVec[i-1] ) {
                minDiff = subVec[i] - subVec[i-1];
            }
        }
        if ( minDiff <= t ) {
            return true;
        }
        for ( int i = k + 1; i < size; i++ ) {
            int eraseVal = nums[i - k - 1];
            int pos = binaryFind(subVec, eraseVal);
            subVec.erase(subVec.begin() + pos);
        }

        return false;
    }
};
