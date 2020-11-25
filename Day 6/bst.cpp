// Binary Tree Type

// Full Binary Tree
// Binary Tree that has either 0 / 2 children

// Complete Binary Tree = Balance
// Binary Tree where all tree levels are filled entirely with nodes, 
// Except the lowest level of the tree

// Perfect Binary
// Binary Tree that internal node have only 2 children
// 

// Balance Binary Tree != Complete
// Height = O(log N), n number of nodes
// To identify = Perbedaan sub-tree kiri dan sub-tree kanan <= 1

// Degenerate Binary Tree
// Binary Tree where every internal node only have one child
// Similar to LL (Linked List)


//Property of Binary Tree
// Maximum number of Nodes on level k is 2^k
// Maximum number of Nodes on a binary tree is 2^h+1 - 1
// Minimum height of a binary tree of node n is 2log(n0)
// Minimum height of a binary tree of node n is n-1


//Binary Tree using Array
// Root is Index 0
// Left Child is 2p + 1
// Right Child is 2p + 1
// Parent is (p-1)/2

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    Node *left, *right;
};

Node *createNode(int value)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Kita harus sambil initialize link (pasang" panah) ketika traverse
Node *insertNode(Node *root, int value)
{
    if(!root) // Jika tidak ada root
    {
        return createNode(value);
    }
    else if(value < root->value) // Masuk ke subree kiri
    {
        root->left = insertNode(root->left, value); //Traverse ke subtree ke kiri
    }
    else if(value > root->value) // Masuk ke subtree kanan
    {
        root->right = insertNode(root->right, value); //Traverse ke subtree kanan
    }

    return root;
}

// Untuk mencari value terkecil dalam sub-tree
Node *minValueNode(Node *root)
{
    Node *curr = root;

    // Traverse terus ke kiri sampe habis
    while(curr && curr->left)
    {
        curr = curr->left;
    }

    return curr;
}

Node *deleteNode(Node *root, int value)
{
    if(!root) // yg mau kita delete tidak ada
    {
        return root;
    }
    else if(value < root->value) // traverse ke kiri
    {
        //Sambil initialize link karena ada perubahan link
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->value) // traverse ke kanan
    {
        root->right = deleteNode(root->right, value);
    }
    else if(value == root->value) // ketemu apa yang mau kita delete
    {
        // kasus 0 anak (leaf)
        // kasus 1 anak
        // kasus 2 anak -> Larger node subtree kiri, smallest node subtree kanan -> pake func minValueNode

        //Untuk handle 0 dan 1 anak
        if(root->left == NULL)
        {
            // Jika kiri null, kandidat kanan
            Node *temp = root->right;
            free(root);

            return temp;
        }
        else if(root->right == NULL)
        {
            // Jika kanan null, kandidat kiri
            Node *temp = root->left;
            free(root);

            return temp;
        }

        //Jika kedua if di atas tidak dijalankan artinya
        //dia masuk ke kasus 2 anak

        // Cari nilai terkecil di subtree kanan
        Node *temp = minValueNode(root->right);
        root->value = temp->value; // Copy valuenya dulu sebelum dihapus
        root->right = deleteNode(root->right, temp->value);
        // Ketika kita ingin hapus sebuah node 2 anak, bukan node itu yang dihapus
        // tetapi penggantinnya
        // Bakal hapus nilai dari node terkecil di subtree kanan(hapus penggantinya)

    }
    
}

bool searchNode(Node *root, int key)
{
    if(root)
    {
        if(root->value == key) // Jika nilai root adalah yang dicari
        {
            return true; //level  // Masuk subtree kiri
        }
        else if(key < root->value)
        {
            return searchNode(root->left, key);
        }
        else if(key > root->value)
        {
            return searchNode(root->right, key);
        }
    }
}

void preOrder(Node *root)
{
    if(root)
    {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if(root)
    {
        preOrder(root->left);
        preOrder(root->right);
        printf("%d ", root->value);
    }
}

// InOrder = print sorted
void printAll(Node *root)
{
    if(root)
    {
        printAll(root->left);
        printf("%d ", root->value);
        printAll(root->right);
    }
}


int main()
{
    Node *baseRoot = NULL; // Initialize null
    baseRoot = insertNode(baseRoot, 15); // Initialize value
    insertNode(baseRoot, 20); // Add new item
    insertNode(baseRoot, 10); // Add new item
    insertNode(baseRoot, 7); // Add new item
    printAll(baseRoot);

    return 0;
}

