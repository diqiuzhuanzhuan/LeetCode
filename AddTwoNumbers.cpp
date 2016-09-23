//
// Created by diqiu on 2016/9/23.
//
#include <iostream>

/**
 * problem:
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain
 * a single digit. Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) Output: 7 -> 0 -> 8
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if ( l1 == NULL || l2 == NULL ) {
            return l1 == NULL? l2: l1;
        }
        struct ListNode *lsum = new ListNode(0);
        struct ListNode *lsumHead = lsum;
        int carry = 0;
        while ( 1 ) {
            int val1 = ( l1 == NULL? 0: l1->val );
            int val2 = ( l2 == NULL? 0: l2->val );

            lsum->val = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;
            if ( l1 )   l1 = l1->next;
            if ( l2 )   l2 = l2->next;
            if (l1 == NULL && l2 == NULL && carry == 0) {
                break;
            }
            lsum->next = new ListNode(0);
            lsum = lsum->next;
        }
        return lsumHead;
    }
};