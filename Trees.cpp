#include <bits/stdc++.h>

using namespace std ;

class Node {
    public:
        int data ;
        Node* left ;
        Node* right ;
        Node ( int data ) {
            this->data = data ;
            left = NULL ;
            right = NULL ;
        }
};

/*
                  5            
                /   \           
               3     7          
              / \   / \  
             2   4 6   8
            / 
           1
*/  

// Function Declarations :
Node* newNode ( int ) ;

void preOrderTraversal ( Node* ) ;
void postOrderTraversal ( Node* ) ;
void inOrderTraversal ( Node* ) ;
void leverOrderTraversal ( Node* ) ;
void levelOrderTraversal ( Node* ) ;
int height ( Node* ) ;

// Binary Search Tree Functions :
Node* search ( Node* , int ) ;
Node* insert ( Node* , int ) ;
Node* inorderSuccessor ( Node* ) ;
Node* deleteNode ( Node* , int ) ;


int main(){

    Node* root = newNode ( 5 ) ;
    root = insert ( root , 3 ) ;            
    root = insert ( root , 7 ) ;
    root = insert ( root , 2 ) ;
    root = insert ( root , 4 ) ;
    root = insert ( root , 6 ) ;   
    root = insert ( root , 8 ) ;  
    root = insert ( root , 1 ) ;

    deleteNode ( root , 2 ) ;

    cout << "Preorder Traversal\n" ;
    preOrderTraversal ( root ) ;
    cout << endl ;
    cout << "Inorder Traversal\n" ;
    inOrderTraversal ( root ) ;
    cout << endl ;
    cout << "Postorder Traversal\n" ;
    postOrderTraversal ( root ) ;
    cout << endl ;
    cout << "Lever Order Traversal\n" ;
    levelOrderTraversal ( root ) ;
    cout << endl ;

    if ( search ( root , 8 ) == NULL ) cout << "NOT FOUND\n" ;
    else cout << "FOUND\n" ;
    cout << endl ;

    cout << "Height of the tree is " << height ( root ) << endl ; 
    
    return 0 ;
}

// Create a new node
Node* newNode ( int key ) {
    return new Node(key) ;
}

// preOrderTraversal 
void preOrderTraversal ( Node* root ) {
    if ( root == NULL ) return ;
    cout << root -> data << endl ;
    preOrderTraversal ( root -> left ) ;
    preOrderTraversal ( root -> right ) ;

}

// inOrderTraversal
void inOrderTraversal ( Node* root ) {
    if ( root == NULL ) return ;
    inOrderTraversal ( root -> left ) ;
    cout << root -> data << endl ;
    inOrderTraversal ( root -> right ) ;
}

// postOrderTraversal
void postOrderTraversal ( Node* root ) {
    if ( root == NULL ) return ;
    postOrderTraversal ( root -> left ) ;
    postOrderTraversal ( root -> right ) ;
    cout << root -> data << endl ;
}

// levelOrderTraversal
void levelOrderTraversal ( Node* root ) {
    if ( root == NULL ) return ;
    int level = 1 ;
    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;
    cout << "level - " << level << endl ;
    while ( !q.empty() ){
        Node* x = q.front() ;
        q.pop() ;
        if ( x != NULL ) {
            if ( x -> left != NULL ) q.push(x->left) ;
            if ( x -> right != NULL ) q.push(x->right) ;
            cout << x -> data << endl ;
        }
        else if ( !q.empty() ) {
            level ++ ;
            cout << "level - " << level << endl ;
            q.push(NULL) ;
        }
    }
}

// Find the height of a tree
int height ( Node* root ) {
    if ( root == NULL ) return 0 ;
    int lheight = height ( root -> left ) ;
    int rheight = height ( root -> right ) ;
    return max ( lheight , rheight ) + 1 ;
}

// Search if a value is present in a tree
Node* search ( Node* root , int key ) {
    if ( root == NULL || root -> data == key ) return root ;
    if ( key < root -> data ) search ( root -> left , key ) ;
    if ( key > root -> data ) search ( root -> right , key ) ;
}

// Rotating a AVL tree
Node* left ( Node* root ) {
    
}

Node* right ( Node* root ) {

}

// Insert a node in a binary search tree
Node* insert ( Node* root , int key ) {
    
    if ( root == NULL ) return newNode(key) ;
    if ( key < root -> data ) root -> left =  insert ( root -> left , key ) ;
    if ( key > root -> data ) root -> right = insert ( root -> right , key ) ;
    return root ;

    int balance = height ( root -> left ) - height ( root -> right ) ;

    if ( balance > 1 && key < root -> left -> data ) return right ( root ) ;
    if ( balance < -1 && key > root -> left -> data ) return left ( root ) ;

    if ( balance > 1 && key > root -> left -> data ) {
        root -> left = left ( root -> left ) ;
        return right ( root ) ;
    }

    if ( balance < -1 && key < root -> right -> data ) {
        root -> right = right ( root -> right ) ;
        return left ( root ) ;
    }

}

// To find Inorder Successor
Node* inorderSuccessor ( Node* root ) {
    while ( root -> left != NULL ) {
        root = root -> left ;
    }
    return root ;
}

// Delete a node in a binary search tree
Node* deleteNode ( Node* root , int key ) {
    if ( root == NULL ) return root ;
    if ( key < root -> data ) root -> left = deleteNode ( root -> left , key ) ;
    if ( key > root -> data ) root -> right = deleteNode ( root -> right , key ) ;
    if ( key == root -> data ) {
        if ( root -> left == NULL ) {
            Node* temp = root -> right ;
            free ( root ) ;
            return temp ;
        }
        else if ( root -> right == NULL ) {
            Node* temp = root -> left ;
            free ( root ) ;
            return temp ;
        }
        else {
            Node* temp = inorderSuccessor ( root -> right ) ;
            root -> data = temp -> data ;
            root -> right = deleteNode ( root -> right , temp -> data ) ;
        }
        return root ;
    }

    return root ;
}