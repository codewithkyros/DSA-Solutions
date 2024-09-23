## Merge Two Sorted Lists

### Problem Description:
This C++ function merges two sorted linked lists into one sorted list. The input consists of two sorted singly linked lists, `list1` and `list2`. The function merges the two lists into a single linked list that is also sorted in non-decreasing order.

### Code Explanation:
The function uses three pointers:
- `p1` points to the current node in `list1`.
- `p2` points to the current node in `list2`.
- `p3` is used to build the new merged list, starting from a dummy node.

### Step-by-Step Process:

1. **Initialization**: 
   - We create two pointers `p1` and `p2` that point to the head of `list1` and `list2` respectively.
   - A dummy node (`dummy`) is initialized to help simplify the merging process. The actual merged list will start from `dummy->next`.
   - `p3` is initialized to point to the dummy node. It will traverse and link nodes from `list1` and `list2`.

2. **Merging the Two Lists**:
   - We enter a `while` loop that continues as long as both `p1` and `p2` are not `NULL`. 
   - In each iteration, the smaller value between `p1->val` and `p2->val` is appended to the merged list, and the corresponding pointer (`p1` or `p2`) is advanced.
   
3. **Appending Remaining Nodes**:
   - After the first `while` loop, one of the lists may still have nodes left (because they are of unequal length).
   - Two additional `while` loops handle appending the remaining nodes from either `list1` or `list2` to the merged list.

4. **Return the Merged List**:
   - The function finally returns `dummy->next`, which points to the head of the merged linked list.

### Code:


ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* dummy = new Listnode(-1);
        ListNode* p3 = dummy;

        while(p1!= NULL && p2!= NULL){

            if(p1->val < p2->val){
                p3->next =p1;
                p1=p1->next;

            }
            else{
                p3->next =p2;
                p2=p2->next;

            }
            p3= p3->next;

        }
        while(p1!=NULL){
        p3->next = p1;
        p1=p1->next;
        p3= p3->next;

    }
       while(p2!=NULL){
        p3->next = p2;
        p2=p2->next;
        p3= p3->next;

    }
    return dummy->next;


    }
