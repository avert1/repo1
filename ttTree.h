#ifndef ttTree
#define ttTree


#include "node.h"

class ttTree
{
private:

public:
    node *_root;

    ttTree();
    bool ttTreeInsert(int value);
    void ttTreePrint();
    node* traverseTree(int value, node *aNode);

    void insertTwoNode(int value, node *aNode);
    void insertThreeNode(int value, node *aNode);
    void fixChildren(node *aNode, node *_tempNode);
    void inOrder(node *aNode);
    bool ttTreeDelete(int value);
    node* traverseTreeDelete(int value, node *aNode);
    node * getInOrder(node *aNode);
};
#endif // TTTREE_H_INCLUDED
