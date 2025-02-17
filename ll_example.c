// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

#include <stdio.h>
#include <stdlib.h>
int linkedList(int choice, int id, char *name);
LLPtr startPtr = NULL; // initially there are no nodes

void main(int argc, char *argv[])
{
   for (int i = 1; i + 2 < argc;)
   {
      int choice = atoi(argv[i]); // First argument (convert to integer)
      int id = atoi(argv[i + 1]); // Second argument (convert to integer)
      char *name = argv[i + 2];   // Third argument (string)
      // printf("Choice: %d, ID: %d, Name: %s\n", choice, id, name);
      linkedList(choice, id, name);
      if (choice == 1)
      {
         i += 3;
      }
      if (choice == 2)
      {
         i += 2;
      }
   }
   printList(startPtr);
   printListR(startPtr);
}

int linkedList(int choice, int id, char *name)
{
   int item = id; // char entered by user
   switch (choice)
   {
   case 1:
      insert(&startPtr, item, name); // insert item in list
      break;
   case 2: // delete an element
      // if list is not empty
      if (!isEmpty(startPtr))
      {
         // if character is found, remove it
         if (deletes(&startPtr, item))
         { // remove item
           // printf("%d deleted.\n", item);
           // printList(startPtr);
           // printListR(startPtr);
         } // end if
         else
         {
            // printf("%d not found.\n\n", item);
         } // end else
      } // end if
      else
      {
         puts("List is empty.\n");
      } // end else

      break;
   default:
      puts("Invalid choice.\n");
      break;
   } // end switch
} // end while
