/* 
Problem Link: https://leetcode.com/problems/split-linked-list-in-parts/description/
Solution Link: https://leetcode.com/problems/split-linked-list-in-parts/solutions/3452520/c-well-commented-easy-solution/

*/
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
// calculating the size of linked list
    int length(ListNode* head){
        int size = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        return size;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = length(head);
        int innersize = len/k;
        int extras = len%k;

        vector<ListNode*>ans;
        while(k--){
            //since the difference of size can be at most 1 and the parts occuring earlier should have a greater size, we will keep adding 1 to each parts until the number of extras becomes 0.
            int currsize = innersize;//expected size of each parts
            if(extras){
                currsize++; //increasing the size of first part by one
                extras--;
            }
            if(currsize == 0){
                ans.push_back(NULL);
                continue;
            }
            //now we have to add the splitted linked lists of currsize in the ans vector.
            ListNode* temp = head; //storing the head of the curr splitted linked list
            ListNode* prev = NULL;
            while(currsize-- && head){ //storing linked lists of currsize
                prev = head;
                head = head->next;
            }
            //if we reach to the end of the current ll, we will make the prev point to the NULL
            if(prev)prev->next = NULL;
            //and then store the head of the current ll in the ans vector
            ans.push_back(temp);
        }
        return ans;

    }
};
