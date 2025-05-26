#ifndef LISTAWP_LIST_H
#define LISTAWP_LIST_H

/* --------- ERROR CODES ---------- */
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/* ---------- INSERTING ---------- */

int insertFront(int element);
// Inserts passed argument at the front of the list
// Returns:
// EXIT_SUCCESS (0), if added successfully
// EXIT_FAILURE (1), if couldn't add (memory allocation fail)

int insertBack(int element);
// Inserts passed argument at the back of the list
// Returns:
// EXIT_SUCCESS (0), if added successfully
// EXIT_FAILURE (1), if couldn't add (memory allocation fail)

int insertAfterNode(int index, int element);
// Inserts passed argument (element) after given element (position: index - counting from 1, not 0)
// Returns:
// EXIT_SUCCESS (0), if added successfully
// EXIT_FAILURE (1), if couldn't add (memory allocation fail)

/* ---------- DELETING ---------- */

int deleteFront();
// Deletes the first element from the list
// Returns:
// EXIT_SUCCESS (0), if deleted successfully
// EXIT_FAILURE (1), if couldn't delete (no nodes)

int deleteBack();
// Deletes the last element from the list
// Returns:
// EXIT_SUCCESS (0), if deleted successfully
// EXIT_FAILURE (1), if couldn't delete (no nodes)

int deleteNode(int index);
// Deletes given element (position: index, counting from 1, not 0) from the list
// Returns:
// EXIT_SUCCESS (0), if deleted successfully
// EXIT_FAILURE (1), if couldn't delete (no nodes or such index doesn't exist)

/* ---------- READING ---------- */

int readFromTop();
int readFromBeginning();

/* ---------- OTHER ---------- */

int searchList(int key);
// Checks whether given element is present in the list
// Returns:
// EXIT_SUCCESS (0), if the element is present
// EXIT_FAILURE (1), if the element is not present

void printList(void);
// Prints the list

int getNodesCount();
// Returns the current amount of elements (nodes)

void freeList(void);
// Frees memory allocated by the list

#endif //LISTAWP_LIST_H
