/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node temp = head;
        while(temp != null){
            Node newNode = new Node(temp.val);
            newNode.next = temp.next;
            temp.next = newNode;
            temp = temp.next.next;
        }
        Node item = head;
        while(item != null){
            if(item.random != null){
                item.next.random = item.random.next;
            }
            item = item.next.next;
        }
        item = head;
        Node pseudoHead = new Node(0);
        Node dummy = pseudoHead;
        Node front = head;
        while(item != null){
            front = item.next.next;
            dummy.next = item.next;
            dummy = dummy.next;
            item.next = front;
            item = front;
        }
        return pseudoHead.next;
    }
}
