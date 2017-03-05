#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BinaryTreeNode
{
        char *data; 
       struct  BinaryTreeNode* left; 
       struct  BinaryTreeNode* right;   
} BinaryTreeNode;

BinaryTreeNode* addNode(BinaryTreeNode* root, char *value);
void printSortAscending(BinaryTreeNode* root);
void printSortDescending(BinaryTreeNode* root);
void destroyTree(BinaryTreeNode* root);


int main(int argc, char *argv[])
{
BinaryTreeNode* root= NULL;
char* str2;
str2=malloc(sizeof(char)*1024);
FILE* doc = fopen(argv[2],"r");
        if((!str2)||(!doc)||(argc>3)||((strcmp(argv[1],"ascending"))&&(strcmp(argv[1],"descending"))))
 {
 printf ("Error\n");
 return 1;
 }
while(!feof(doc))
{
fgets(str2,1024,doc);
root = addNode(root,str2);
}
free(str2);
if(!strcmp(argv[1],"ascending"))
printSortAscending(root);
else printSortDescending(root);
destroyTree(root);
fclose(doc);
return 0;
}

BinaryTreeNode* addNode(BinaryTreeNode* root, char *value)
{
if (!root)
 {
 root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
 root->data=(char*)malloc(sizeof(char)*(strlen(value)+1));
 if((!root)||(!(root->data)))
 {
 printf("Error in malloc(addNode)");
 return 0;
 }       
 strcpy(root->data,value);
 root->left = NULL;
 root->right = NULL;
 return root;
 }
if (strcmp(value,root->data)>0)
 root->right = addNode(root->right, value);
if (strcmp(value,root->data)<0)
 root->left  = addNode(root->left, value);
return root;
}

void printSortAscending(BinaryTreeNode* root)
{
if (!root)
 return;
printSortAscending(root->left);
printf("%s\n", root->data);
printSortAscending(root->right);
}

void printSortDescending(BinaryTreeNode* root)
{
  if (!root)
    return;
printSortDescending(root->right);
printf("%s\n", root->data);
printSortDescending(root->left);
}

void destroyTree(BinaryTreeNode* root)
{
  if (root)
    {
      destroyTree(root->left);
      destroyTree(root->right);
      free(root);
    }
}
     
