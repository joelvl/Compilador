#ifndef NODO_H_
#define NODO_H_

#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

struct Nodo;

struct Nodo{
    string name;
	string value;
    Nodo(string pName, string pValue);
};

#endif