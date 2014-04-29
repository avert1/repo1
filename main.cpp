#include "ttTree.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
using namespace std;
#define null 0

int main(int argc, char *argv[])
{
    ttTree *aTree = new ttTree();
    cout<<"here";
    cout<<endl;
    /*aTree->ttTreeInsert(37);
    //aTree->ttTreePrint();
    aTree->ttTreeInsert(50);
    //aTree->ttTreePrint();
    aTree->ttTreeInsert(30);
    aTree->ttTreeInsert(39);
    aTree->ttTreeInsert(70);
    aTree->ttTreeInsert(90);
    aTree->ttTreeInsert(10);
    aTree->ttTreeInsert(36);
    aTree->ttTreeInsert(20);
    aTree->ttTreeInsert(38);
    aTree->ttTreeInsert(40);
    aTree->ttTreeInsert(60);
    aTree->ttTreeInsert(80);
    aTree->ttTreeInsert(100);
    aTree->ttTreeInsert(35);
    aTree->ttTreeInsert(34);
    aTree->ttTreeInsert(33);
    aTree->ttTreeInsert(32);*/
    aTree->ttTreeInsert(10);
    aTree->ttTreeInsert(20);
    aTree->ttTreeInsert(30);
    aTree->ttTreeInsert(40);
    aTree->ttTreeInsert(50);
    aTree->ttTreeInsert(60);
    aTree->ttTreeInsert(70);
    aTree->ttTreeInsert(80);
    aTree->ttTreePrint();
    aTree->ttTreeInsert(90);
    aTree->ttTreeInsert(100);
    cout<<"here1";
    cout<<endl;
    aTree->ttTreePrint();

    //aTree->ttTreeDelete(100);
    aTree->ttTreePrint();
    cout<<"here2";
    cout<<endl;
    aTree->ttTreeDelete(90);
    aTree->ttTreePrint();
    aTree->ttTreeDelete(60);
    aTree->ttTreePrint();
    return 1;
}
