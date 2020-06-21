#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }

        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;

        ListNode* p = dummyHead;
        while(p->next != NULL){
            if(p->next->val == val){
                ListNode* tmp = p->next;
                p->next = p->next->next;
                tmp->next = NULL;
            }else{
                p = p->next;
            }
        }
        return dummyHead->next;
    }
};

int main(){
    int nums[] = {1,2,6,3,4,5,6};
    ListNode* head = new ListNode(nums[0], NULL);
    ListNode* p = head;
    for(int i=1; i<7; i++){
        ListNode* tmp = new ListNode(nums[i], NULL);
        p->next = tmp;
        p = p->next; 
        tmp = NULL;
        delete tmp;  
    }

    Solution s;
    ListNode* pt = s.removeElements(head, 6);

    while(pt != NULL){
        cout << pt->val << endl;
        pt = pt->next;
    }

    return 0;
}