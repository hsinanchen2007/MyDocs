/*
Copyright (C) 2017 Interview Druid, Parineeth M. R.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include <stdio.h>
#include <stdlib.h>


#define MAX_NUM_NODES_IN_TREE (10)

void handle_error(void)
{
    printf("Test failed\n");
    exit(1);
}


struct node
{
    int data;

    int depth;

    struct node *left;
    struct node *right;

    struct node *parent;

};

/*
Include the header file for printing the tree. The header file should be included
only after defining struct node
*/
#include "print_tree.h"

struct node * construct_bst(struct node *parent, int values[], int low, int high, struct node *node_array[])
{
    int middle;

    struct node *new_node;

    if (low > high) {

        return NULL;
    }

    middle = (low + high) / 2;

    new_node = (struct node*) calloc(1, sizeof(struct node));

    new_node->data = values[middle];

    new_node->parent = parent;

    if (!parent)
        new_node->depth = 0;
    else
        new_node->depth = parent->depth + 1;

    new_node->left = construct_bst(new_node, values, low, middle - 1, node_array);

    new_node->right = construct_bst(new_node, values, middle + 1, high, node_array);

    node_array[middle] = new_node;

    return new_node;

}

void destroy_tree(struct node *cur_node) 
{
    if (!cur_node)
        return;

    destroy_tree(cur_node->left);
    destroy_tree(cur_node->right);

    free(cur_node);
}


/*Find the Least Common Ancestor of a BINARY SEARCH TREE
ancestor: the current ancestor node (root node is passed by the caller for first time)
n1 and n2 are two nodes in the tree whose least common ancestor should be found
Return value - pointer to least common ancestor node of n1 and n2
*/

struct node * bst_lca(struct node *ancestor, struct node *n1, struct node *n2)
{
    if (!ancestor || !n1 || !n2)
        return NULL;

    /*If the ancestor data is between n1 data and n2 data, then the
    ancestor is the least common ancestor*/
    if (n1->data <= ancestor->data && ancestor->data <= n2->data)
        return ancestor;

    if (n2->data <= ancestor->data && ancestor->data <= n1->data)
        return ancestor;

    /*If the ancestor data is greater than n1 data and n2 data, then
    the LCA will be in the left subtrie of the ancestor*/
    if (ancestor->data > n1->data && ancestor->data > n2->data)
        return bst_lca(ancestor->left, n1, n2);

    /*The ancestor data is less than n1 data and n2 data. So
    the LCA will be in the right subtrie of the ancestor*/
    return bst_lca(ancestor->right, n1, n2);
}


/*n: node in the binary tree
Return value: depth of the node
*/
int find_depth(struct node *n)
{
    int depth = 0;

    while (n->parent) {
        n = n->parent;
        ++depth;
    }
    return depth;
}

/*Find the Least Common Ancestor of a BINARY TREE
n1 and n2 are two nodes in the tree
Return value: least common ancestor node of n1 and n2
*/
struct node *lca(struct node *n1, struct node *n2)
{
    int depth1, depth2;
    
    depth1 = find_depth(n1);
    depth2 = find_depth(n2);

    /* If n1 is deeper than n2, then move n1 up the tree
    till the depth of n1 and n2 match
    */
    while (depth1 > depth2) {
        n1 = n1->parent;
        depth1--;
    }

    /* If n2 is deeper than n1, then move n2 up the tree
    till the depth of n1 and n2 match
    */
    while (depth2 > depth1) {
        n2 = n2->parent;
        depth2--;
    }

    /*Move n1 and n2 up the tree until a common node is found*/
    while (n1 != n2 ) {
        n1 = n1->parent;
        n2 = n2->parent;
    }

    return n1;
}


int main()
{
    struct node *root, *lca1, *lca2;
    int i, j, num_elems, number_array[MAX_NUM_NODES_IN_TREE];
    struct node *node_array[MAX_NUM_NODES_IN_TREE];

    /*number_array contains data in ascending order from 0*/
    for (i = 0; i < MAX_NUM_NODES_IN_TREE; ++i) {
        number_array[i] = i;
    }

    /*Test for different number of nodes in the tree*/
    for (num_elems = 1; num_elems <= MAX_NUM_NODES_IN_TREE; ++num_elems) {
        /*Construct the tree based on the data stored in the number array
        the nodes will also be stored in the node_array*/
        root = construct_bst(NULL, number_array, 0, num_elems - 1, node_array);

        printf("Printing the tree:\n");
        print_tree(root, num_elems);

        /*Generate all pairs of nodes in the tree using the node_array*/
        for (i = 0; i < num_elems; ++i) {
            for (j = i+1; j < num_elems; ++j) {
                /*Find the Least Common Ancestor for the two nodes
                using the algorithm for the BINARY TREE.
                We have created a Binary Search Tree which is also a Binary Tree
                So we can apply the BINARY TREE algo for a BST*/
                lca1 = lca(node_array[i], node_array[j]);

                /*There is a different algo to find the LCA that is 
                applicable only for BINARY SEARCH TREE. 
                Since we have created a Binary Search Tree, use the algo for BST */
                lca2 = bst_lca(root, node_array[i], node_array[j]);

                /*The two results should match*/
                if (lca1 != lca2)
                    handle_error();

                printf("Least Common Ancestor of %d and %d = %d\n", 
                    node_array[i]->data, node_array[j]->data, lca1->data);
            }
        }

        destroy_tree(root);

        printf("____________________________________________________\n");

    }

    printf("Test passed \n");

    return 0;
}
