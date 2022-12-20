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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null || head.next == null){
            return null;
        }
        int size = 1;
        ListNode temp = head;
        while(temp.next != null){
            size++;
            temp = temp.next;
        }
        
        System.out.println(size);
        int pos = size - n;
        temp = head;
        if(pos == 0){
            head = head.next;
            return head;
        }
        for(int i = 0;i<pos-1;i++){
            temp = temp.next;
        }
        temp.next = temp.next.next;
        return head;
    }
}
