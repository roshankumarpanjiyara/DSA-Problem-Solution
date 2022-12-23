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
class Solution {
    public ListNode middle(ListNode head){
        ListNode slow = null;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = (slow == null) ? head : slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    public ListNode merge(ListNode left, ListNode right){
        if(left == null || right == null){
            return (left == null)?right:left;
        }

        ListNode ans = new ListNode(0);
        ListNode curr = ans;

        while(left != null && right != null){
            if(left.val<right.val){
                curr.next = left;
                left = left.next;
            }else{
                curr.next = right;
                right = right.next;
            }
            curr = curr.next;
        }
        if(left != null || right != null){
            curr.next = (left != null)?left:right;
        }
        return ans.next;
    }
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode mid = middle(head);
        ListNode newHead = mid.next;
        mid.next = null;
        ListNode left = sortList(head);
        ListNode right = sortList(newHead);
        return merge(left,right);
    }
}
