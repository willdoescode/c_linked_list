#include "singly.h"

int main()
{
  struct Node *head = newList(4);

  append(head, 5);
  append(head, 6);
  append(head, 7);
  append(head, 8);

  int x[] = {9, 10, 11, 12};
  appendSlice(head, x, 4);

  printf("Pre reverse:  ");
  print(head);

  reverse(&head);

  printf("Post reverse: ");
  print(head);

  dealloc(head);

  return 0;
}
