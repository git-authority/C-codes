#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *left;
struct node *right;
};

struct node *root = NULL;
void insert(int data){
struct node *tempNode = (struct node*) malloc(sizeof(struct node));
struct node *current;
struct node *parent;
tempNode->data = data;
tempNode->left = NULL;
tempNode->right = NULL;
if(root == NULL) {
root = tempNode;
}
else {
current = root;
parent = NULL;
while(1)
{
parent = current;
if(data < parent->data) {
current = current->left;

if(current == NULL) {
parent->left = tempNode;
return;
    }
}
else { 
current = current->right;
if(current == NULL) {
parent->right = tempNode;
return;
            }
        }
    }
}

}

void inorder(struct node* root){
if(root != NULL) {
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    }
}
int main(){
int i;
printf("Enter Elements \n");
int n;
scanf("%d",&n);
int arr[n];
for(int i=0; i<n; i++){
    scanf("%d",&arr[i]);
}
    for(i = 0; i < n; i++)
    {
    insert(arr[i]);
    }
printf("\nInorder traversal: ");
inorder(root);
return 0;

}