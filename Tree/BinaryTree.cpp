#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//Binary Tree Implementation using recursion from Pre order sequence (root left right)

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

//code of linear time complexity
static int index=-1;
Node* buildTree(vector<int> preorder){
    index++;
    if(preorder[index]==-1){
        return nullptr;
    }
   
    Node* root = new Node(preorder[index]);
    root->left=buildTree(preorder);
    root->right=buildTree(preorder);

    return root;
}

//code of linear time complexity PREORDER
void preOrder(Node* root){
    if(root==nullptr){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//code of linear time complexity  INORDER
void inOrder(Node* root){
    if(root==nullptr){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//code of linear time complexity POSTORDER
void postOrder(Node* root){
    if(root==nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

//LEVEL ORDER TRAVERSAL BFS

void BFS(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(nullptr);
    while(q.size()>0){
        Node* curr=q.front();
        q.pop();

        if(curr==nullptr){
            if(!q.empty()){
                cout << endl;
                q.push(nullptr);
                continue;
            }else{
                break;
            }
        }
        cout << curr->data << " " ;
        if(curr->left!=nullptr){
            q.push(curr->left);
        }
        if(curr->right!=nullptr){
            q.push(curr->right);
        }
    }
    cout << endl;
}



int main() {
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(preorder);

    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postOrder(root);
    cout << endl;

    cout << "Level Order Traversal (BFS):" << endl;
    BFS(root);
    return 0;
}