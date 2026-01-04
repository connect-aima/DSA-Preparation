#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int v){
        data=v;
        left=right=nullptr;
    }  
};
class BinarySearchTree{

 void insert(Node* &root,int val){
        if(root==nullptr){
            root=new Node(val);
            cout << "Inserted" <<endl;
            return;
        }else if(val>root->data){
            insert(root->right,val);
        }else if(val<root->data){
            insert(root->left,val);
        }else{
            cout << "Dublicates Not allowed." << endl;
            return;
        }
    }
    Node* delNode(Node* &root,int key){
        if(root==nullptr){
            return nullptr;
        }
        if(key<root->data){
            root->left=delNode(root->left,key);
        }else if(key>root->data){
            root->right=delNode(root->right,key);
        }else{
            //actual deletion logic that covers both 0 and 1 child conditions
            //key==root
            if(root->left==nullptr){
                Node* temp=root->right;
                delete root;
                return temp;
            }else if(root->right==nullptr){
                Node* temp=root->left;
                delete root;
                return temp;
            }else{
                //root to be deleted has two childdren
                //we get inorder succesor of root (left most node in right subtree) with helper function
                Node* IS=findMin(root->right);
                //replacing data of root with data of that successor
                root->data=IS->data;
                //deleting that 
                root->right=delNode(root->right,IS->data);
            }
        }
        return root;
    }
    bool search(Node* &root,int key){
        if (root == nullptr)
        {
            return false;
        }
        if (root->data == key)
        {
            return true;
        }
        if (key < root->data)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }
    void preOrder(Node* &root){//root left right
        if (root == nullptr)
        {
            return;
        }
        cout << root->data << " ";
        inOrder(root->left);
        inOrder(root->right);
    }
    void inOrder(Node* &root){//left root right
        if (root == nullptr)
        {
            return;
        }
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    void postOrder(Node* &root){//left right root
        if (root == nullptr)
        {
            return;
        }
        inOrder(root->left);
        inOrder(root->right);
        cout << root->data << " ";
    }
    Node* findMax(Node* &root){
        if (root == nullptr)
        return nullptr;
        if (root->right == nullptr)
            return root;
        return findMax(root->right);
    }
    Node* findMin(Node* &root){
        if (root == nullptr)
            return nullptr;
        if (root->left == nullptr)
            return root;
        return findMin(root->left);
    }
};
int main() {
    
    return 0;
}