#pragma once

#include <iosfwd>

//template <typename T>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//template <typename T>
class List
{
private:
    ListNode* pHead;
    ListNode* pTail;

public:
    List();
    // 3 ptrs (prev, ptr, newNode)
    void insert(int value);

     // 2 ptrs (prev, ptr)
    void remove(int value);

    // 1 ptr (ptr)
    void print();

    // 1 ptr (ptr)
    int size();

    // 3 ptrs (prev, curr, next)
    void reverse();


    void rotateCCW(int rotations);


    void rotateCW(int rotations); // harder
};
