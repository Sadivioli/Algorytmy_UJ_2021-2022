#ifndef LLIST_H
#define LLIST_H
#pragma once
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>  
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data);
        ~Node();
};

class List{
    public:
        List();
        ~List();
        virtual bool insert(int, int){return false;} 
        virtual bool remove(int){return false;}
        virtual int retrive(int){return -1;} 
        virtual int locate(int){return -1;}
        virtual int len(){return 0;}
        virtual bool isEmpty(){return false;}
        virtual Node first(){return 0;}
        virtual Node last(){return 0;}
        virtual int front(){return 0;}
        //virtual void pop_front(){}
        virtual int back(){return 0;}
        //virtual void pop_back(){}
        virtual bool validIndex(int){return false;}
        virtual bool push_back(int){return false;} 
        virtual bool push_front(int){return false;}
        virtual void printList(){}
        virtual bool pop_front(){return false;}
        virtual bool pop_back(){return false;}
        virtual void rmDupes(){}
        virtual void rmVal(){}
        virtual void reverse(){}
        virtual void rmEvenIndex(){}
};

class LinkedList : public List{
    private:
        Node *head;
        Node *tail;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        bool insert(int, int); 
        bool remove(int);
        int retrive(int); 
        int locate(int);
        int len();
        bool isEmpty();
        Node first();
        Node last();
        int front();
        int back();
        bool validIndex(int);
        bool push_back(int); 
        bool push_front(int);
        void printList(); 
        bool pop_front();
        bool pop_back(); 
        void rmDupes();
        void rmVal(int);
        void reverse();
        void rmEvenIndex();
};

#endif