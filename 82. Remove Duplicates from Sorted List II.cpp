/* Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]
 
Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order. */
//code
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0); //creating a new dummy node
        dummy->next = head; //point it's next to the head of the linked list
        ListNode* prev = dummy; // create two pointers one is prev that is required to change links
        ListNode* temp = head;
        
        while(temp!=NULL){
            if(temp->next!=NULL && temp->val == temp->next->val){ //if we found duplicate nodes
                while(temp->next!=NULL && temp->val == temp->next->val){ //we will keep moving our temp until we reach our last duplicate node
                    temp = temp->next;
                }
                prev->next = temp->next; //then change the links
            }
            else{
                prev = prev->next; //other wise simply move prev to its next
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};
