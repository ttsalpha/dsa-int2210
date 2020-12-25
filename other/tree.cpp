/**Bogosort**/
// #include <bits/stdc++.h>
#include <iostream>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100005
#define maxm 1000006
#define maxc 1000000007
#define pii pair<int, int>
#define Task ""
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
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
using namespace std;
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
struct BinaryTreeADT
{
    Node *root;
    BinaryTreeADT()
    {
        root = NULL;
    }
};
void build(int l, int r, Node *u, vector<int> v)
{
    int mid = (l + r) >> 1;
    u->data = v[mid];
    if (l <= mid - 1)
    {
        u->left = new Node();
        build(l, mid - 1, u->left, v);
    }
    if (mid + 1 <= r)
    {
        u->right = new Node();
        build(mid + 1, r, u->right, v);
    }
}
BinaryTree createTree(char *filename)
{
    ifstream in;
    in.open(filename);
    string s;
    getline(in, s);
    s = s + ' ';
    vector<int> ver;
    ver.clear();
    int cur = 0;
    for (char c : s)
    {
        if (c == ' ')
        {
            ver.pb(cur);
            cur = 0;
        }
        else
        {
            cur = 10 * cur + c - '0';
        }
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
void TraversalLevel(BinaryTree t)
{
    if (t->root)
    {
        int pt = 0;
        vector<Node *> q;
        q.clear();
        q.pb(t->root);
        while (pt < q.size())
        {
            Node *u = q[pt++];
            if (u->left != NULL)
            {
                q.pb(u->left);
            }
            if (u->right != NULL)
            {
                q.pb(u->right);
            }
        }
        for (auto v : q)
        {
            cout << v->data << ' ';
        }
    }
    cout << '\n';
}
bool hasLeft(BinaryTree t)
{
    return t == NULL || t->root == NULL || t->root->left == NULL;
}
bool hasRight(BinaryTree t)
{
    return t == NULL || t->root == NULL || t->root->right == NULL;
}
BinaryTree Left(BinaryTree t)
{
    if (t == NULL || t->root == NULL)
    {
        return NULL;
    }
    BinaryTree res = new BinaryTreeADT();
    res->root = t->root->left;
    return res;
}
BinaryTree Right(BinaryTree t)
{
    if (t == NULL || t->root == NULL)
    {
        return NULL;
    }
    BinaryTree res = new BinaryTreeADT();
    res->root = t->root->right;
    return res;
}
int main()
{
    //srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie();
    //if(fopen(".inp", "r")) freopen(".inp", "r", stdin);
    BinaryTree T = createTree(".inp");
    TraversalLevel(T);
    return 0;
}
