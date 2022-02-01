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
        HashMap<Node, Node> mp = new HashMap<>();
        return cloneptr(head, mp);
    }
     public Node cloneptr(Node old, HashMap<Node, Node> mp){
        if(old == null){
            return null;
        }

        Node newNode = new Node(old.val);
        mp.put(old, newNode);

        newNode.next = cloneptr(old.next, mp);
        newNode.random = mp.get(old.random);

        return newNode;
    }
}