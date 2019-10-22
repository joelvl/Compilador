#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

#include "Nodo.h"

Nodo::Nodo(string pName, string pValue){
		this->name = pName;
		this->value = pValue;	
}