/*
*scope implementation of bplus trees
*/
#include <iostream>
#include <string>
using namespace std;
#include "tree.h"

int main()
{
    Tree *scope = new Tree(0);
    scope->insertar(0,30,scope);
    scope->insertar(2,5,scope);
    scope->insertar(6,10,scope);
    scope->insertar(7,9,scope);
    scope->insertar(12,20,scope);
    scope->insertar(31,40,scope);
    scope->showTree(scope);
    int line=8;
    cout << "\nLine number "<< line << " tabs "<< scope->getTabs(scope,line);
    return 0;
}
