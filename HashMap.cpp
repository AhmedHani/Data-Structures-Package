//============================================================================
// File        : Hash Map
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 28, 2012, 10:41 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
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

/*
 * Hash Map using simple simple hash function .. actually it dosen't bring good performance .. 
 * there is a better Algorithm known as DBJ2 algorthim .. i couldn't be able to understand to ...
 */

const int SIZE = 10000;

template<class T>
class HashEntry {
private:
    T Key;
    int Value;
public:
    HashEntry(T Key, int Value) {
        this->Key = Key;
        this->Value = Value;
    }
    string GetKey() {
        return Key;
    }
    int GetValue() {
        return Value;
    }
         
};

template<class T>
class HashMap {
private:
    HashEntry<T> **Table;
public:
    HashMap() {
        Table = new HashEntry<T>*[SIZE];
        memset(Table, NULL, sizeof(Table));
    }
    ~HashMap() {
        for(int i = 0; i < SIZE; i++)   if(Table[i] != NULL)    delete Table[i];
        delete[] Table;
    }
    int Get(const char *Key) {
        int Hash = ((unsigned int)Key % SIZE);
        while(Table[Hash] != NULL && Table[Hash]->GetKey() != Key) {
            Hash = (Hash + 1) % SIZE;
        }
        if(Table[Hash] == NULL) return -1;
        else                    return Table[Hash]->GetValue();
    }
    void Insert(const char* Key, int Val) {
        int Hash = ((unsigned int)Key  % SIZE);
        while(Table[Hash] != NULL && Table[Hash]->GetKey() != Key) {
            Hash = (Hash + 1) % SIZE;
        }
        if(Table[Hash] != NULL) delete Table[Hash];
        Table[Hash] = new HashEntry<T>(Key, Val);
    }
   
};

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    HashMap<string> S;
    
    return 0;
}
