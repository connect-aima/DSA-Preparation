//make a tree from pre and post order traversals 
#include <iostream>
using namespace std;
#include<queue>
#include <vector>
class Node{
public:
    string data;
    Node* left;
    Node* right;
    Node(string val){
        data=val;
        left=right=nullptr;
    }
};
Node* fromPreorderAndPostorderToFullBInaryTreeConversion(vector<string>&preOrder , vector<string>&postOrder,int &preIndex,int postStart,int postEnd){
    //check base conditions first
    if(preIndex>=preOrder.size()||postStart>postEnd){
        return nullptr;
    }
    Node* root=new Node(preOrder[preIndex]);//2-mark the main root
    preIndex++;//3-increment preindex
    // If only one element exists in this postorder segment → leaf node
    //check leaf node case
    if (postStart == postEnd)
        return root;

    //4-mark left subtree root which is right after main roont in preorder sequence
    string leftSubTree=preOrder[preIndex];
    //5-find index of root of leftsubtree in post order befor that index 
    //there will be sub branches of left subtree and after that there will be subbranches of right 
    //subtree
    int index = -1;
    for(int i=postStart;i<=postEnd;i++){
        if(postOrder[i]==leftSubTree){
            index=i;
            break;
        }
    }
    //4-Make recurssive calls for left and right subtree recursively
    root->left=fromPreorderAndPostorderToFullBInaryTreeConversion(preOrder,postOrder,preIndex,postStart,index);
    root->right=fromPreorderAndPostorderToFullBInaryTreeConversion(preOrder,postOrder,preIndex,index+1,postEnd-1);
    return root;
}
Node* buildTreeFromPreAndIn(
    vector<string>& preOrder,
    vector<string>& inOrder,          // fixed: postOrder → inOrder
    int& preIndex,
    int inStart,                      // fixed: postStart → inStart
    int inEnd                         // fixed: postEnd → inEnd
) {
    // base condition
    if (preIndex >= preOrder.size() || inStart > inEnd) // fixed
        return nullptr;

    // create root from preorder
    Node* root = new Node(preOrder[preIndex]); // same logic
    preIndex++;

    // leaf node case
    if (inStart == inEnd)                        // fixed
        return root;

    // find root in inorder
    int index = -1;
    for (int i = inStart; i <= inEnd; i++) {     // fixed
        if (inOrder[i] == root->data) {          // fixed
            index = i;
            break;
        }
    }

    // build left and right subtrees
    root->left = buildTreeFromPreAndIn(
        preOrder, inOrder, preIndex,
        inStart, index - 1                       // fixed
    );

    root->right = buildTreeFromPreAndIn(
        preOrder, inOrder, preIndex,
        index + 1, inEnd                         // fixed
    );

    return root;
}

void levelOrderTraversals(Node* &root){
    if(!root){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int levelsize=q.size();
        while ((levelsize--))
        {
            Node* current=q.front();
            q.pop();
            cout << current->data << " ";
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }
    }
}
int main() {
    vector<string> preorder = {"CEO",  "Manager1", "TeamLead1",
                             "Dev1", "Dev2",     "TeamLead2",
                             "Dev3", "Dev4",     "Manager2"};

  vector<string> postorder = {"Dev1",     "Dev2",     "TeamLead1",
                              "Dev3",     "Dev4",     "TeamLead2",
                              "Manager1", "Manager2", "CEO"};

  
  int preIndex = 0;

  
  Node *root =fromPreorderAndPostorderToFullBInaryTreeConversion(preorder, postorder, preIndex, 0, postorder.size() - 1);
  levelOrderTraversals(root);
    return 0;
}
