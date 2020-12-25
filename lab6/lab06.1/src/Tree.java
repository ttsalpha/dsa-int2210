/**
 * 18021105 Tran The Son
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Tree {
    Node root = null;

    public Tree() {
        root = null;
    }

    public void getInput(String input) throws FileNotFoundException {
        try (Scanner scanner = new Scanner(new File(input))) {
            while (scanner.hasNext()) {
                String line = scanner.nextLine();
                insert(line);
            }
        }
    }

    private Node searchNode(int data, Node node) {
        if (node != null) {
            if (node.data == data) {
                return node;
            } else {
                Node inode;
                inode = searchNode(data, node.firstChild);
                if (inode == null) {
                    inode = searchNode(data, node.nextSibling);
                    if (inode != null) {
                        return inode;
                    }
                } else
                    return inode;
            }
        }
        return node;
    }

    void insert(String line) {
        String[] parts = line.split(" ");
        if (root == null) {
            root = new Node(Integer.parseInt(parts[0]));
            for (int i = 1; i < parts.length; i++) {
                root.nextSibling = new Node(Integer.parseInt(parts[i]));
            }
        } else {
            Node parent = searchNode(Integer.parseInt(parts[0]), root);
            parent.firstChild = new Node(Integer.parseInt(parts[1]));
            for (int i = 2; i < parts.length; i++) {
                parent.nextSibling = new Node(Integer.parseInt(parts[i]));
            }
            root.firstChild = parent;
        }
    }

    int height(Node root) {
        if (root == null)
            return 0;
        else {
            int rHeight = height(root);
            int nHeight = height(root.firstChild);
            if (rHeight > nHeight)
                return (rHeight + 1);
            else return (nHeight + 1);
        }
    }

    void printLevel(Node root) {
        if (root == null)
            return;
        if (root.nextSibling != null)
            System.out.print(root.data + " ");
        printLevel(root.nextSibling);
    }

    void printLevelOrder() {
        int h = height(root);
        for (int i = 1; i <= h; i++) {
            printLevel(root);
        }
    }

    public void preOrder(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            preOrder(node.firstChild);
            preOrder(node.nextSibling);
        }
    }

    void postOrder(Node node) {
        if (node != null) {
            postOrder(node.firstChild);
            System.out.print(node.data + " ");
            postOrder(node.nextSibling);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Tree tree = new Tree();
        tree.getInput("input.txt");
//        System.out.println("\nTree print level order");
//        tree.printLevelOrder();
        System.out.println("\nTree print pre order");
        tree.preOrder(tree.root);
        System.out.println("\nTree print post order");
        tree.postOrder(tree.root);

    }
}