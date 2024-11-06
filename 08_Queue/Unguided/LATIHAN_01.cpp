#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

Node *front = nullptr;
Node *back = nullptr;

bool isEmpty()
{
    return front == nullptr;
}

void enqueueAntrian(string data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty())
    {
        front = back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
    cout << "Data \"" << data << "\" telah ditambahkan ke dalam antrian." << endl;
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        cout << "\nData \"" << temp->data << "\" telah dihapus dari antrian." << endl;
        delete temp;

        if (front == nullptr)
        {
            back = nullptr;
        }
    }
}

int countQueue()
{
    int count = 0;
    Node *temp = front;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue()
{
    while (!isEmpty())
    {
        dequeueAntrian();
    }
    cout << "\nAntrian telah dikosongkan.\n"
         << endl;
}

void viewQueue()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Node *temp = front;
        int index = 1;
        cout << "\nData antrian teller:" << endl;
        while (temp != nullptr)
        {
            cout << index++ << ". " << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    enqueueAntrian("Atsal");
    enqueueAntrian("Nisa");
    viewQueue();

    cout << "Jumlah antrian = " << countQueue() << endl;

    dequeueAntrian();
    viewQueue();

    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();

    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
