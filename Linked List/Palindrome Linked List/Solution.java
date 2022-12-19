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
    public static ListNode middle(ListNode head){
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public static ListNode reverse(ListNode head){
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    public boolean isPalindrome(ListNode head) {
        if(head == null){
            return true;
        }

        ListNode mid = middle(head);
        ListNode last = reverse(mid.next);
        ListNode curr = head;
        ListNode end = last;
        // System.out.println(mid.val);
        boolean result = true;
        while(result && end != null){
            if(end.val != curr.val){
                result = false;
            }
            end = end.next;
            curr = curr.next;
        }
        mid.next = reverse(last);
        return result;
    }
}
