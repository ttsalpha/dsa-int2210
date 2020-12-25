#include <iostream>
#include <fstream>
using namespace std;
template <typename T>
inline void read(T &x)
{
    char c;
    bool nega = 0;
    while ((!isdigit(c = getchar())) && (c != '-'))
        ;
    if (c == '-')
    {
        nega = 1;
        c = getchar();
    }
    x = c - 48;
    while (isdigit(c = getchar()))
        x = x * 10 + c - 48;
    if (nega)
        x = -x;
}
template <typename T>
inline void writep(T x)
{
    if (x > 9)
        writep(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    writep(x);
    putchar(' ');
}
template <typename T>
inline void writeln(T x)
{
    write(x);
    putchar('\n');
}

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node()
    {
        data = 0;
        left = right = NULL;
    }
};

typedef struct BinaryTreeADT *BinaryTree;
int A[100];

Node *createNote(int i)
{
    Node *node = new Node;
    node->data = A[i];
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct BinaryTreeADT
{
    Node *root;
    BinaryTreeADT()
    {
        root = NULL;
    }
};

void build(int l, int r, Node *u, vector<int> ver)
{
    int m = (l + r) / 2;
    u->data = ver[m];
    if (l <= m - 1)
    {
        u->left = new Node();
        build(l, m - 1, u->left, ver);
    }
    if (m + 1 <= r)
    {
        u->right = new Node;
        build(m + 1, r, u->right, ver);
    }
}

BinaryTree createTree(char *filename)
{
    fstream file;
    file.open(filename);
    string s;
    getline(in, s);

    s += ' ';
    vector<int> ver;
    ver.clear();
    int tmp = 0;
    for (char c : s)
    {
        if (c == ' ')
        {
            ver.pb(tmp);
            tmp = 0;
        }
        else
            tmp = 10 * tmp + c - '0';
    }

    if (ver.size())
    {
        BinaryTree res = new BinaryTreeADT();
        res->root = new Node();
        build(0, ver.size() - 1, res->root, ver);
        return res;
    }

    return NULL;
}

BinaryTreeADT *createTreeADT()
{
    Node *root;
    BinaryTreeADT();
    {
        root = NULL;
    }
}

bool hasLeft(BinaryTreeADT t)
{
    if (t.root->left == NULL)
        return true;
    return false;
}

bool hasRight(BinaryTreeADT t)
{
    if (t.root->right == NULL)
        return false;
    return true;
}

BinaryTreeADT *Left(BinaryTreeADT t)
{
    if (t.root->left == NULL)
        return nullptr;
    BinaryTreeADT *a = new BinaryTreeADT();
    a->root = t.root->left;
    return a;
}

void TraversalLevel(BinaryTreeADT t)
{
}

void printPostorder(struct Node *node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void printPostorderTree(BinaryTreeADT *tree)
{
    printPostorder(tree->root);
}

int main(int argc, const char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie();
    BinaryTree T = createTree("input.txt");
    return 0;
}
