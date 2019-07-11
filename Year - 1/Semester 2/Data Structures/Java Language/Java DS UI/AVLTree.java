public class AVLTree{

    Node head;

    // class Node{
    //     int nr, height;
    //     Node left, right;

    //     public Node(int nr){
    //         this.nr = nr;
    //         height = 1;
    //         left = null;
    //         right = null;
    //     }
    // }

    public AVLTree() {
        this.head = null;
    }

    public Node getHead() {
        return head;
    }


    /*
     * Utility
     */
    private int height(Node node) {
        if (node == null) {
            return 0;                
        }

        return node.height;
    }

    private int max(int a, int b) {
        return (a < b)  ?   b : a;
    }

    private int getBalance(Node node) {
        if (node == null) {
            return 0;
        }

        return height(node.left) - height(node.right);
    }

    /*
     * Rotate Right
     */
    private Node rightRotate(Node node) {
        var a = node.left;
        var b = a.right;

        a.right = node;
        node.left = b;

        node.height = max(height(node.left), height(node.right)) + 1;
        a.height = max(height(a.left), height(a.right)) + 1;

        return a;
    }

    /*
     * Rotate Left
     */
    private Node leftRotate(Node node) {
        var a = node.right;
        var b = a.left;

        a.left = node;
        node.right = b;

        node.height = max(height(node.left), height(node.right)) + 1;
        a.height = max(height(a.left), height(a.right)) + 1;

        return a;
    }

    /*
     * Insert
     */
    public Node insert(Node node, int nr) {
        if (node == null) {
            return (new Node(nr));        
        }

        if (nr < node.nr) {
            node.left = insert(node.left, nr);                
        } else if (nr > node.nr) {
            node.right = insert(node.right, nr);
        } else {
            return node;
        }

        node.height = max(height(node.left), height(node.right)) + 1;

        int balance = getBalance(node);


        if (balance > 1 && nr < node.left.nr) {
            return rightRotate(node);
        }

        if (balance < -1 && nr > node.right.nr) {
            return leftRotate(node);
        }

        if (balance > 1 && nr > node.left.nr) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        if (balance < -1 && nr < node.right.nr) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        return node;
    }
}