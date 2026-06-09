#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    node<T> *next;
};

template <class T>
class LL
{
protected:
    node<T> *head;
    node<T> *tail;

public:
    LL()
    {
        head = nullptr;
        tail = nullptr;
    }

    virtual void insertAtHead(const T &value) = 0;
    virtual void insertAtTail(const T &value) = 0;
    virtual void insertAtPosition(const T &value, const int &pos) = 0;

    virtual bool deleteByValue(const T &value) = 0;

    virtual T deleteFromHead() = 0;
    virtual T deleteFromTail() = 0;
    virtual T deleteFromPos(const int &pos) = 0;

    virtual int searchValue(const T &value) = 0;

    virtual void updateNodeValue(const T &value, const int &pos) = 0;

    virtual bool isEmpty() = 0;
    virtual void display() = 0;
    virtual void displayR() = 0;

    virtual ~LL()
    {
        delete head;
        delete tail;
    }
};