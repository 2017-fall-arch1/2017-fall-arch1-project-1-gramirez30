#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

/* Creates a Tree with the given Employee Name */
BSTree *createSubTree(char *name){
  /* Allocate memory for the new tree */
  BSTree *subTree = (BSTree *)malloc(sizeof(BSTree));
  int len;
  char *nameCopy;
  for(len = 0; name[len]; len++)
    ;
  nameCopy = (char *)malloc(len+1);   /* Allocate memory for Name copy */
  for(len = 0; name[len]; len++)
    nameCopy[len] = name[len];        /* Copy the name */
  nameCopy[len] = 0;
  
  subTree->employeeName = nameCopy;
  subTree->leftTree = NULL;
  subTree->rightTree = NULL;
  return subTree;
}

/* Adds an employee to the Tree */
BSTree *addEmployee(BSTree *tree, char *name){
  if(tree == NULL)
    return createSubTree(name);

  /* Compare for employee names in the tree */
  int cmp = strcmp(name, tree->employeeName);
  if(cmp < 0){
    tree->leftTree = addEmployee(tree->leftTree, name);
  }
  else if(cmp > 0){
    tree->rightTree = addEmployee(tree->rightTree, name);
  }
  else{
    tree->employeeName = name;
  }
  
  return tree;
}

/* Removes an employee from the Tree */
BSTree *removeEmployee(BSTree *tree, char *name){
  if(tree == NULL){
    return NULL;
  }

  int cmp = strcmp(name, tree->employeeName);
  if(cmp < 0){
    tree->leftTree = removeEmployee(tree->leftTree, name);
  }
  else if(cmp > 0){
    tree->rightTree = removeEmployee(tree->rightTree, name);
  }
  else{
    free(tree);
    tree == NULL;
  }

  return tree;
}

/* Lists all the employees in the Tree */
void listEmployees(BSTree *tree){
  if(tree == NULL){
    return;
  }
  else{
    /* List elements in the left Sub Tree */
    listEmployees(tree->leftTree);
    printf("%s\n", tree->employeeName);
    /* List the elements in the Right Sub Tree */
    listEmployees(tree->rightTree);
  }
}
