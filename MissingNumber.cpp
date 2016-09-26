//
// Created by diqiu on 2016/9/26.
//
#include <iostream>
#include <vector>
using namespace std;
/**
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 * For example,
 * Given nums = [0, 1, 3] return 2.
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /**
         * solution 1
         */
        /*
        int expectMax = nums.size();
        int expectMin = 0;
        int expectSum = (expectMin + expectMax) * (nums.size() + 1) / 2;
        int actualSum = 0;
        for ( int i = 0; i < nums.size(); i++ ) {
            actualSum += nums[i];
        }
        return expectSum - actualSum;
        */

        /**
         * solution 2
         */
        int actualSum = 0;
        for ( int i = 0; i < nums.size(); i++ ) {
            actualSum += i - nums[i];
        }
        return actualSum + nums.size();
    }
};