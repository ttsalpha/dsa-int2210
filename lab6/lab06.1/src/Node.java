/**
 * 18021105 Tran The Son
 */

public class Node {
    int data;
    Node firstChild;
    Node nextSibling;

    public Node(int data){
        this.data = data;
    }

    public Node(int data, Node firstChild, Node nextSibling) {
        this.data = data;
        this.firstChild = firstChild;
        this.nextSibling = nextSibling;
    }
}
