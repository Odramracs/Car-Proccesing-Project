#ifndef LINKEDLIST_H
#define LINKEDLIST_H
//These are the only header files allowed
//-----------------------------------------
#include <iostream>//for cin and cout
#include <iomanip>//for output formatting
#include <fstream>//for file handling
#include "car.h"
using namespace std;
//-----------------------------------------

struct node 
{
    car* payload;
    node* next;
    void print () const;
    node();
};

class linkedList 
{
    node* head;
    node* tail;
public:
    node* getHead();
    node* getTail();

    void setHead(node*);
    void setTail(node*);

    void insertBack(node*);
    void deleteBack();
    void insertFront(node* );
    void deleteFront();
    void addGivenPosition(node*, int);
    void deleteGivenPosition(int);

    void printByYear(int);
    node* carModel(const char*);
    int readCarsDB(const char*, STATUS);
    node * findNodeByModel(const char * );
    int size();
    bool removeNode(node *);
    
    linkedList();
    ~linkedList();

};
#endif