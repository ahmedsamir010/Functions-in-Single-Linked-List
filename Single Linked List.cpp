﻿#include<iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
class linked {
private:
    node* head = NULL;
public:
    void insertfirst(int value);
    void insertlast(int value);
    void insertpos(int vlaue, int pos);
    void deltfirst();
    void deltlast();
    void deltpos(int pos);
    void display();
};
int main()
{
    linked s;
    s.insertfirst(10);
    s.insertfirst(20);
    s.insertfirst(30);
    s.insertfirst(40);
    s.insertfirst(50);
    s.display();// 50  40  30  20  10
    s.insertpos(90, 3);
    s.insertlast(70);
    s.insertfirst(50);
    s.display();// 50 50 40 90 30 20 10 70
    s.deltfirst();
    s.deltpos(3);
    s.deltlast();
    s.display();//50  40 30  20  10  
    return 0;
}

void linked::insertfirst(int value)
{
    node* newNode = new node;
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }

}

void linked::insertlast(int value)
{
    node* newNode = new node;
    node* temp = head;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void linked::insertpos(int value, int pos)
{
    node* newNode = new node;
    newNode->data = value;
    node* temp = head;node* pre = NULL;
    for (int i = 1;i < pos;i++) {
        pre = temp;
        temp = temp->next;
    }
    pre->next = newNode;
    newNode->next = temp;
}
void linked::deltfirst()
{
    node* temp = new node;
    temp = head;
    head = head->next;
    delete temp;
}

void linked::deltlast()
{
    node* rev = new node;
    node* prev = new node;
    prev = NULL;
    rev = head;
    while (rev->next != NULL) {
        prev = rev;
        rev = rev->next;
    }
    prev->next = NULL;
    delete rev;

}

void linked::deltpos(int pos)
{
    node* cur = new node;
    node* pre = new node;
    cur = head;pre = NULL;
    if (head == NULL) {
        delete cur;
        return;
    }
    else {
        for (int i = 1;i < pos;i++)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
    }
}

void linked::display()
{
    node* cur = new node;
    cur = head;
    while (cur != NULL) {
        cout << cur->data << "\t";
        cur = cur->next;
    }
    cout << endl;
}