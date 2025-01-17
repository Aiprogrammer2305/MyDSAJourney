//Middle of the LL
class Solution {
public: 
    ListNode* middleNode(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        int midIdx = len/2;
        ListNode* mid = head;
        for(int i=1; i<=midIdx; i++){
            mid = mid->next;
        }
        return mid;
    }

};

// Twist: Do the same in single pass


//for odd length:-
class Solution{
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

//for even length:
class Solution{
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){ //the only change
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


// combine both conditions:

class Solution{
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
