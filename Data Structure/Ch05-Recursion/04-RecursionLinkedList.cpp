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
            return NULL;
        }
        ListNode* ret = removeElements(head->next, val);
        if(head->val == val){
            head = ret;
            return head;
        }else{
            head->next = ret;
            return head;
        }
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