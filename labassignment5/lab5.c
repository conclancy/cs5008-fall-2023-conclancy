// name: Connor Clancy
// email: clancy.co@neu.edu

#include<stdio.h>
#include<stdlib.h>

/*----defining the structure for Avl tree node----*/
typedef struct avlnode {
    int data;
    struct avlnode *left;
    struct avlnode *right;
    int height;
} node_t;

/*---defining structure for AVL tree--*/
typedef struct AVL {
    struct avlnode* root;
} Tree;

/* creating a new Avl node */
node_t* newNode(int data) {

    node_t* temp = (node_t*)malloc(sizeof(node_t));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 0;

    return temp;
}

/*------------Creating a Tree------------------*/
Tree* initTree() {
    Tree* t;
    t=(Tree*)malloc(sizeof(Tree));

    if(t==NULL) {
        printf("Memory is not allocated\n");
        exit(1);
    }

    t->root=NULL;
    
    return t;
}


/* calculating maximum of 2 numbers*/
int max(int a, int b) {

    if(a>b) {
        return a;
    } else {
        return b;
    }
}

/* finding the height of the tree*/
int height(node_t* node) {

    if(node==NULL) {
        return -1;
    }

    return node->height;
}

/* finding the balance factor of the node*/
int balance(node_t* node){

    if(node==NULL) {
        return 0;
    }

    return height(node->left) - height(node->right);//height of Left subtree-height of right subtree.
}

/* left rotation of the node and updating the height of left and right subtree*/
node_t* leftRotate(node_t* z) {

    node_t* y = z->right;
    node_t* temp = y->left;

    y->left = z;
    z->right = temp;

    z->height = max(height(z->left), height(z->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

/*--- function to perform the Right rotation and updating the height of left and right subtree--*/
node_t* rightRotate(node_t *z) {

    node_t* y = z->left;
    node_t* temp = y->right;

    y->right = z;
    z->left = temp;
    
    /*update the height after right rotation*/
    z->height = max(height(z->left), height(z->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

/*---------------- function to display the preorder traversal of AVL tree------------*/
void preOrder(node_t *temp) {
    
    
    if(temp != NULL) {
        printf("%d\n",temp->data);
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

/*---free the AVL nodes----*/
void freeNode(node_t *p) {

    if(p != NULL) {
        freeNode(p->left);
        freeNode(p->right);
        free(p);
    }
}

/* ----------------function to insert a node*---------------------------*/
/* Insert a node like a Binary search tree, then convert it into a AVL tree using four cases*/
node_t* insert(node_t* root, int data) {
    
    // base case for empty tree
    if (root == NULL) {
        return newNode(data);
    }
    
    // add data to the tree
    if (data < root->data) {
        // if the data is smaller than the root, add left 
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        // if the data is larger than the root, add right 
        root->right = insert(root->right, data);
    } else if (data == root->data) {
        // if the data is a duplicate
        return root; 
    }
        
    /*updating the height after insertion of the node*/
    root->height = max(height(root->left),height(root->right))+1;
        
    /*checking the balance factor to check the tree is balanced*/
    int balancefactor = balance(root);

    /*Left Left case*/
    if(balancefactor > 1 && data < root->left->data) {
        return rightRotate(root);
    }

    /*Right Right Case*/
    if(balancefactor < -1 && data > root->right->data) {
        return leftRotate(root);
    }

    /*Left Right Case*/
    if(balancefactor > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    /*Right Left Case*/
    if(balancefactor < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}



/*------------------main program-------------------------------*/
int main() {

    Tree* T=initTree();
    int n,x,i;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the tree data\n");

    for(i=0;i<n;i++) {
        scanf("%d", &x);
        T->root=  insert(T->root,x);
    }

    printf("The output is:\n");
    preOrder(T->root);
    freeNode(T->root);

    free(T);
}
