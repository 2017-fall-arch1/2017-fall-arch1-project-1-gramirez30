#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

/*
 Reference for this file: Algorithms 4th Edition by R. Sedgewick and K. Wayne 

 Creates a Tree with the given Employee Name */
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


/* Returns the smallest value in a Treee */
BSTree *minValue(BSTree *tree){
  if(tree->leftTree == NULL) return tree;
  return minValue(tree->leftTree);
}

/* Deletes smallest value from a Tree  */
BSTree *deleteMin(BSTree *tree){
  if(tree->leftTree == NULL) return tree->rightTree;
  tree->leftTree = deleteMin(tree->leftTree);
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
    /* Case that Tree only has one leaf(SubTree) */
    if(tree->rightTree == NULL) return tree->leftTree;
    if(tree->leftTree == NULL) return tree->rightTree;
    
    /* Case that Tree has two leaves(SubTrees) */
    BSTree *tmp = (BSTree *)malloc(sizeof(BSTree));
    tmp = tree;
    tree = minValue(tree->rightTree);
    tree->rightTree = deleteMin(tree->rightTree);
    tree->leftTree = tmp;
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
