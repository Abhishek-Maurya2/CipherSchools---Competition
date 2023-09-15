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

    Node *mergeTwoLists(Node *l1, Node *l2)
    {
        Node dummy(0);
        Node *tail = &dummy;

        while (l1 && l2)
        {
            if (l1->data < l2->data)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }

    void merge(vector<Node *> &lists)
    {
        if (lists.empty()) return;
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }

        head = lists[0];
    }
};

int main()
{
    LinkedList ll;

    Node *list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);

    Node *list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Node *list3 = new Node(2);
    list3->next = new Node(6);

    vector<Node *> lists = {list1, list2, list3};
    cout << "Linked List before merging: ";
    ll.display();

    ll.merge(lists);
    cout << "Linked List after merging: ";
    ll.display();

    return 0;
}
