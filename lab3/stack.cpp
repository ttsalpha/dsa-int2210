#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct Stack
{
    Node *first;
    Stack()
    {
        first = NULL;
    }
};

void addFirst(Stack &s, int v)
{
    Node *newNode = new Node(v);
    newNode->next = s.first;
    s.first = newNode;
}

void addLast(Stack &s, int v)
{
    if (s.first == NULL)
        addFirst(s, v);
    else
    {
        Node *index = s.first;
        while (index->next != NULL)
            index = index->next;
        Node *last = new Node(v);
        index->next = last;
    }
}

Stack newStack(char *filename)
{
    fstream file;
    file.open(filename);
    Stack s;
    int temp;
    while (file >> temp)
    {
        addLast(s, temp);
    }
    file.close();
    return s;
}

void printStack(Stack s)
{
    Node *index;
    for (index = s.first; index != NULL; index = index->next)
    {
        cout << index->data << " ";
    }
    cout << endl;
}

bool isEmpty(Stack s)
{
    if (s.first = NULL)
        return true;
    return false;
}

void push(Stack &s, int v)
{
    Node *newNode = new Node(v);
    newNode->next = s.first;
    s.first = newNode;
}

int getTop(Stack s)
{
    if (isEmpty(s) == true)
    {
        cout << "Error! Stack is empty";
        return -1;
    }
    return s.first->data;
}

void pop(Stack &s)
{
    if (isEmpty(s) == true)
    {
        cout << "Nothing to pop!";
    }
    else
    {
        cout << getTop(s);
        int temp = s.first->data;
        Node *p = s.first;
        s.first = s.first->next;
        delete p;
    }
}

int main()
{
    Stack st = newStack("input.txt");
    cout << "Current Stack: ";
    printStack(st);

    push(st, 20);
    cout << "After pushing val 20: ";

    printStack(st);
    cout << "The top value is: ";

    pop(st);
    cout << endl
         << "After popping: ";

    printStack(st);
}