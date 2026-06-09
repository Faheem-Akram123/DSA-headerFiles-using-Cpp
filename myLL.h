#include "LinkedList.h"

template <class T>
class myLL : public LL<T>
{
    void dr(Node<T> *p);

public:
    void insertAtHead(const T &value);
    void insertAtTail(const T &value);
    void insertAtPosition(const T &value, const int &pos);
    bool deleteByValue(const T &value);
    T deleteFromHead();
    T deleteFromTail();
    T deleteFromPos(const int &pos);
    T searchValue(const T &value);
    void updateNodeValue(const T &value, const int &pos);
    void sortList();
    bool isEmpty();
    void display();
    int countList();
    void displayR();
};

template <class T>
void myLL<T>::dr(Node<T> *p)
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

template <class T>
void myLL<T>::displayR()
{
    if (this->head == nullptr)
        cout << "LL is empty" << endl;

    else
    {
        dr(this->head);
    }
}

template <class T>
bool myLL<T>::isEmpty()
{
    if (this->head == nullptr && this->tail == nullptr)
    {
        return true;
    }
    return false;
}

template <class T>
void myLL<T>::insertAtHead(const T &value)
{
    Node<T> *nn = new Node<T>;
    nn->data = value;
    nn->next = nullptr;

    if (isEmpty())
    {
        this->head = nn;
        this->tail = nn;
    }
    else
    {
        nn->next = this->head;
        this->head = nn;
    }
}

template <class T>
void myLL<T>::insertAtTail(const T &value)
{
    Node<T> *nn = new Node<T>;
    nn->data = value;
    nn->next = nullptr;

    if (isEmpty())
    {
        this->head = nn;
        this->tail = nn;
    }
    else
    {
        this->tail->next = nn;
        this->tail = nn;
    }
}

template <class T>
void myLL<T>::insertAtPosition(const T &value, const int &pos)
{
    Node<T> *nn = new Node<T>;
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

        Node<T> *t = this->head<T>;
        for (int i = 1; i < pos - 1; i++)
        {
            t = t->next;
        }
        Node<T> *tn = t->next;

        t->next = nn;
        nn->next = tn;
    }
}

template <class T>
void myLL<T>::display()
{
    if (!isEmpty())
    {
        Node<T> *t = this->head;
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

template <class T>
int myLL<T>::countList()
{
    int count = 0;
    if (!isEmpty())
    {
        Node<T> *t = this->head;
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

template <class T>
T myLL<T>::deleteFromHead()
{
    if (isEmpty())
    {
        cout << "Linked List is Empty" << endl;
        return T();
    }
    else
    {
        if (this->head == tail)
        {
            int rv = this->head->data;
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            return rv;
        }
        else
        {
            int rv = this->head->data;
            Node<T> *t = this->head->next;
            delete this->head;
            this->head = t;
            return rv;
        }
    }
}

template <class T>
T myLL<T>::deleteFromTail()
{
    if (isEmpty())
    {
        cout << "Linked List is Empty" << endl;
        return T();
    }
    else
    {
        if (this->head == tail)
        {
            int rv = this->tail->data;
            delete this->tail;
            this->head = nullptr;
            this->tail = nullptr;
            return rv;
        }
        else
        {
            int rv = this->tail->data;
            Node<T> *t = this->head;
            while (true)
            {
                if (t->next == this->tail)
                {
                    break;
                }
                t = t->next;
            }
            delete this->tail;
            this->tail = t;
            this->tail->next = nullptr;
            return rv;
        }
    }
}

template <class T>
T myLL<T>::deleteFromPos(const int &pos)
{
    if (isEmpty())
    {
        cout << "Element not removed because Linked list is Empty" << endl;
        return T();
    }
    else if (pos <= 0 || pos > countList())
    {
        cout << "Element not removed because Invalid position" << endl;
        return T();
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
        Node<T> *t = this->head;
        for (int i = 1; i < pos - 1; i++)
        {
            t = t->next;
        }
        Node<T> *tn = t->next;
        int rv = tn->data;
        t->next = tn->next;
        delete tn;
        return rv;
    }
}

template <class T>
T myLL<T>::searchValue(const T &value)
{
    if (isEmpty())
    {
        cout << "Element not removed because Linked list is Empty" << endl;
        return T();
    }
    else
    {
        int pos = 0;
        Node<T> *t = this->head;
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
                return T();
            }
            t = t->next;
        }
    }
}

template <class T>
void myLL<T>::updateNodeValue(const T &value, const int &pos)
{
    if (isEmpty())
    {
        cout << "Element not removed because Linked list is Empty" << endl;
    }
    else
    {
        Node<T> *t = this->head;
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

template <class T>
bool myLL<T>::deleteByValue(const T &value)
{
    if (isEmpty())
    {
        cout << "Element not removed because Linked list is Empty" << endl;
        return T();
    }
    else
    {
        Node<T> *t = this->head;
        while (true)
        {
            if (t->next->data == value)
            {
                Node<T> *tn = t->next;
                t->next = tn->next;
                delete tn;
                return true;
            }
            t = t->next;
        }
    }
    return false;
}

template <class T>
void myLL<T>::sortList()
{
    int count = countList();
    for (int i = 0; i < count; i++)
    {
        Node<T> *curr = this->head;
        for (int j = i; j < count - 1; j++)
        {
            if (curr->data > curr->next->data)
            {
                T temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
            }
            curr = curr->next;
        }
    }
}
