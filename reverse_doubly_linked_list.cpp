#include <iostream>
#include <iomanip>

template <typename T>
struct List
{
    List(T value): value(value) {}
    T value{};
    List* left{nullptr};
    List* right{nullptr};
    List<T>* push_back(List<T>* list)
    {
        right = list;
        list->left = this;
        return list;
    }
};

template<typename T>
void print(List<T>* list)
{
    List<T>* current = list;
    List<T>* left = nullptr;
    
    while (current != nullptr) {
        left = current;
        current = current->left;
    }
    
    current = left;
    
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->right;
    }
    std::cout << std::endl;
}

template<typename T>
void reverse(List<T>* list)
{
    List<T>* current = list;
    List<T>* left = nullptr;
    
    while (current != nullptr) {
        left = current;
        current = current->left;
    }
    
    current = left;
    
    List<T>* previous = nullptr;
    
    while (current) {
        List<T>* tmp_right = current->right;
        current->left = current->right;
        current->right = previous;
        previous = current;
        current = tmp_right;
    }
}

int main()
{
    List<int>* head = new List<int>(1);
    List<int>* tail = head->push_back(new List<int>(2))
                          ->push_back(new List<int>(3));
    
    print(head);
    print(tail);
    
    reverse(head);
    
    print(head);
    print(tail);
}
