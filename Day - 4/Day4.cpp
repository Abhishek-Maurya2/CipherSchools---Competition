#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class LinkedList {
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
    void reverseK(int k) {
        if (head == nullptr || k == 1) return;
        int count = 0;
        Node *curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        Node dummy(0);
        dummy.next = head;
        Node *prev = &dummy;
        while (count >= k) {
            Node *start = prev->next;
            Node *nxt = start->next;
            for (int i = 1; i < k; i++) {
                start->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = start->next;
            }
            prev = start;
            count -= k;
        }
        head = dummy.next;
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

    cout << "Linked List after rotation: ";
    ll.reverseK(k);
    ll.display();

    return 0;
}
