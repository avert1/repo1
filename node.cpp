#include <string>
#include <stdio.h>
#include "node.h"
#define null 0
/*class node
{
private:
    //array which will store skiparray
    //vector<vector<int> > kmpSkipArray;
    //string searchString;

public:
    node *_leftChild;
    node *_middleChild;
    node *_rightChild;
    //child for inserting into 3 nodes
    node *_parent;
    int _leftValue;
    int _middleValue;
    int _rightValue;

    node();
};*/

node::node(){
    _leftChild = null;
    _rightChild = null;
    _middleChild = null;
    _parent = null;
    _rightValue = null;
    _middleValue = null;
    _leftValue = null;
}
