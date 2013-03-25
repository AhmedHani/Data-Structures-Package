//============================================================================
// File        : LinkedList Stack
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 16, 2012, 05:12 AM
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
    Node *Link; // The Addreess to the next node in the list
    Node() { 
        Link = NULL;    // Intially Points to NULL
    }
    ~Node() {
        if(Link != NULL)        delete Link; // Terminate
    }
};

template<class T>
class Stack {
    Node<T> *Front;
    //Node<T> *Next;
    int Size;
public:
    Stack() {
        Size = 0;
        Front = NULL;
        //Next = NULL;
    }
    ~Stack() { delete Front; }
    void Push(T X);
    T Pop();
    T Top();
    int Length();
    bool IsEmpty();
};

template<class T>
void Stack<T>::Push(T X) {
    Node<T> *Temp = new Node<T>();
    Temp->Data = X;
    Temp->Link = Front;
    Front = Temp;
    Size++;
}

template<class T>
T Stack<T>::Pop() {
    if(IsEmpty()) { puts("It Is Empty"); return 0; }
    T data = Front->Data;
    Node<T> *Temp = Front;
    Front = Front->Link;
    Size--;
    return data;
}

template<class T>
T Stack<T>::Top() {
    if(IsEmpty()) { puts("It Is Empty"); return 0; }
    else        return Front->Data;
}

template<class T>
bool Stack<T>::IsEmpty() {
    return Front == 0;
}

template<class T>
int Stack<T>::Length() {
    return Size;
}

int main(int argc, char** argv) {
    Stack<int> S;
    S.Push(3);
    S.Push(4);
    cout << S.Top() << endl;
    S.Pop();
    cout << S.Top() << endl;
    cout << S.Length() << endl;
    
    return 0;
}

