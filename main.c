#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    int key;
    struct node *right;
    struct node *left;
}node_t;
node_t *newNode(int ,node_t* ,node_t*);
void longestPath(node_t *);
int main()
{
    node_t *node8 = newNode(6,NULL,NULL);
    node_t *node9 = newNode(9,NULL,NULL);
    node_t *node10 = newNode(10,NULL,NULL);
    node_t *node11 = newNode(17,NULL,NULL);
    node_t *node12 = newNode(12,NULL,NULL);
    node_t *node13 = newNode(7,NULL,NULL);
    node_t *node14 = newNode(19,NULL,NULL);
    node_t *node15 = newNode(8,NULL,NULL);
    node_t *node4 = newNode(1,node8,node9);
    node_t *node5 = newNode(5,node10,node11);
    node_t *node6 = newNode(4,node12,node13);
    node_t *node7 = newNode(15,node14,node15);
    node_t *node2 = newNode(3,node4,node5);
    node_t *node3 = newNode(11,node6,node7);
    node_t *node1 = newNode(2,node2,node3);
    longestPath(node1);
    return 0;
}
node_t *newNode(int x,node_t* Left,node_t* Right){
    node_t *tmp=(node_t*)malloc(sizeof(node_t));
    tmp->key=x;
    tmp->left=Left;
    tmp->right=Right;
    return tmp;
}
void longestPath(node_t *root){
    static int cnt =0;
    static int res[100];
    int i;
    res[cnt]=root->key;
    ///termination condition
    ///if(root==NULL){  I needed to check the children of the node
    if((root->left==NULL)||(root->right==NULL)){
        printf("RESULT :{");
        for(i=1;i<=cnt;i++){
            printf("%d ",res[i]);
        }
        printf("}");
        exit(1);
    }
    ///if the next key value is greater than current key
    if(root->left->key > root->key){
        cnt++;
        longestPath(root->left);
        if(root->right->key> root->key){
            longestPath(root->right);
        }
    }else if(root->right->key> root->key){
        cnt++;
        longestPath(root->right);
    }else{///in the case both nodes key are smaller than current Key
        cnt--;
        return;
    }
}

