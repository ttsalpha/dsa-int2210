/**
 * 18021105 Tran The Son
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class BSTree {
    Node root = null;

    public BSTree() {
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

    int minValue(Node root) {
        int min = root.data;
        while (root.left != null) {
            min = root.left.data;
            root = root.left;
        }
        return min;
    }

    Node deleteNode(Node root, int data) {
        if (root == null)
            return null;
        if (data < root.data) {
            root.left = deleteNode(root.left, data);
        } else if ((data > root.data)) {
            root.right = deleteNode(root.right, data);
        } else {
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;
            root.data = minValue(root.right);
            root.right = deleteNode(root.right, root.data);
        }
        return root;
    }

    void delete(int data) {
        deleteNode(root, data);
    }

    public void printLevelOrder() {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++) {
            printLevel(root, i);
        }
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

    private Node searchValue(Node root, int value) {
        if (root == null)
            return root;
        else if (root.data == value)
            return root;
        else if (root.data > value)
            return searchValue(root.left, value);
        else
            return searchValue(root.right, value);
    }

    public static void main(String[] args) throws FileNotFoundException {
        BSTree tree = new BSTree();
        tree.getInput("input.txt");
        System.out.println("Input: 6 5 7 8 4 3");
        System.out.println("\nTree print level order");
        tree.printLevelOrder();
        tree.insert(2);
        System.out.println("\nTree after insert 2");
        tree.printLevelOrder();
        tree.delete(3);
        System.out.println("\nTree after delete 3");
        tree.printLevelOrder();
        Node tmp = tree.searchValue(tree.root, 5);
        System.out.println("\nSearch: " + tmp.data);
    }
}
