/* Structure of Doubly Linked List
class Node
{
	int data;
	Node next;
	Node prev;
	Node(int data)
	{
	    this.data = data;
	    next = prev = null;
	}
}*/

class GfG
{
    //Function to insert a new node at given position in doubly linked list.
    void addNode(Node head_ref, int pos, int data)
	{
		// Your code here
		Node node = new Node(data);
		Node temp = head_ref;
		int index = 0;
		while(index++ != pos){
		    temp = temp.next;
		}
		node.prev = temp;
		node.next = temp.next;
		temp.next = node;
// 		node.next.prev = node;
	}
}
