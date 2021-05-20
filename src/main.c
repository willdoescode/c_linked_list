#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int value;
  struct Node *next;
};

void append(struct Node *head, int value)
{
  if (head->next)
  {
    append(head->next, value);
  }
  else
  {
    struct Node *n = malloc(sizeof(struct Node));
    n->value = value;
    n->next = NULL;

    head->next = n;
  }
}

void dealloc(struct Node *head)
{
  struct Node *current = head;
  while (head)
  {
    current = head;
    head = head->next;
    free(current);
  }
}

struct Node *newList(int value)
{
  struct Node *ret = malloc(sizeof(struct Node));
  ret->value = value;
  ret->next = NULL;
  return ret;
}

void print(struct Node *head)
{
  struct Node *current = head;
  printf("%d", current->value);
  if (!current->next)
  {
    return;
  }
  current = current->next;

  while (current)
  {
    printf(" -> %d", current->value);
    current = current->next;
  }
  printf("\n");
}

int main()
{

  struct Node *head = newList(4);

  append(head, 5);
  append(head, 6);

  print(head);

  dealloc(head);

  return 0;
}
