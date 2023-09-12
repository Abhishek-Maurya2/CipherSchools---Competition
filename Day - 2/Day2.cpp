#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *oddEven(Node *head)   // Function to segregate the odd and even nodes
{
    Node *odd = head;
    Node *even = head->next;    //What we do is we create two linked lists, one for odd and one for even
    Node *evenHead = even;

    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;   // We then connect the odd list to the even list and return the head of the combined list
    return head;
}
int main() {
    Node *head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = new Node();
    head->next->next->next->data = 4;
    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 5;

    cout << "Before: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    head = oddEven(head);

    cout << "\nAfter: ";
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}