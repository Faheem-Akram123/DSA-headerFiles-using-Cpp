#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LL
{
protected:
    Node *head;
    Node *tail;

public:
    LL()
    {
        head = nullptr;
        tail = nullptr;
    }
    virtual void insertAtHead(const int &value) = 0;
    virtual void insertAtTail(const int &value) = 0;
    virtual void insertAtPosition(const int &value, const int &pos) = 0;
    virtual bool deleteByValue(const int& value) = 0;
    virtual int deleteFromHead() = 0;
    virtual int deleteFromTail() = 0;
    virtual int deleteFromPos(const int& pos) = 0;
    virtual int searchValue(const int& value) = 0;
    virtual void updateNodeValue(const int& value,const int& pos) = 0;
    virtual bool isEmpty() = 0;
    virtual void display() = 0;
    virtual void displayR() = 0;
    ~LL()
    {
        delete head;
        delete tail;
    }
};