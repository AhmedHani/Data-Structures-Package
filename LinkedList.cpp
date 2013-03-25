//============================================================================
// File        : LinkedList
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 15, 2012, 10:57 PM
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
class LinkedList {
    Node<T>* Head;
    /* Head is a pointer which point the first node in the list .. it isn't the node itself .. but it points to the address of the node
     * Intially Head points to the NULL for sure .. because there isn't an address
     */
    Node<T> *Tail;
    /* Like the Head .. it has the last address of the last actual Node ..  for adding elements in the linkedlist easily */
    int Size; 
    /* The size of the linked list .. on the other words .. the number of elemnts of the linkedlist*/
public:
    LinkedList() {
        Size = 0;
        Head = NULL;
        Tail = NULL;
    }
    ~LinkedList() {
        delete Head;
        /* Deleting Head means remove all the links in the linked list .. because it is a chain reaction .. 
         the head won't remove until the next romved and so on*/
    }
    void Add(T X); // Function to add data
    void Delete(T X); // Delete Data
    void Traverse(); // Traverse the LinkedList
    void Reverse();    // Print the data Reversed
    int Length();     // return the size of the list
};

/*Now .. We want to build a function to add elements to on container .. 
 First .. We create a new node .. this node will be for example a number .. The tail's next will be the temp node
 Head now points to Null beacause it is the first node*/
template<class T>
void LinkedList<T>::Add(T X){
    Node<T> *Temp; // Temp Node
    Temp = new Node<T>();
    Temp->Data = X;
    if(Size == 0) {
        Head = Temp;
        Tail = Temp;
    } else {
        Tail->Next = Temp;
        Tail = Temp;
    }
    Size++; // we add an element .. so .. the size of the list increased by one
}

/* What about deleting an element from the list ?
 linked list is like a sequence .. so .. we can make a prev. element of the element we won't delete to point to the next element of our target
 now the element won't be a part of the sequence or the chain .. but we want to delete the elements Next be null to clean its memory
 Deleting an element means Size-- */
template<class T>
void LinkedList<T>::Delete(T X) {
    Node<T> *Temp = Head;
    Node<T> *Previous = Head;
    
    for(size_t i = 0; i < Size; i++) { // iterate over the list
        if(Temp->Data == X) {
            Previous->Next = Temp->Next;
            if(Head == Temp) {
                Head = Temp->Next;
            }
            Temp->Next = NULL;
            delete Temp;
            break;
        } else {
            Previous = Temp;
            Temp = Temp->Next;
        }
    }
    Size--;
}

/* We Want top print all the elements of the list .. it is easy :D
 using a loop an a temp variable .. and reassigned to have the value of the Next during the loop */
template<class T>
void LinkedList<T>::Traverse() {
    Node<T> *Temp;
    Temp = Head;
    cout << "{ " << Temp->Data << " } ---> ";
    Temp = Temp->Next;
    while(Temp != NULL) {
        cout << "{ " << Temp->Data << " } ---> ";
        Temp = Temp->Next;
    }
    puts("END");
}

/* Reverse the Elements in the list .. Simple way is swapping*/
template<class T>
void LinkedList<T>::Reverse() {
    if(Head == NULL)    return;
    Node<T> *Previous = NULL;
    Node<T> *Temp = NULL;
    Node<T> *Next = NULL;
    Temp = Head;
    while(Temp != NULL) {
        Next = Temp->Next;
        Temp->Next = Previous;
        Previous = Temp;
        Temp = Next;
    }
    Head = Previous;
}
template<class T>
int LinkedList<T>::Length() {
    return Size;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    LinkedList<int> List;
    List.Add(1);
    List.Add(3);
    List.Add(5);
    List.Add(7);
    List.Traverse(); // Output : 1 .. 3 .. 5 .. 7 .. END
    List.Reverse(); 
    List.Traverse(); // Output : 7 .. 5 .. 3  .. 1 .. END
    List.Delete(5);
    List.Traverse(); // Output : 7  .. 3 .. 1 .. END

    return 0;
}

