/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        // ListNode temp = headA;
        // ListNode temp2 = headB;
        // if(headA == headB){
        //     return headA;
        // }
        // boolean intersect = false;
        // while(temp2!=null){
        //     temp = headA;
        //     while(temp!=null){
        //         if(temp == temp2){
        //             return temp;
        //         }
        //         temp = temp.next;
        //     }
        //     temp2 = temp2.next;
        // }
        // return null;

        if(headA == null || headB == null){
            return null;
        }
        
        ListNode a = headA;
        ListNode b = headB;
        while(a!=b){
            a = a == null?headB:a.next;
            b = b == null?headA:b.next;
        }
        return a;
    }
}
