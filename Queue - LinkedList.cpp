//============================================================================
// File        : LinkedList Queue
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 16, 2012, 11:44 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

template<class T>
class Node {
public:
    T Data; // The data we want to store
    Node *Next; // The Addreess to the next node in the list
    Node() { 
        Next = NULL;    // Intially Points to NULL
    }
    ~Node() {
        if(Next != NULL)        delete Next; // Terminate
    }
};

template<class T>
class Queue {
    Node<T> *Front;
    Node<T> *Rear;
    int Size;
public:
    Queue() {
        Size = 0;
        Front = NULL;
        Rear = NULL;
    }
    ~Queue() {
        delete Front;
        //delete Rear;
    }
    void Enqueue(T X);
    T Dequeue();
    int Length();
    bool IsEmpty();
    T Top();
    T Last();
};

template<class T>
void Queue<T>::Enqueue(T X) {
    Node<T> *Temp = new Node<T>();
    Temp->Data = X;
    Temp->Next = 0;
    if(!IsEmpty()) { 
        Rear->Next = Temp;
        Rear = Temp;
    } else {
        Front = Rear = Temp;
    }
    Size++;
}

template<class T>
T Queue<T>::Dequeue() {
    if(IsEmpty()) { puts("It Is Empty"); return 0; }
    T data = Front->Data;
    Node<T> *Temp = Front;
    Front = Front->Next;
    if(Size == 1)       Rear = NULL;
    Size--;
    return data;
}

template<class T>
T Queue<T>::Top() {
    if(IsEmpty()) { puts("It Is Empty"); return 0; }
    return Front->Data;
}

template<class T>
T Queue<T>::Last() {
    if(IsEmpty()) { puts("It Is Empty"); return 0; }
    return Rear->Data;
}

template<class T>
bool Queue<T>::IsEmpty() {
    return (Front ? false : true);
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    Queue<int> Q;
    Q.Enqueue(33);
    Q.Enqueue(4);
    Q.Enqueue(444);
    cout << Q.Last() << endl;
    Q.Dequeue();
    cout << Q.Top() << endl;
    Q.Dequeue();
    cout << Q.Last() << endl;
    
    return 0;
}

