#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

/* Reads the employees from a tree and puts them in a Tree */
BSTree *readEmployees(){
  /* Open file to read */
  FILE *fileptr;
  fileptr = fopen("employees.txt", "r");

  /* Initialize a tree and variables to copy the line from the file */
  BSTree *tree = NULL;
  char line[100];
  int len;
  char *strcopy;

  /* Read the file and copy the line to a String */
  while(fscanf(fileptr,"%s",line) != EOF){
    for(len = 0; line[len]; len++)      /* Get length of String */
      ;
    strcopy = (char *)malloc(len+1);    /* Allocate memory for String */

    for(len = 0; line[len]; len++)      /* Copy the line to a String  */
      strcopy[len] = line[len];
    strcopy[len] = 0;
    tree = addEmployee(tree, strcopy);  /* Add the String to the Tree */
  }
  fclose(fileptr);   /* Close file */

  return tree;       /* Return tree with the elements read */
}

/* Save the elements in a Tree to a file */
void saveEmployees(BSTree *tree){
  /* Open file to write */
  FILE *fileptr;
  fileptr = fopen("employees.txt","w");
    
  if(tree == NULL){
    fclose(fileptr);
    return;
  }
  else{
    /* Save the elements in the tree to a file */
    printf("%s\n", *tree->employeeName);
    fprintf(fileptr, "%s\n", tree->employeeName);
    saveEmployees(tree->leftTree);
    saveEmployees(tree->rightTree);
  }
  fclose(fileptr);   /* Close the file */
}

int main(){
  printf("\nWELCOME TO ACME SYSTEM\n\n");

  /* Initialize tree and read the names from file */
  BSTree *root = readEmployees();
  printf("\n\n");

  /* Ask user for the task to be done */
  char task[100];
  printf("Please Enter Task: ADD, REMOVE, LIST, SAVE(EXIT)\n");
  scanf("%s", task);
  int cmpTask = strcmp(task, "SAVE");  // Compare for SAVE to exit
  int cmpAdd;
  int cmpRem;
  int cmpLst;
  
  while(cmpTask != 0){
    cmpAdd = strcmp(task,"ADD");       // Compare for ADD
    cmpRem = strcmp(task,"REMOVE");    // Compare for REMOVE
    cmpLst = strcmp(task,"LIST");      // Compare for LIST
    char employee[100];                 // Employee name given by user
    
    if(cmpAdd == 0){
      printf("\nEnter Employee to ADD\n");
      scanf("%s", employee);
      root = addEmployee(root, employee);
    }
    else if(cmpRem == 0){
      printf("\nEnter Employe to REMOVE");
      scanf("%s", employee);
    }
    else if(cmpLst == 0){
      printf("\nEMPLOYEES:\n\n");
      listEmployees(root);
    }
    else{
      /* Input wasnt a valid TASK */
      printf("\nTask is NOT VALID\n\n");
    }
    /* ASK for new task to be done  */
    printf("\nPlease Enter Task: ADD, REMOVE, LIST, SAVE(EXIT)\n");
    scanf("%s", task);
    cmpTask = strcmp(task, "SAVE");
  }

  /* Save the employees and EXIT */
  saveEmployees(root);
  printf("\n\nGOODBYE\n\n");

  return 0;
}
