#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};
int maxSumOfTwins(Node *head) {
    vector<int> val;
    Node *current = head;
    while (current != nullptr)      // Storing all the values in a vector for adding them later
    {
        val.push_back(current->val);
        current = current->next;
    }
    int left = 0, right = val.size() - 1, maximumSum = 0;

    while (left < right)        // Finding the maximum sum of the twins
    {
        maximumSum = max(maximumSum, val[left] + val[right]);
        left++;
        right--;
    }
    return maximumSum;
}

int main()
{
    Node *head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);

    int result = maxSumOfTwins(head);
    cout << "\nMaximum Twin Sum is : " << result << endl<<endl;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
