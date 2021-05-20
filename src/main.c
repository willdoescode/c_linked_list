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

static void reverse(struct Node **head)
{
  struct Node *prev = NULL;
  struct Node *current = *head;
  struct Node *next;
  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
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
  append(head, 7);
  append(head, 8);
  reverse(&head);

  print(head);

  dealloc(head);

  return 0;
}
