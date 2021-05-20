#include "singly.h"

int main()
{
  struct Node *head = newList(4);

  append(head, 5);
  append(head, 6);
  append(head, 7);
  append(head, 8);
  reverse(&head);

  print(head);

  dealloc(head);

  return 0;
}
