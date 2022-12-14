/*
class Node { 
    int data; 
    Node next; 

    Node() { data = 0; }
    Node(int d) { data = d; }  //constructor to create a new node
} 
*/
class Solution {
    static Node constructLL(int arr[]) {
        // code here
        Node head = null;
        Node last = null;
        for(int i = 0;i<arr.length;i++){
            if(head == null){
                head = new Node(arr[i]);
                last = head;
            }else{
                last.next = new Node(arr[i]);
                last =last.next;
            }
        }
        return head;
    }
}
