#include <iostream>
#include <cassert>
#include <conio.h>

void insert_data(int x);
void display();
void delete_int(int x);
void reversel();
int search_int(int x);

template <typename T>
bool is_nullptr(T ptr)
{
    return ptr == nullptr;
}

bool compare_no = true;
bool compare_fn(int a, int b) { return a > b; }
bool comparison(int a, int b) { return compare_fn(a, b) == compare_no; }

void print_elem_not_found()
{
    std::cout << "\nElement not found\n";
}

struct node
{
    int data;
    node* prev;
    node* next;
};

node* top = nullptr;

int main()
{
    int channel, data;
    for (;;)
    {
        std::cout << "\n\t1. Insert    2. Delete    3. Reverse    4.Exit\n";
        std::cout << "Enter: ";
        std::cin >> channel;

        switch (channel)
        {
        case 1:
            std::cout << "Enter an element to be inserted: ";
            std::cin >> data;
            insert_data(data);
            display();
            break;
        case 2:
            std::cout << "Enter the element to be deleted: ";
            std::cin >> data;
            delete_int(data);
            display();
            break;
        case 3:
            reversel();
            break;
        default:
            return 0;
            break;
        }
    }
    assert(false);
}

int search_int(int x)
{
    int cnt = 0;
    node* search_element = top;

    while (!is_nullptr(search_element))
    {
        if (comparison(x, search_element->data))
        {
            search_element = search_element->next;
            cnt++;
        }
        else
        {
            break;
        }
    }

    return cnt;
}

void insert_data(int x)
{
    if (is_nullptr(top))
    {
        top = new node;
        top->data = x;
        top->next = nullptr;
        top->prev = nullptr;
    }
    else if (comparison(top->data, x))
    {
        node* N = new node;
        N->data = x;
        N->next = top;
        N->prev = nullptr;
        top->prev = N;
        top = N;
    }
    else
    {
        int c = search_int(x);
        node* insert_element = top;

        for (int i = 0; i < c-1; i++)
        {
            insert_element = insert_element->next;
        }
        
        node* N = new node;
        N->data = x;
        node* b = insert_element->next;

        N->prev = insert_element;
        N->next = b;
        insert_element->next = N;
        if (is_nullptr(b))
        {
            b->prev = N;
        }
    }
}

void display()
{
    std::cout << "Element in the linked list is: ";
    node* for_diplay = top;
    while (!is_nullptr(for_diplay))
    {
        std::cout << " " << for_diplay->data;
        if (is_nullptr(for_diplay->next))
        {
            break;
        }

        for_diplay = for_diplay->next;
    }
}

void delete_int(int x)
{
    node* for_delete = top;
    if (for_delete->data == x)
    {
        if (is_nullptr(for_delete->next) && is_nullptr(for_delete->prev))
        {
            top = nullptr;
            return;
        }
        for_delete->next->prev = nullptr;
        top = for_delete->next;
    }
    else
    {
        node* delsuc = for_delete->next;
        
        if (is_nullptr(for_delete) || is_nullptr(delsuc))
        {
            print_elem_not_found();
            return;
        }

        while (delsuc->data != x)
        {
            for_delete = for_delete->next;
            delsuc = delsuc->next;

            if (is_nullptr(for_delete))
            {
                print_elem_not_found();
            }
            if (is_nullptr(delsuc))
            {
                print_elem_not_found();
                return;
            }
        }
        for_delete->next = delsuc->next;

        if (!is_nullptr(delsuc->next))
        {
            delsuc->next->prev = for_delete;
        }
    }
}

void reversel()
{
    node* a = top;
    node* b, *c, *d;

    while (!is_nullptr(a))
    {
        d = a;
        c = a->next;
        b = a->prev;
        a->prev = a->next;
        a->next = b;
        a = c;
    }
    top = d;
    std::cout << "After reversing the linked list";
    display();
    
    if (compare_no)
    {
        compare_no = false;
    }
    else
    {
        compare_no = true;
    }
}
