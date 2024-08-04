/*
 LeetCode Problem:  1 Two Sum
 Description:       Given an array of integers nums and an integer target,
                    return indices of the two numbers such that they add
                    up to target.
                    You may assume that each input would have exactly one
                    solution, and you may not use the same element twice.
                    You can return the answer in any order.
 Link:              https://leetcode.com/problems/two-sum/description/
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    struct hashTable
    {
        int key;
        int value;
        UT_hash_handle hh;
    } *hashTable = NULL, *item;

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        HASH_FIND_INT(hashTable, &complement, item);
        if (item)
        {
            int *result = malloc(sizeof(int) * 2);
            result[0] = item->value;
            result[1] = i;
            *returnSize = 2;
            HASH_CLEAR(hh, hashTable); // Free the hash table
            return result;
        }
        item = malloc(sizeof(struct hashTable));
        item->key = nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item);
    }
    *returnSize = 0;
    HASH_CLEAR(hh, hashTable); // Free the hash table
    return NULL;
}