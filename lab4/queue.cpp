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

struct Queue
{
    Node *first;
    Queue()
    {
        first = NULL;
    }
};

void addFirst(Queue &q, int v)
{
    Node *newNode = new Node(v);
    newNode->next = q.first;
    q.first = newNode;
}

void addLast(Queue &q, int v)
{
    if (q.first == NULL)
        addFirst(q, v);
    else
    {
        Node *index = q.first;
        while (index->next != NULL)
            index = index->next;
        Node *last = new Node(v);
        index->next = last;
    }
}

Queue newQueue(char *filename)
{
    fstream file;
    file.open(filename);
    Queue q;
    int temp;
    while (file >> temp)
    {
        addLast(q, temp);
    }
    file.close();
    return q;
}

void printQueue(Queue q)
{
    Node *index;
    for (index = q.first; index != NULL; index = index->next)
    {
        cout << index->data << " ";
    }
    cout << endl;
}

bool isEmpty(Queue q)
{
    if (q.first = NULL)
        return true;
    return false;
}

void enqueue(Queue &q, int v)
{
    if (q.first == NULL)
    {
        Node *newNode = new Node(v);
        newNode->next = q.first;
        q.first = newNode;
    }
    else
    {
        Node *index = q.first;
        while (index->next != NULL)
            index = index->next;
        Node *last = new Node(v);
        index->next = last;
    }
}

int getHead(Queue q)
{
    if (isEmpty(q) == true)
    {
        cout << "Error! Queue is empty";
        return -1;
    }
    return q.first->data;
}

void dequeue(Queue &q)
{
    if (isEmpty(q) == true)
    {
        cout << "Empty, do nothing!";
    }
    else
    {
        cout << getHead(q);
        int temp = q.first->data;
        Node *p = q.first;
        q.first = q.first->next;
        delete p;
    }
}

int main()
{
    Queue q = newQueue("input.txt");
    cout << "Current Queue: ";
    printQueue(q);
    enqueue(q, 30);
    cout << "After Enqueue: ";
    printQueue(q);
    cout << "The top value is: ";
    dequeue(q);
    cout << endl
         << "After Dequeue: ";
    printQueue(q);
}
