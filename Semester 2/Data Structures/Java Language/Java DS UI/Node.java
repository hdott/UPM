public class Node{
 
    int nr, height;
    Node left, right;

    public Node(int nr){
        this.nr = nr;
        height = 1;
        left = null;
        right = null;
    }
}