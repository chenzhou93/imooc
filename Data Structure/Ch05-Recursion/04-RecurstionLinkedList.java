/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution3 {
    public ListNode removeElements(ListNode head, int val) {
        if(head == null){
            return null;//head
        }

        //头节点后面接的链表中，删除元素后剩下的链表
        ListNode res = removeElements(head.next, val);
        
        if(head.val == val){
            return res;
        }else{
            head.next = res;
            return head;
        }


        /************************************************/
        head.next = removeElements(head.next, val);
        return head.val == val ? head.next : head;
    }

    public static void main(String[] args){
        int[] nums = {1,2,6,3,4,5,6};
        ListNode head = new ListNode(nums);
        System.out.println(head);

        ListNode res = (new Solution()).removeElements(head, 6);
        System.out.println(res);
    }
}