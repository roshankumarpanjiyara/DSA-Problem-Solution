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
    public ListNode middleNode(ListNode head) {
        // int size = 1;
        // ListNode temp = head;
        // while(temp.next != null){
        //     size++;
        //     temp = temp.next;
        // }
        // // System.out.println(size);
        // temp = head;
        // int i = 0;
        // while(i<size/2 && temp.next != null){
        //     temp = temp.next;
        //     i++;
        // }
        // return temp;

        ListNode slow = head, fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}
