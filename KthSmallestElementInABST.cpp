//
// Created by diqiu on 2016/9/28.
//

#include <iostream>
#include <list>
#include <iterator>
#include <vector>
/**
 * problem:
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 * Follow up:
 * What if the BST is modified (insert/delete operations) often
 * and you need to find the kth smallest frequently?
 * How would you optimize the kthSmallest routine?
 */
/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 *  #1 solution 1
 */

class Solution {
public:
    Solution()
    {
        _res = 0;
        _count = 0;
    }
    int kthSmallest(TreeNode* root, int k)
    {
        if ( root == NULL ) {
            return _res;
        }
        kthSmallest(root->left, k);
        _count++;
        if ( _count == k ) {
            _res = root->val;
        }
        kthSmallest(root->right, k);
        return _res;
    }

    int _res;
    int _count;
};

class Solution2 {
public:

    int countChildren(TreeNode* root)
    {
        if ( root == NULL ) return 0;
        return countChildren(root->left) + countChildren(root->right) + 1;
    }

    TreeNode* findRightestNode(TreeNode* root)
    {
        while (root) {
            root = root->right;
        }
        return root;
    }

    int kthSmallest(TreeNode* root, int k)
    {
        std::list<TreeNode*> listNode;
        while ( root ) {
            listNode.push_front(root);
            root = root->left;
        }
        int count = 0;
        int val = 0;
        for ( std::list<TreeNode*>::iterator it = listNode.begin(); it != listNode.end(); it++ ) {
            count = countChildren((*it)->right) + 1;
            if ( count < k ) {
                k -= count;
            } else if ( count > k ) {
                k -= 1;
                if ( k == 0 ) {
                    val = (*it)->val;
                } else {
                    val = kthSmallest((*it)->right, k);
                }
                break;
            } else {
                val = findRightestNode(*it)->val;
                break;
            }
        }

        return val;
    }

};

