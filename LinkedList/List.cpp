// Example program
#include <iostream>
#include <string>

using namespace std;

struct LinkedList
{
    LinkedList* left, * right;
    int id;
};

void add_left(LinkedList*& head, LinkedList*& end, int id)
{
    LinkedList* new_elem = new LinkedList;
    new_elem->left = nullptr;
    new_elem->id = id;

    if (head != nullptr)
    {
        head->left = new_elem;
        new_elem->right = head;
    }
    else
    {
        new_elem->right = nullptr;
        end = new_elem;
    }

    head = new_elem;

}

void delete_element(LinkedList*& head, LinkedList*& end, int id)
{
    if (head->id == id)
    {
        LinkedList* ptr = head->right;
        
        head = head->right;
        ptr->left = nullptr;
    }
    else if (end->right->id == id)
    {
        LinkedList* ptr = end;

        end = end->left;
        ptr->right = nullptr;
    }
    else
    {
        LinkedList* ptr = head;
        
        while (ptr->right->id != id)
            ptr = ptr->right;
        
        ptr->right = ptr->right->right;
    }
}

void add_right(LinkedList*& head, LinkedList*& end, int id)
{
    LinkedList* new_element = new LinkedList;
    new_element->id = id;

    end->right = new_element;
    new_element->right = nullptr;
    end = new_element;
}


void isert(LinkedList*& head, LinkedList*& end, int id, int position)
{
    LinkedList* new_element = new LinkedList;
    LinkedList* ptr = head;

    new_element->id = id;

    while (ptr->id != position && ptr->right != nullptr)
        ptr = ptr->right;


    if (ptr->right == nullptr)
    {
        cout << "this number is missing";
    }
    else
    {
        LinkedList* r = ptr;
        LinkedList* rr = ptr->right;

        r->right = new_element;
        new_element->right = rr;
    }
}


void print(LinkedList* h)
{
    while (h != nullptr)
    {
        cout << h->id << " ";
        h = h->right;
    }
}

int main()
{
    LinkedList* h = nullptr, * e = nullptr;
    print(h);
    add_left(h, e, 4);
    add_left(h, e, 3);
    add_left(h, e, 2);
    add_left(h, e, 1);
    add_right(h, e, 11);

    add_right(h, e, 1121);
    add_right(h, e, 999);
    add_right(h, e, 123);
    add_right(h, e, 321);
    add_right(h, e, 33);

    isert(h, e, 11, 2);
    isert(h, e, 10, 3);
    isert(h, e, 123412, 999);
    
    print(h);
}