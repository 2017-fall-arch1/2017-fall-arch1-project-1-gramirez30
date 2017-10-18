#ifndef bstree_included
#define bstree_included

/* Binary Search Tree structure */
typedef struct BSTree{
  char *employeeName;
  struct BSTree *leftTree, *rightTree;
}BSTree;

/* Creates a Tree with the given name */
BSTree *createSubTree(char *name);

/* Adds an employee to the Tree */
BSTree *addEmployee(BSTree *tree, char *name);

/* Returns the smallest value in a Tree */
BSTree *minValue(BSTree *tree);

/* Deletes the smallest value in a Tree */
BSTree *deleteMin(BSTree *tree);

/* Removes an employee from the Tree */
BSTree *removeEmployee(BSTree *tree, char *name);

/* List all employee names in the Tree */
void listEmployees(BSTree *tree);

/* Reads the employess from the file and returns them in a Tree */
BSTree *readEmployees();

/* Saves the employees in a Tree to a file */
void saveEmployees();

#endif

