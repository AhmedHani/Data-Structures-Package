//============================================================================
// File        : BinarySearchTree
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 20, 2012, 06:42 AM
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

/* Binary Search Tree (BST) is a tree data structure that has some properties
 * - Every Parent Node should have 2 children at most (so it is called Binary)
 * - The left subtree of node conatines nodes that has less value(key) than the node's value
 * - The Right subtree of node conatines nodes that has greater value(key) than the node's value
 * - The Keys couldn't be repeaten
 */

template<class T>
class Node {
public:
    T Data; // Value
    Node<T> *Right; // Right Child
    Node<T> *Left; // Left Child
    Node() {
        Right = Left = NULL;
    }
    ~Node() {
        delete Right;
        delete Left;
    }
};

template<class T>
class BinarySearchTree {
private:
    void Insert(T X, Node<T>* &SubTree); // Insert a value in the BST
    void InOrderTraversing(Node<T>* SubTree); // In Order Traversing the Tree (Left -> Parent -> Right)
    void PreOrderTraversing(Node<T>* SubTree); // Pre Order Traversing the Tree (Parent -> Left -> Right)
    void PostOrderTraversing(Node<T>* SubTree); // Post Order Traversing thr Tree(Left -> Right -> Parent)
    bool Find(T X, Node<T>* SubTree); // bool Function that returns true if it finds a specefic value and returns false otherwise
    Node<T> *FindNode(T X, Node<T>* SubTree); // Returns the Specific Node
    void DeleteNode(Node<T>* &Nodex); // Delete a Node
    int Level(T X, Node<T>* Root); // Returns the Depth(Level) of the tree
    bool IsBST(Node<T>* SubTree); // Check that is it a BST or Not
    bool IsEmpty(Node<T>* Root); // Check that is the Tree Empty or Not 
    T MinimumValue(Node<T>* SubTree); // Returns the Minimum Value of the BST
    T MaximumValue(Node<T>* SubTree); // Returns the Maximum Value of the BST
};


/* To Insert an value in the BST .. we have 3 cases
 * 1)there is no Subtree .. then we will build a new one
 * 2)the value that we want to insert is less than the current SubTree value .. then Recursivly we will search in
 *   the left Childres to put it
 * 3)the Value is greater than the subtree then we will try to put it in the Right Children.
 */
template<class T>
void BinarySearchTree<T>::Insert(T X, Node<T>* &SubTree) {
    if(SubTree == NULL) {
        Node<T> *New = new Node<T>();
        SubTree = New;
    }
    if(X < SubTree->Data)       Insert(X, SubTree->Left);
    else                        Insert(X, SubTree->Right);
}

template<class T>
void BinarySearchTree<T>::InOrderTraversing(Node<T>* SubTree) {
    if(SubTree != NULL) {
        InOrderTraversing(SubTree->Left);
        //printf
        InOrderTraversing(SubTree->Right);
    }
}

template<class T>
void BinarySearchTree<T>::PostOrderTraversing(Node<T>* SubTree) {
    if(SubTree != NULL) {
        PostOrderTraversing(SubTree->Left);
        PostOrderTraversing(SubTree->Right);
        //printf
    }
}

template<class T>
void BinarySearchTree<T>::PreOrderTraversing(Node<T>* SubTree) {
    if(SubTree != NULL) {
        //printf
        PreOrderTraversing(SubTree->Left);
        PreOrderTraversing(SubTree->Right);
    }
}

/* Check is there a subtree or not .. if not return false
 * if we reach to the target .. return true
 * if the value that we want to find is less than a left SubTree .. then going to the Left Children
 * if the value is greater than the subtree .. going to the Right Nodes 
 */
template<class T>
bool BinarySearchTree<T>::Find(T X, Node<T>* SubTree) {
    if(SubTree == NULL) return false;
    if(SubTree->Data == X)      return true;
    else if(X < SubTree->Left)  return Find(X, SubTree->Left);
    else                        return Find(X, SubTree->Right);
}

/*
 * we want to return a specific Node ,, then .. we have a key that we can determine that where the Node will be
 * right or left Children .. so, of the value of Node is less than subtree node .. then , going to the Left Subtree
 * but, if we didn't find a node that have the key that we are looking for .. then BST doesn't have that node and returns NULL
 * if we Find it .. Return the Node
 * the Same Steps will be with Right Children if we the Key was greater than a subtree.
 */
template<class T>
Node<T>* BinarySearchTree<T>::FindNode(T X, Node<T>* SubTree) {
    if(X < SubTree->Data) {
        if(SubTree->Left == NULL)       return NULL;
        else if(SubTree->Left->Data == X)       return SubTree;
        else    return FindNode(X, SubTree->Left);
    } else {
        if(SubTree->Right == NULL)      return NULL;
        else if(SubTree->Right->Data == X)      return SubTree;
        else    FindNode(X, SubTree->Right);
    }
}

/*
 * Well, i remmber it took me many a while to find out how to delete a Node in BST .. and remain it as a BST :D
 * we have 4 Cases in deleting a Node from a BST .. 
 * 1) the node we want to delete is a leaf node(has no Children) .. then easily we can Delete it.
 * 2) the node has no Right Children .. then we can create a Temp Node that will hold the Left Chilren of the node .. then delete the node
 * 3) the node has no Left Chhildren .. then we do same.
 * 4) the problem appear now .. if the node has 2 childs .. then we create a Temp Node to the Right Child (or Left) 
 *    .. and thers is two cases now
 *    - if the the Temp Node has no Left Child .. then we put a Node data to the Temp Data .. then Recursivly Delete the Right Child
 *    - if the the Temp Node has no Right Child .. then we put a Node data to the Temp Data .. then Recursivly Delete the Left Child
 */
template<class T>
void BinarySearchTree<T>::DeleteNode(Node<T>* &Nodex) {
    if(Nodex->Left == NULL && Nodex->Right == NULL) {
        delete Nodex;
        Nodex = NULL;
    }
    else if(Nodex->Right == NULL) {
        Node<T>* Temp = Nodex->Left;
        delete Nodex;
        Nodex = NULL;
    } 
    else if(Nodex->Left == NULL) {
        Node<T>* Temp = Nodex->Right;
        delete Nodex;
        Nodex = NULL;
    }
    else {
        Node<T>* Temp = Nodex->Right;
        if(Temp->Left == NULL) {
            Nodex->Data = Temp->Data;
            DeleteNode(Nodex->Right);
        } else {
            while(Temp->Left != NULL) Temp = Temp->Left;
            Nodex->Data = Temp->Data;
            DeleteNode(Temp);
        }
    }
}

/*
 * 0 Based .. we will return the Level (Depth) of the Specfic Node 
 * if the the Root Data is the Specfic value we are looking for .. then it is 0 Level
 * if not .. Recursivly to the Right and Left Children .. ++Level for each Call
 */
template<class T>
int BinarySearchTree<T>::Level(T X, Node<T>* Root) {
    if(Root->Data == X)      return 0;
    else if(X < Root->Left)  return 1 + Level(X, Root->Left);
    else                        return 1 + Level(X, Root->Right);
}

/*
 * Function to figure out that is the tree is Binary Search tree or not
 * to do it .. we will check the Properites of the BST as i mentiond before.
 */
template<class T>
bool BinarySearchTree<T>::IsBST(Node<T>* SubTree) {
    if(SubTree == NULL) return true;
    if(SubTree->Right != NULL && MaximumValue(SubTree->Right) < SubTree->Data)  return false;
    if(SubTree->Left != NULL && MinimumValue(SubTree->Left) > SubTree->Data)    return false;
    return true;
}

/*
 * we want to know the Maximum Value in the BST .. Maximum value means that it must be in the final Right Child . 
 * we can do it easily with Recursion
 */
template<class T>
T BinarySearchTree<T>::MaximumValue(Node<T>* SubTree) {
    Node<T>* Temp = SubTree;
    while(Temp->Right != NULL)  Temp = Temp->Right;
    return Temp->Data;
}

/*
 * Minimum Value .. like the Maximum Function .. 
 * but here we want the Minimum Value which msut be at the final Left Child
 */
template<class T>
T BinarySearchTree<T>::MinimumValue(Node<T>* SubTree) {
    Node<T>* Temp;
    while(Temp->Left != NULL)   Temp = Temp->Left;
    return Temp->Data;
}

/*
 * if there is no Root .. then the BST has no Children .. which mean that the BST is Empty
 */
template<class T>
bool BinarySearchTree<T>::IsEmpty(Node<T>* Root) {
    return (Root == NULL);
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    BinarySearchTree<int> BST;
    
    return 0;
}

