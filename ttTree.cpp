//Avery Horton
#include "ttTree.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
using namespace std;
#define null 0

/*class ttTree
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
};*/

ttTree::ttTree(){
    //_root = null;
    _root = new node();
    _root->_parent = null;
    _root->_leftChild = null;
    _root->_rightChild = null;
    _root->_middleChild = null;
}


bool ttTree::ttTreeInsert(int value)
{
    //Find the location in the tree where the value needs to be inserted
    if(_root == null){
        _root = new node();
        _root->_leftValue = value;
    }
    node *aNode = traverseTree(value, _root);
    //If aNode == null, then a match was already found
    if(aNode ==null){
            cout<<"inshere0";
    cout<<endl;
        return 0;
    }
    cout<<"inshere1";
    cout<<endl;
    if (aNode->_leftValue == null){
        aNode->_leftValue =value;
        return true;
    }
    //If node is a 2 node, just insert value
    cout<<"inshere2";
    cout<<endl;
    if (aNode->_rightValue ==null){
        insertTwoNode(value, aNode);
        return true;
    }

    //If node is a 3 node, more difficult
    insertThreeNode(value, aNode);

}

node* ttTree::traverseTree(int value, node *aNode)
{
    //If node only has one key
    //keys will be stored in leftValue by default

    //If value is equal to any of the keys in node, key is already in tree
    if(value == aNode->_leftValue || value == aNode->_rightValue){
        return null;
    }
    //If all children are null then node is a leaf
    if(aNode->_leftChild == null&&aNode->_middleChild == null){
        return aNode;
    }

    if(aNode->_middleChild == null){
        //This node only has 2 children
            if(value < aNode->_leftValue){
                aNode =traverseTree(value, aNode->_leftChild);
            }
            else{
                aNode =traverseTree(value, aNode->_rightChild);
            }
    }
    else {
        //This node has 3 children
        if(value < aNode->_leftValue){
                aNode =traverseTree(value, aNode->_leftChild);
            }
            else if(value > aNode->_rightValue){
                aNode =traverseTree(value, aNode->_rightChild);
            }
            else{
                aNode =traverseTree(value, aNode->_middleChild);
            }
    }
    return aNode;
}


void ttTree::insertTwoNode(int value, node *aNode) {

    if(aNode->_leftValue ==null){
        aNode->_leftValue = value;
    }
    else if(value > aNode->_leftValue){
        aNode->_rightValue = value;
        cout<<"dfgdf";
        cout<<endl;
    }
    else{
        aNode->_rightValue = aNode->_leftValue;
        aNode->_leftValue = value;
    }
}

void ttTree::insertThreeNode(int value, node *aNode) {
cout<<"ins3here";
cout<<endl;
    node *_tempNode;
    //first just insert, using middlevalue as a placeholder
    if(value < aNode->_leftValue){
        aNode->_middleValue = aNode->_leftValue;
        aNode->_leftValue = value;
    }
    else if(value > aNode->_rightValue){
        aNode->_middleValue = aNode->_rightValue;
        aNode->_rightValue = value;
        cout<<"ins3here1";
        cout<<endl;
    }
    else {
        aNode->_middleValue = value;
    }

    //Now, move up and split children
    //Once again, if node is a 2 node, will be easy
    //dont forget to add case where parent is null
    if(aNode->_parent == null){
          cout<<"ins3here1.5";
        cout<<endl;
        aNode->_parent = new node();
        _root = aNode->_parent;
    }
    cout<<"ins3here2";
        cout<<endl;
    if(aNode->_parent->_rightValue == null){
        insertTwoNode(aNode->_middleValue, aNode->_parent);
        cout<<"ins3here3";
        cout<<endl;
        //Check and see if the value was inserted to left or right
        if(aNode->_middleValue == aNode->_parent->_leftValue){
                cout<<"ins3here4";
                cout<<endl;
                //split the node
                if(aNode->_parent->_rightValue == null){
                    node *bNode = new node();
                    aNode->_parent->_leftChild = bNode;
                    bNode->_leftValue = aNode->_leftValue;
                    bNode->_parent= aNode->_parent;
                    aNode->_parent->_rightChild = aNode;
                    aNode->_leftValue = aNode->_rightValue;
                    _tempNode = bNode;
                    cout<<"ins3here4.5";
                    cout<<endl;
                    aNode->_rightValue = null;
                    aNode->_middleValue = null;

                     //Find out which node to call it on
                     cout<<"ins3here4.55";
                    cout<<endl;
                    if(aNode->_middleChild != null){
                        if(aNode->_middleChild->_middleValue != null){
                                cout<<"ins3here4.6";
                        cout<<endl;
                            fixChildren(aNode->_middleChild, _tempNode);
                        }
                    }
                    if(aNode->_leftChild != null){
                        if(aNode->_leftChild->_middleValue != null){
                            cout<<"ins3here4.7";
                        cout<<endl;
                            fixChildren(aNode->_leftChild, _tempNode);
                        }
                    }
                    if(aNode->_rightChild != null){
                        if(aNode->_rightChild->_middleValue != null){
                            cout<<"ins3here4.8";
                        cout<<endl;
                            fixChildren(aNode->_rightChild, _tempNode);
                        }
                    }
                    else{
                    }
                    cout<<"ins3here4.9";
                    cout<<endl;
                }

            else{
                //aNode._parent._leftChild = aNode;
                node *bNode = new node();
                aNode->_parent->_leftChild = bNode;
                bNode->_leftValue = aNode->_leftValue;
                bNode->_parent= aNode->_parent;
                aNode->_parent->_middleChild = aNode;
                aNode->_leftValue = aNode->_rightValue;
                cout<<"ins3here5";
                cout<<endl;
                aNode->_rightValue = null;
                aNode->_middleValue = null;
                _tempNode = bNode;

                if(aNode->_middleChild != null){
                        if(aNode->_middleChild->_middleValue != null){
                                cout<<"ins3here5.6";
                        cout<<endl;
                            fixChildren(aNode->_middleChild, _tempNode);
                        }
                    }
                    if(aNode->_leftChild != null){
                        if(aNode->_leftChild->_middleValue != null){
                            cout<<"ins3here5.7";
                        cout<<endl;
                            fixChildren(aNode->_leftChild, _tempNode);
                        }
                    }
                    if(aNode->_rightChild != null){
                        if(aNode->_rightChild->_middleValue != null){
                            cout<<"ins3here5.8";
                        cout<<endl;
                            fixChildren(aNode->_rightChild, _tempNode);
                        }
                    }
                    else{
                    }
                    cout<<"ins3here5.9";
                    cout<<endl;
            }
        }
        else{
                cout<<"ins3here6.1";
                    cout<<endl;
             aNode->_parent->_rightChild = aNode;
            //create a new node
            node *bNode = new node();
            aNode->_parent->_middleChild = bNode;
            bNode->_leftValue = aNode->_leftValue;
            bNode->_parent = aNode->_parent;
            //change leftValue to rightValue, because we use left if there is only 1 key
            aNode->_leftValue = aNode->_rightValue;
            aNode->_rightValue = null;
            aNode->_middleValue = null;

            _tempNode = bNode;
            //Find out which node to call it on
            if(aNode->_middleChild != null){
                        if(aNode->_middleChild->_middleValue != null){
                                cout<<"ins3here6.6";
                        cout<<endl;
                            fixChildren(aNode->_middleChild, _tempNode);
                        }
                    }
                    if(aNode->_leftChild != null){
                        if(aNode->_leftChild->_middleValue != null){
                            cout<<"ins3here6.7";
                        cout<<endl;
                            fixChildren(aNode->_leftChild, _tempNode);
                        }
                    }
                    if(aNode->_rightChild != null){
                        if(aNode->_rightChild->_middleValue != null){
                            cout<<"ins3here6.8";
                        cout<<endl;
                            fixChildren(aNode->_rightChild, _tempNode);
                        }
                    }
                    else{
                    }
                    cout<<"ins3here6.9";
                    cout<<endl;
        }
    }

    //Otherwise the parent already has 2 keys
    else{
            cout<<"ins3here6.1";
        cout<<endl;
        insertThreeNode(aNode->_middleValue, aNode->_parent);
    }
                cout<<"ins3here8";
        cout<<endl;

}

void ttTree::fixChildren(node *aNode, node *_tempNode) {

    cout<<"ins3here7";
                        cout<<endl;

                        cout<<_tempNode->_leftValue;
        cout<<endl;
    node * _tempNode2;
    //Always keep original node as right child. Will save some coding
    if(aNode->_middleValue == null){
            //Then you no longer need to break things apart
        return;
    }
         aNode->_middleValue = null;
        if(aNode == aNode->_parent->_middleChild){
            if(_tempNode->_leftValue < aNode->_rightValue){
                _tempNode->_leftChild = aNode->_parent->_leftChild;
                _tempNode->_leftChild->_parent = _tempNode;
                _tempNode->_rightChild = new node();
                _tempNode->_rightChild->_leftValue = aNode->_leftValue;
                _tempNode2 = _tempNode->_rightChild;
                aNode->_leftValue = aNode->_rightValue;
                aNode->_rightValue = null;
                _tempNode->_rightChild->_parent = _tempNode;
                aNode->_parent->_leftChild = aNode;
                //Parent's right child stays the same
                aNode->_parent->_middleChild = null;
            }
            else {

            }
        }
        else if(aNode == aNode->_parent->_leftChild){
                if(_tempNode->_leftValue < aNode->_rightValue){
                        cout<<"ins3here7.1";
                        cout<<endl;
                _tempNode->_leftChild = new node();
                _tempNode->_leftChild->_leftValue = aNode->_leftValue;
                _tempNode2 = _tempNode->_leftChild;
                aNode->_leftValue = aNode->_rightValue;
                aNode->_rightValue = null;
                _tempNode->_rightChild = aNode;
                aNode->_parent->_leftChild = aNode->_parent->_middleChild;
                //Parent's right child stays the same
                aNode->_parent->_middleChild = null;
                _tempNode->_leftChild->_parent = _tempNode;
                _tempNode->_rightChild->_parent = _tempNode;
                //aNode->_parent->_middleChild = null;
            }
            else {

            }
        }
        else if(aNode == aNode->_parent->_rightChild) {
                if(_tempNode->_leftValue < aNode->_rightValue){
                _tempNode->_leftChild = aNode->_parent->_leftChild;
                _tempNode->_rightChild = aNode->_parent->_middleChild;
                aNode->_parent->_leftChild = new node();
                _tempNode2 = aNode->_parent->_leftChild;
                aNode->_parent->_leftChild->_leftValue = aNode->_leftValue;
                aNode->_leftValue = aNode->_rightValue;
                aNode->_rightValue = null;
                _tempNode->_leftChild->_parent = _tempNode;
                _tempNode->_rightChild->_parent = _tempNode;
                //Parent's right child stays the same
                aNode->_parent->_middleChild = null;
            }
            else {

            }
        }

        //aNode->_middleValue = null;
        //Rerun
         if(aNode->_middleChild != null){
                        if(aNode->_middleChild->_middleValue != null){
                                cout<<"ins3here7.6";
                        cout<<endl;
                            fixChildren(aNode->_middleChild, _tempNode2);
                        }
                    }
                    if(aNode->_leftChild != null){
                        if(aNode->_leftChild->_middleValue != null){
                            cout<<"ins3here7.7";
                        cout<<endl;
                            fixChildren(aNode->_leftChild, _tempNode2);
                        }
                    }
                    if(aNode->_rightChild != null){
                        if(aNode->_rightChild->_middleValue != null){
                            cout<<"ins3here7.8";
                        cout<<endl;
                            fixChildren(aNode->_rightChild, _tempNode2);
                        }
                    }
                    else{
                    }
}

bool ttTree::ttTreeDelete(int value)
{
    //Find the location in the tree where the value needs to be deleted
    if(_root == null){
        return 0;
    }
    node *aNode = traverseTreeDelete(value, _root);
    //If aNode == null, then a match was not
    if(aNode ==null){
            cout<<"inshere0";
    cout<<endl;
        return 0;
    }
    cout<<"inshere1";
    cout<<endl;
    //if node is not leaf, swap with inorder sucessor
    if(aNode->_leftChild !=null){
            cout<<"delhere0.1";
    cout<<endl;
        if(value ==aNode->_leftValue){
            cout<<"delhere0.2";
    cout<<endl;
            //swap with inOrder successor
            node *leaf = null;
            if(aNode->_middleChild != null){
                leaf = getInOrder(aNode->_middleChild);
            }
            else{
                cout<<"delhere0.3";
    cout<<endl;
                leaf = getInOrder(aNode->_rightChild);
                cout<<aNode->_rightChild->_leftValue;
    cout<<endl;
            }
            aNode->_leftValue = leaf->_leftValue;
            leaf->_leftValue = value;
    cout<<"delhere0.4";
    cout<<endl;
            ttTreeDelete(leaf->_leftValue);

            /*if(aNode->_rightValue != null){
                //successor is middleChild
                aNode->_leftValue = aNode->_middleChild->_leftValue;
                aNode->_middleChild->_leftValue = value;
            }*/
           //else {
                //successor is rightChild
                //node *leaf = getInOrder(value);
            //}
        //If node is a 2 node, just insert value
        }
        else{
            //value is rightValue, swap with rightChild. Also know that there is another value
            node *leaf = getInOrder(aNode->_rightChild);
            aNode->_rightValue = leaf->_leftValue;
            leaf->_leftValue = value;
            ttTreeDelete(leaf->_leftValue);

        }
    }
    //node is leaf
    else{
            cout<<"delhere1";
    cout<<endl;
        if(aNode->_leftValue == value){
            aNode->_leftValue = null;
            //If node has another value, just replaces
            if(aNode->_rightValue != null){
                aNode->_leftValue = aNode->_rightValue;
                aNode->_rightValue = null;
            }
            //Otherwise, 3 cases
            /*else*/while (aNode->_leftValue == null) {
                    //Case 1
                if(aNode ==_root){
                    if (aNode->_leftChild !=null) {
                        _root = aNode->_leftChild;
                        aNode = aNode->_leftChild;
                    }
                    else if (aNode->_rightChild !=null) {
                        _root = aNode->_rightChild;
                        aNode = aNode->_rightChild;
                    }
                    //Tree is empty
                    else{
                        _root = null;
                        aNode = null;
                    }
                }

                //Case 2
                else if(aNode->_parent->_middleChild != null &&
                        ((aNode->_parent->_leftChild->_rightValue!=null && aNode == aNode->_parent->_middleChild)
                            || (aNode->_parent->_rightChild->_rightValue!=null && aNode == aNode->_parent->_middleChild) || aNode->_parent->_middleChild->_rightValue!=null)){
                    if(aNode->_parent->_leftChild->_rightValue!=null||aNode->_parent->_rightChild->_rightValue!=null){
                        if(aNode->_parent->_leftChild->_rightValue!=null){
                        //if left child is the one with 2 keys. Node can only be middle
                            if (aNode == aNode->_parent->_middleChild){
                                aNode->_leftValue = aNode->_parent->_leftValue;
                                aNode->_parent->_leftValue = aNode->_parent->_leftChild->_rightValue;
                                aNode->_parent->_leftChild->_rightValue = null;
                                //dont forget to add children
                                aNode->_leftChild = aNode->_parent->_leftChild->_rightChild;
                                aNode->_parent->_leftChild->_rightChild = aNode->_parent->_leftChild->_middleChild;
                                aNode->_parent->_leftChild->_middleChild = null;
                            }

                        }
                        else if(aNode->_parent->_middleChild->_rightValue!=null){
                        //if middle child is the one with 2 keys. Node could be middle or right
                            if (aNode == aNode->_parent->_leftChild){
                                aNode->_leftValue = aNode->_parent->_leftValue;
                                aNode->_parent->_leftValue = aNode->_parent->_middleChild->_leftValue;
                                aNode->_parent->_middleChild->_leftValue = aNode->_parent->_middleChild->_rightValue;
                                aNode->_parent->_middleChild->_rightValue = null;
                                //dont forget to add children
                                aNode->_rightChild = aNode->_parent->_middleChild->_leftChild;
                                aNode->_parent->_middleChild->_leftChild = aNode->_parent->_middleChild->_middleChild;
                                aNode->_parent->_middleChild->_middleChild = null;
                            }
                            else{
                                //It is right child.
                                aNode->_leftValue = aNode->_parent->_rightValue;
                                aNode->_parent->_rightValue = aNode->_parent->_middleChild->_rightValue;
                                aNode->_parent->_middleChild->_rightValue = null;
                                //dont forget to add children
                                aNode->_leftChild = aNode->_parent->_middleChild->_rightChild;
                                aNode->_parent->_middleChild->_rightChild = aNode->_parent->_middleChild->_middleChild;
                                aNode->_parent->_middleChild->_middleChild = null;
                            }

                        }
                        else if(aNode->_parent->_rightChild->_rightValue!=null){
                        //if right child is the one with 2 keys. Node can only be middle
                            if (aNode == aNode->_parent->_middleChild){
                                aNode->_leftValue = aNode->_parent->_rightValue;
                                aNode->_parent->_rightValue = aNode->_parent->_rightChild->_leftValue;
                                aNode->_parent->_rightChild->_leftValue = aNode->_parent->_rightChild->_rightValue;
                                aNode->_parent->_rightChild->_rightValue = null;
                                //dont forget to add children
                                aNode->_rightChild = aNode->_parent->_rightChild->_leftChild;
                                aNode->_parent->_rightChild->_leftChild = aNode->_parent->_rightChild->_middleChild;
                                aNode->_parent->_rightChild->_middleChild = null;
                            }
                        }
                    }
                }
                //Case 2 for parent with only 2 children
                else if(aNode->_parent->_middleChild == null && (aNode->_parent->_leftChild->_rightValue!=null || aNode->_parent->_rightChild->_rightValue!=null)) {
                    if(aNode->_parent->_leftChild->_rightValue!=null){
                        //we know aNode is right child because doesn't have 2 values
                        aNode->_leftValue = aNode->_parent->_leftValue;
                        aNode->_parent->_leftValue = aNode->_parent->_leftChild->_rightValue;
                        aNode->_parent->_leftChild->_rightValue = null;
                        //dont forget to add children
                        aNode->_leftChild = aNode->_parent->_leftChild->_rightChild;
                        aNode->_parent->_leftChild->_rightChild = aNode->_parent->_leftChild->_middleChild;
                        aNode->_parent->_leftChild->_middleChild = null;


                    }
                    else {
                        //we know aNode is left child
                        aNode->_leftValue = aNode->_parent->_leftValue;
                        aNode->_parent->_leftValue = aNode->_parent->_rightChild->_leftValue;
                        aNode->_parent->_rightChild->_leftValue = aNode->_parent->_rightChild->_rightValue;
                        aNode->_parent->_rightChild->_rightValue = null;
                        //dont forget to add children
                        aNode->_rightChild = aNode->_parent->_rightChild->_leftChild;
                        aNode->_parent->_rightChild->_leftChild = aNode->_parent->_rightChild->_middleChild;
                        aNode->_parent->_leftChild->_middleChild = null;

                    }
                }
                //Case 3
                else{
                        cout<<"delhere2";
                            cout<<endl;
                    node *parent = aNode->_parent;
                    if(aNode->_parent->_middleChild != null){
                            cout<<"delhere2.5";
                            cout<<endl;
                    cout<<aNode->_parent->_middleChild->_leftValue;
                            cout<<endl;
                        //Parent node has 3 children
                        if(aNode == aNode->_parent->_leftChild){
                                cout<<"delhere3";
                            cout<<endl;
                            aNode->_parent->_middleChild->_rightValue = aNode->_parent->_middleChild->_leftValue;
                            aNode->_parent->_middleChild->_leftValue = aNode->_parent->_leftValue;
                            aNode->_parent->_leftValue= aNode->_parent->_rightValue;
                            aNode->_parent->_rightValue = null;
                            aNode->_parent->_leftChild = aNode->_parent->_middleChild;
                            aNode->_parent->_middleChild = null;
                            aNode = null;
                            aNode = parent;
                            //rightchild stays the same
                        }
                        else if(aNode == aNode->_parent->_middleChild){
                            cout<<"delhere4";
                            cout<<endl;
                            aNode->_parent->_leftChild->_rightValue = aNode->_parent->_leftValue;
                            aNode->_parent->_leftValue= aNode->_parent->_rightValue;
                            aNode->_parent->_rightValue = null;
                            aNode->_parent->_middleChild = null;
                            aNode = null;
                            aNode = parent;
                            //rightchild stays the same
                        }
                         else {
                             cout<<"delhere5";
                            cout<<endl;
                                //We know node is the right child
                            aNode->_parent->_middleChild->_rightValue = aNode->_parent->_rightValue;
                            //aNode->_parent->_leftValue= aNode->_parent->_rightValue;
                            aNode->_parent->_rightChild = aNode->_parent->_middleChild;
                            aNode->_parent->_rightValue = null;
                            aNode->_parent->_middleChild = null;
                            aNode = null;
                            aNode = parent;
                            //leftchild stays the same
                        }

                    }
                    else{
                            cout<<"delhere3";
                            cout<<endl;
                        //Parentnode has 2 children
                        if(aNode == aNode->_parent->_leftChild){
                            aNode->_parent->_rightChild->_rightValue = aNode->_parent->_rightChild->_leftValue;
                            aNode->_parent->_rightChild->_leftValue = aNode->_parent->_leftValue;
                            aNode->_parent->_leftValue= aNode->_parent->_rightValue;
                            aNode->_parent->_leftChild = null;
                            //reorder children
                            aNode->_parent->_rightChild->_middleChild = aNode->_parent->_rightChild->_leftChild;
                            aNode->_parent->_rightChild->_leftChild = aNode->_rightChild;
                            aNode = null;
                            aNode = parent;
                        }
                        else {
                            aNode->_parent->_leftChild->_rightValue = aNode->_parent->_leftValue;
                            aNode->_parent->_leftValue= aNode->_parent->_rightValue;
                            aNode->_leftValue = null;
                            aNode->_parent->_rightChild = null;
                            //reorder children
                            aNode->_parent->_leftChild->_middleChild = aNode->_parent->_leftChild->_rightChild;
                            aNode->_parent->_leftChild->_rightChild = aNode->_leftChild;
                            aNode = null;
                            aNode = parent;
                        }
                    }
                }
            }
        }
        //Node has 2 values, can just get rid of right value
        else{
            aNode->_rightValue = null;
            return 1;
        }

    }
    return 1;
}

//Returns the node you're looking for, or null if leaf wasn't found
node* ttTree::traverseTreeDelete(int value, node *aNode)
{
    //If node only has one key
    //keys will be stored in leftValue by default

    //If value is equal to any of the keys in node, key is already in tree
    if(aNode == null){
        return null;
    }
    if(value == aNode->_leftValue || value == aNode->_rightValue){
        return aNode;
    }
    //If all children are null then node is a leaf
    if(aNode->_middleChild == null){
        //This node only has 2 children
            if(value < aNode->_leftValue){
                aNode =traverseTreeDelete(value, aNode->_leftChild);
            }
            else{
                aNode =traverseTreeDelete(value, aNode->_rightChild);
            }
    }
    else {
        //This node has 3 children
        if(value < aNode->_leftValue){
                aNode =traverseTreeDelete(value, aNode->_leftChild);
            }
            else if(value > aNode->_rightValue){
                aNode =traverseTreeDelete(value, aNode->_rightChild);
            }
            else{
                aNode =traverseTreeDelete(value, aNode->_middleChild);
            }
    }
    return aNode;
}

node * ttTree::getInOrder(node *aNode) {
    //If node is a leaf, print its values
    if(aNode->_leftChild == null){
        return aNode;
    }
    getInOrder(aNode->_leftChild);

}

void ttTree::ttTreePrint() {
    inOrder(_root);
}
void ttTree::inOrder(node *aNode) {
    //If node is a leaf, print its values
    if(aNode == null){
        return;
    }
    if(aNode->_leftChild == null){
        if(aNode->_leftValue != null)
            cout <<"("<< aNode->_leftValue;
        if(aNode->_rightValue != null){
            cout <<", "<< aNode->_rightValue;
        }
        cout<<")";
    }
    else if (aNode->_leftValue != null &&aNode->_rightValue != null) {
        cout <<"(";
        inOrder(aNode->_leftChild);
        cout<<", "<<aNode->_leftValue<<", ";
        inOrder(aNode->_middleChild);
        cout <<", "<< aNode->_rightValue<<", ";
        inOrder(aNode->_rightChild);
        cout <<")";
    }

    else {
        cout <<"(";
        inOrder(aNode->_leftChild);
        cout <<", "<< aNode->_leftValue<<", ";
        inOrder(aNode->_rightChild);
        cout <<")";
    }

}

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

