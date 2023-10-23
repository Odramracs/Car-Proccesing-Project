#include "linkedList.h"

node *linkedList::getHead()
{
    return head;
}
node* linkedList::getTail()
{
    return  tail;
}

void linkedList::setHead(node* h)
{
   head = h;
}
void linkedList::setTail(node* t)
{
    tail = t;
}

int linkedList::size()
{
    node* itc = head;
    int counter = 0;
    while (itc -> next != nullptr)
    {
        counter ++;
    }
    return  counter;
}

void linkedList::insertBack(node * input)
{
    int i = 0;
    if (head == nullptr)
    {
        head = input;
    }
    else
    {
        node* it = head;
        while (it -> next != nullptr)
        {
            it = it -> next;
        }
        it -> next = input;
        tail = it -> next;
        tail -> next = nullptr;
    }
}

void linkedList::deleteBack()
{
    if(head != nullptr)
    {
        node* itc = head;
        node* prev = head;
        while (itc->next != nullptr)
        {
            prev = itc;
            itc = itc->next;
        }
        prev->next = nullptr;
        delete itc;
    } 
    else 
    {
        cout << "head is nulptr" << endl;
    }
}

void linkedList::insertFront(node* input)
{
    input -> next = head;
    head = input;
}

void linkedList::deleteFront()
{ 
    node* itc = head;
    head = itc->next;
    delete itc;
}

void linkedList::addGivenPosition(node * input, int n)
{
    if(head != nullptr)
    {
        node *itc = head;
        node *prev = head;
        int counter = 0;
        while (counter < n && itc != nullptr)
        {
            counter++;
            prev = itc;
            itc = itc -> next;
        }
        input->next = itc;
        prev->next = input;
    }
}

void linkedList::deleteGivenPosition(int n)
{
    if(head != nullptr)
    {
        node* itc =head;
        node* prev =head;
        int counter = 0;
        while (counter < n && itc != nullptr)
        {
            counter++;
            prev = itc;
            itc = itc->next;
        }
        if(itc != nullptr)
        {
            prev -> next = itc -> next;
            delete itc;
        }
    }
}

node* linkedList::carModel(const char* model)
{
    node* itc = head;
    while(itc -> next != nullptr)
    {
        if(itc -> payload -> getModel() == model)
        {
            return itc;
        }
        itc -> next;
    }
    return nullptr;
}


void node::print() const
{
    cout << payload -> getYear() <<" " << payload -> getStatusAsCString()<< " "<< payload -> getMileage()<< " "<< payload -> getPrice() << payload -> getModel() << endl;
}

int linkedList::readCarsDB(const char* filename, STATUS stat)
{
    ifstream input;
    input.open(filename);
    if (!input.is_open()) 
    {
        return -1;
    }

    int i = 0;
    int intHelper = 0;
    int intStatus = 0;
    char buffer[1000]; 
    node* nn = new node();
    while (!input.eof()) 
    {
        nn -> payload = new car();
        input >> intHelper;
        nn -> payload -> setYear(intHelper);
        input >> intStatus;
        nn -> payload -> setStatus((STATUS) stat);
        input >> intHelper;
        nn -> payload -> setMileage(intHelper);
        input >> intHelper;
        nn -> payload -> setPrice(intHelper);
        input.getline(buffer, sizeof(buffer));
        nn -> payload -> setModel(buffer);
        if (intStatus == stat) 
        {
            if(head == nullptr){
                cout << "null" << endl;

            }
            else
            {
                head -> print();
            }
            insertBack(nn);
            cout << "counter: " << i << endl;
            head -> print();
            i++;
        }
    }
    return i;
}

node* linkedList::findNodeByModel(const char * name)
{
    node* itc = head;
    int counter = 0;
    while(itc -> next != nullptr)
    {
       // cout << "ran Once" << endl;

        if(itc -> payload -> getModel() == name)
        {
            return itc;
        }
        itc = itc -> next;
        cout << "counter at: " << counter << endl;
        counter++;

    }
    return nullptr;
}

bool linkedList::removeNode(node * in)
{
    node* itc = head -> next;
    node* prev = head;
    if(in == head)
    {
        deleteFront();
        return true;
    }
    while(itc -> next != nullptr)
    {
        if(itc == in)
        {
            prev -> next = itc -> next;
            delete itc;
            return true;
        }

    }
    return false;
}

void linkedList::printByYear(int year)
{
    node* itc = head;
    if(itc -> payload -> getYear() == year)
    {
        itc -> print();
        itc = itc -> next;
    }
}

linkedList::linkedList()
{
    head = nullptr;
    tail = nullptr;
}

linkedList::~linkedList()
{
    if(head != nullptr)
    {
        delete [] head;
    }
    if(tail != nullptr)
    {
        delete [] tail;
    }
}

node::node()
{
    next = nullptr;
    payload = nullptr;
}