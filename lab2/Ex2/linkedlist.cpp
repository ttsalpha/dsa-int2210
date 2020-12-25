#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    //new list node - ex2
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *first;
    LinkedList()
    {
        first = NULL;
    }
};

//add first - ex3
void addFirst(LinkedList &list, int v)
{
    Node *newNode = new Node(v);
    newNode->next = list.first;
    list.first = newNode;
}

//add last - ex3
void addLast(LinkedList &list, int v)
{
    if (list.first == NULL)
        addFirst(list, v);
    else
    {
        Node *index = list.first;
        while (index->next != NULL)
            index = index->next;
        Node *last = new Node(v);
        index->next = last;
    }
}

//new list ex1
LinkedList newList(char *filename)
{
    fstream file;
    file.open(filename);
    LinkedList list;
    int temp;
    while (file >> temp)
    {
        //      addFirst(list, temp);
        addLast(list, temp);
    }
    file.close();
    return list;
}

//removefirst - ex3
void removeFirst(LinkedList &list)
{
    Node *temp = list.first;
    list.first = temp->next;
    delete temp;
}

//findIndex - ex3
int findIndex(LinkedList list, int v)
{
    int count = 0;
    Node *index;
    for (index = list.first; index != NULL; index = index->next)
    {
        if (index->data == v)
            return count;
        else
            count++;
    }
    return -1;
}

//print list - ex2
void printList(LinkedList list)
{
    Node *index;
    for (index = list.first; index != NULL; index = index->next)
    {
        cout << index->data << " ";
    }
    cout << endl;
}

int main()
{
    LinkedList list = newList("List.txt");
    printList(list);
    cout << "Add 27 to last:" << endl;
    addLast(list, 27);
    printList(list);
    cout << "Remove first: " << endl;
    removeFirst(list);
    printList(list);
    cout << "Find index of 8 in list: " << findIndex(list, 8) << endl;
    printList(list);
    return 0;
}
