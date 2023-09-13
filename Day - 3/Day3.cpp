#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void rotate(int k)
    {
        if (head == nullptr || k == 0) return;

        int len = 1;
        Node *tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
            len++;
        }
        k = k % len;

        if (k == 0) return;

        tmp->next = head; // Made the list circular
        tmp = head;       // Reset tmp to the head

        // We Traverse to the (len - k)th node to find the new tail
        for (int i = 0; i < len - k - 1; i++)
        {
            tmp = tmp->next;
        }

        // Update the new head and breaked the circular list
        head = tmp->next;
        tmp->next = nullptr;
    }
};

int main()
{
    int size;
    cin >> size;

    LinkedList ll;
    for (int i = 0; i < size; i++)
    {
        int value;
        cin >> value;
        ll.insert(value);
    }
    int k;
    cin>>k;

    cout << "Linked List before rotation: ";
    ll.display();

    ll.rotate(k);
    cout << "Linked List after rotation: ";
    ll.display();

    return 0;
}
