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
    public ListNode swapNodes(ListNode head, int k) {
        ListNode temp = head;
        List<Integer> t = new ArrayList<>();

        while(temp!= null){
            t.add(temp.val);
            temp = temp.next;
        }
        
        int demo = t.get(k-1);
        t.set(k-1, t.get(t.size()-k));
        t.set(t.size()-k, demo);

        // System.out.println(t.toString());

        temp = head;
        int i = 0;
        while(temp != null){
            temp.val = t.get(i++);
            temp = temp.next;
        }
        return head;
    }
}
