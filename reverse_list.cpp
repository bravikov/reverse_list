#include <iostream>

///////////////////////////////////////////////////////////////////////////////

struct Node
{
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {}
};

Node* reverseList(Node* head)
{
    Node* previous = nullptr;
    Node* current = head;

    while(current != nullptr) {
        Node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

///////////////////////////////////////////////////////////////////////////////

void printList(Node* head)
{
    static int printCount = 0;

    std::cout << printCount++ << " list: ";

    Node* node = head;
    while (node != nullptr) {
        std::cout << node->value << " ";
        node = node->next;
    }

    std::cout << std::endl;
}

void deleteList(Node* head)
{
    Node* node = head;
    while (node != nullptr) {
        Node* next = node->next;
        delete node;
        node = next;
    }
}

/* test() выводит в стандартный поток следующее:
0 list:
1 list:
2 list: 0
3 list: 0
4 list: 0 1
5 list: 1 0
6 list: 0 1 2
7 list: 2 1 0
8 list: 0 1 2 3
9 list: 3 2 1 0
10 list: 0 1 2 3 4
11 list: 4 3 2 1 0
12 list: 0 1 2 3 4 5
13 list: 5 4 3 2 1 0
14 list: 0 1 2 3 4 5 6
15 list: 6 5 4 3 2 1 0
16 list: 0 1 2 3 4 5 6 7
17 list: 7 6 5 4 3 2 1 0
18 list: 0 1 2 3 4 5 6 7 8
19 list: 8 7 6 5 4 3 2 1 0
20 list: 0 1 2 3 4 5 6 7 8 9
21 list: 9 8 7 6 5 4 3 2 1 0
*/

void test()
{
    Node* node0 = nullptr;
    printList(node0);

    node0 = reverseList(node0);
    printList(node0);

    node0 = new Node{0};
    printList(node0);

    node0 = reverseList(node0);
    printList(node0);

    Node* node = node0;
    static const int listSize = 10;
    for (int i = 1; i < listSize; i++) {
        Node *newNode = new Node{i};
        node->next = newNode;
        node = newNode;

        printList(node0);
        node0 = reverseList(node0);
        printList(node0);
        node0 = reverseList(node0);
    }

    deleteList(node0);
}

int main()
{
    test();
    return 0;
}
