/**
 * 18021105 Tran The Son
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class BinaryTree {
    Node root = null;

    public BinaryTree() {
        root = null;
    }

    public void getInput(String input) throws FileNotFoundException {
        try (Scanner scanner = new Scanner(new File(input))) {
            while (scanner.hasNext()) {
                int node = scanner.nextInt();
                insert(node);
            }
        }
    }

    private Node insertNode(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }
        if (root.data <= data) {
            root.right = insertNode(root.right, data);
        } else {
            root.left = insertNode(root.left, data);
        }
        return root;
    }

    void insert(int data) {
        root = insertNode(root, data);
    }

    int height(Node root) {
        if (root == null)
            return 0;
        else {
            int lHeight = height(root.left);
            int rHeight = height(root.right);

            if (lHeight > rHeight)
                return (lHeight + 1);
            else return (rHeight + 1);
        }
    }

    void printLevel(Node root, int level) {
        if (root == null)
            return;
        if (level == 1)
            System.out.print(root.data + " ");
        else if (level > 1) {
            printLevel(root.left, level - 1);
            printLevel(root.right, level - 1);
        }
    }

    void printLevelOrder() {
        int h = height(root);
        for (int i = 1; i <= h; i++) {
            printLevel(root, i);
        }
    }

    boolean hasLeft() {
        return root.left != null;
    }

    boolean hasRight() {
        return root.right != null;
    }

    private BinaryTree left(BinaryTree tree) {
        BinaryTree treeLeft = new BinaryTree();

        if (hasLeft()) {
            treeLeft.root = new Node(root.left.data);
            return treeLeft;
        }
        return null;
    }

    private BinaryTree right(BinaryTree tree) {
        BinaryTree treeRight = new BinaryTree();

        if (hasLeft()) {
            treeRight.root = new Node(root.left.data);
            return treeRight;
        }
        return null;
    }

    public static void main(String[] args) throws FileNotFoundException {
        BinaryTree tree = new BinaryTree();
        tree.getInput("input.txt");
        System.out.println("Input: 6 5 7 8 4 3");
        System.out.println("\nTree print level order");
        tree.printLevelOrder();
        System.out.println("\nCheck left: " + tree.hasLeft());
        System.out.println("\nCheck right: " + tree.hasRight());
        BinaryTree treeLeft = tree.left(tree);
        assert treeLeft != null;
        treeLeft.printLevelOrder();
        BinaryTree treeRight = tree.right(tree);
        assert treeRight != null;
        treeRight.printLevelOrder();
    }
}
