// sum of a two LL.

#include <iostream>
#include <vector>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    void create(int num, Node *&head1)
    {
        int x = num;
        while (x)
        {
            int mod = x % 10;
            x = x / 10;
            Node *newnode = new Node(mod);
            if (head1 == NULL)
            {
                head1 = newnode;
            }
            else
            {
                newnode->next = head1;
                head1 = newnode;
            }
        }
    }
    void display(Node *head)
    {
        cout << "Displaying LL: ";
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node *findSumOfLL(Node *head1, Node *head2)
    {
        Node *newhead = NULL;
        vector<int> vec1;
        vector<int> vec2;

        Node *temp = head1;
        while (temp)
        {
            vec1.push_back(temp->data);
            temp = temp->next;
        }
        cout << "vec1: ";
        for (auto ele : vec1)
        {
            cout << ele << " ";
        }
        cout << endl;
        temp = head2;
        while (temp)
        {
            vec2.push_back(temp->data);
            temp = temp->next;
        }
        cout << "vec2: ";
        for (auto ele : vec2)
        {
            cout << ele << " ";
        }
        cout << endl;

        int i = vec1.size() - 1, j = vec2.size() - 1;
        int carry = 0;
        while (i >= 0 && j >= 0)
        {
            int sum = vec1[i] + vec2[j] + carry;

            cout << "sum: " << sum << endl;
            int mod = sum % 10;
            carry = sum / 10;
            Node *newnode = new Node(mod);
            if (newhead == NULL)
            {
                newhead = newnode;
            }
            else
            {
                newnode->next = newhead;
                newhead = newnode;
            }
            i--;
            j--;
        }

        while (i >= 0)
        {
            int sum = vec1[i--] + carry;
            int mod = sum % 10;
            carry = sum / 10;
            Node *newnode = new Node(mod);
            newnode->next = newhead;
            newhead = newnode;
        }
        while (j >= 0)
        {
            int sum = vec2[j--] + carry;
            int mod = sum % 10;
            carry = sum / 10;
            Node *newnode = new Node(mod);
            carry = 0;
            newnode->next = newhead;
            newhead = newnode;
        }
        if (carry)
        {
            Node *newnode = new Node(carry);
            carry = 0;
            newnode->next = newhead;
            newhead = newnode;
        }

        return newhead;
    }
};

int main()
{
    int num1 = 10040;
    int num2 = 104;

    Node sumofll;

    Node *head1 = NULL;
    sumofll.create(num1, head1);
    sumofll.display(head1);

    Node *head2 = NULL;
    sumofll.create(num2, head2);
    sumofll.display(head2);

    cout << "Finding sum of two LL." << endl;

    Node *newhead = sumofll.findSumOfLL(head1, head2);

    sumofll.display(newhead);

    return 0;
}