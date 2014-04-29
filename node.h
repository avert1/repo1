#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class node
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
};
#endif // NODE_H_INCLUDED
