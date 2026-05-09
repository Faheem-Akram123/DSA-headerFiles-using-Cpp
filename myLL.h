#include "LinkedList.h"

class myLL : public LL
{
    void dr(Node *p);

public:
    void insertAtHead(const int &value);
    void insertAtTail(const int &value);
    void insertAtPosition(const int &value, const int &pos);
    bool deleteByValue(const int &value);
    int deleteFromHead();
    int deleteFromTail();
    int deleteFromPos(const int &pos);
    int searchValue(const int &value);
    void updateNodeValue(const int &value, const int &pos);
    void sortList();
    bool isEmpty();
    void display();
    int countList();
    void displayR();
};

void myLL::dr(Node *p)
{
    if (p == nullptr)
    {
        return;
    }
    else
    {
        dr(p->next);
        cout << p->data << " ";
    }
}

void myLL::displayR()
{
    if (head == nullptr)
        cout << "LL is empty" << endl;

    else
    {
        dr(head);
    }
}

bool myLL::isEmpty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    return false;
}

void myLL::insertAtHead(const int &value)
{
    Node *nn = new Node;
    nn->data = value;
    nn->next = nullptr;

    if (isEmpty())
    {
        head = nn;
        tail = nn;
    }
    else
    {
        nn->next = head;
        head = nn;
    }
}
void myLL::insertAtTail(const int &value)
{
    Node *nn = new Node;
    nn->data = value;
    nn->next = nullptr;

    if (isEmpty())
    {
        head = nn;
        tail = nn;
    }
    else
    {
        tail->next = nn;
        tail = nn;
    }
}
void myLL::insertAtPosition(const int &value, const int &pos)
{
    Node *nn = new Node;
    nn->data = value;
    nn->next = nullptr;

    if (isEmpty() && pos != 1)
    {
        return;
    }
    else if (pos <= 0 || pos > countList() + 1)
    {
        cout << "Invalid position" << endl;
        return;
    }
    else if (pos == 1)
    {
        insertAtHead(value);
    }
    else if (pos == countList() + 1)
    {
        insertAtTail(value);
    }
    else
    {

        Node *t = head;
        for (int i = 1; i < pos - 1; i++)
        {
            t = t->next;
        }
        Node *tn = t->next;

        t->next = nn;
        nn->next = tn;
    }
}

void myLL::display()
{
    if (!isEmpty())
    {
        Node *t = head;
        while (true)
        {
            cout << t->data << " ";
            if (t->next == nullptr)
            {
                break;
            }
            t = t->next;
        }
    }
    else
    {
        cout << "LinkedList is Empty" << endl;
    }
}

int myLL::countList()
{
    int count = 0;
    if (!isEmpty())
    {
        Node *t = head;
        while (true)
        {
            count++;
            if (t->next == nullptr)
            {
                break;
            }
            t = t->next;
        }
    }
    return count;
}

int myLL::deleteFromHead()
{
    if (isEmpty())
    {
        cout << "Linked List is Empty" << endl;
        return -1;
    }
    else
    {
        if (head == tail)
        {
            int rv = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
            return rv;
        }
        else
        {
            int rv = head->data;
            Node *t = head->next;
            delete head;
            head = t;
            return rv;
        }
    }
}

int myLL::deleteFromTail()
{
    if (isEmpty())
    {
        cout << "Linked List is Empty" << endl;
        return -1;
    }
    else
    {
        if (head == tail)
        {
            int rv = tail->data;
            delete tail;
            head = nullptr;
            tail = nullptr;
            return rv;
        }
        else
        {
            int rv = tail->data;
            Node *t = head;
            while (true)
            {
                if (t->next == tail)
                {
                    break;
                }
                t = t->next;
            }
            delete tail;
            tail = t;
            tail->next = nullptr;
            return rv;
        }
    }
}

int myLL::deleteFromPos(const int &pos)
{
    if (isEmpty())
    {
        cout << "Element not removed because Linked list is Empty" << endl;
        return -1;
    }
    else if (pos <= 0 || pos > countList())
    {
        cout << "Element not removed because Invalid position" << endl;
        return -1;
    }
    else if (pos == 1)
    {
        return deleteFromHead();
    }
    else if (pos == countList())
    {
        return deleteFromTail();
    }
    else
    {
        Node *t = head;
        for (int i = 1; i < pos - 1; i++)
        {
            t = t->next;
        }
        Node *tn = t->next;
        int rv = tn->data;
        t->next = tn->next;
        delete tn;
        return rv;
    }
}

int myLL::searchValue(const int &value)
{
    if (isEmpty())
    {
        cout << "Element not removed because Linked list is Empty" << endl;
        return -1;
    }
    else
    {
        int pos = 0;
        Node *t = head;
        while (true)
        {
            if (t->data == value)
            {
                pos++;
                return pos;
                break;
            }
            if (t->next == nullptr)
            {
                cout << "value not exit in linked list" << endl;
                return -1;
            }
            t = t->next;
        }
    }
}

void myLL::updateNodeValue(const int &value, const int &pos)
{
    if (isEmpty())
    {
        cout << "Element not removed because Linked list is Empty" << endl;
    }
    else
    {
        Node *t = head;
        if (pos < 1 || pos > countList())
        {
            cout << "Invalid position" << endl;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                t = t->next;
            }
            t->data = value;
        }
    }
}

bool myLL::deleteByValue(const int &value)
{
    if (isEmpty())
    {
        cout << "Element not removed because Linked list is Empty" << endl;
        return -1;
    }
    else
    {
        Node *t = head;
        while (true)
        {
            if (t->next->data == value)
            {
                Node *tn = t->next;
                t->next = tn->next;
                delete tn;
                return true;
            }
            t = t->next;
        }
    }
    return false;
}

void myLL::sortList()
{
    int count = countList();
    for (int i = 0; i < count; i++)
    {
        Node *curr = head;
        for (int j = i; j < count - 1; j++)
        {
            if (curr->data > curr->next->data)
            {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
            }
            curr = curr->next;
        }
    }
}
