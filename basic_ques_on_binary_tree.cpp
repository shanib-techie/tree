#include<iostream>
#include <climits>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

void display(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}

int sum(Node* root){
    if(root ==NULL) return 0;
    return root->val + sum(root->left) + sum(root->right);
}

int size(Node* root){
    if(root==NULL) return 0;
    return 1 +  size(root->left) + size(root->right);
}

int maxele (Node* root ){
    if(root == NULL) return INT_MIN;
    int lmax = maxele(root->left);
    int rmax = maxele(root->right);
    return max(root->val,max(lmax,rmax));
}

int level (Node* root){
    if(root==NULL) return 0;
    return 1+ max(level(root->left),level(root->right));
}

int main(){
    Node* a = new Node(2);
    Node* b = new Node(5);
    Node* c = new Node(8);
    Node* d = new Node(1);
    Node*e = new Node(9);
    Node* f = new Node(15);
    Node* g = new Node(18);
    Node* h = new Node(88);
    a->left =b;
    a->right =c;
    b->left = d;
    b->right= e;
    c->left = f;
    c->right = g;
    g->right = h;
    display(a);
    cout<<"\n sum of tree : "<<sum(a);
    cout<<"\n size of tree : "<<size(a);
    cout<<"\n max of the tree : "<<maxele(a);
    cout<<"\n level of the tree : "<<level(a);
}