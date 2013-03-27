//============================================================================
// File        : Double Ended Queue
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 25, 2012, 08:01 PM
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
    T Data; 
    Node<T> *Next;
    Node<T> *Previous; 
    Node() {
        Next = Previous = NULL;
    }
    ~Node() {
        delete Next;
        delete Previous;
    }
};

template<class T>
class Dequeue {
    Node<T>* List;
    Node<T>* Head;
public:
    Dequeue() { Head = NULL; }
    void PushBack(T X);
    void PushFront(T X);
    void PopBack();
    void PopFront();
    void Display();
};

template<class T>
void Dequeue<T>::PushFront(T X) {
    Node<T>* Temp = new Node<T>();
    Temp->Data = X;
    List = Head;
    if(List == NULL) {
        Head = Temp;
        Temp->Next = NULL;
        Temp->Previous = NULL;
        return;
    } 
    Temp->Next = List;
    Temp->Previous = NULL;
    List->Previous = Temp;
    Head = Temp;
}

template<class T>
void Dequeue<T>::PushBack(T X) {
    Node<T>* Temp = new Node<T>();
    Temp->Data = X;
    List = Head;
    if(List == NULL) {
        Head = Temp;
        Temp->Next = NULL;
        Temp->Previous = NULL;
        return;
    } 
    while(List->Next != NULL)   List = List->Next;
    List->Next = Temp;
    Temp->Previous = List;
    Temp->Next = NULL;
}

template<class T>
void Dequeue<T>::PopFront() {
    List = Head;
    List->Next->Previous = NULL;
    Head = List->Next;
}

template<class T>
void Dequeue<T>::PopBack() {
    List = Head;
    while(List->Next->Next != NULL) {
        List = List->Next;
    }
    List->Next = NULL;
}

template<class T>
void Dequeue<T>::Display() {
    Node<T>* Temp;
    List = Head;
    if(Head == NULL) {
        puts("It is Empty");
        return;
    }
    puts("Front");
    while(List != NULL) {
        cout << List->Data << "  ";
        if(List->Next == NULL)  Temp = List;
        List = List->Next;
    }
    puts("");
    List = Temp;
    puts("Back");
    while(List != NULL) {
        cout << List->Data << "  ";
        List = List->Previous;
    }
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    Dequeue<int> D;
    
    return 0;
}
