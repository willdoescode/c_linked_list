#ifndef SINGLY_H
#define SINGLY_H

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
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->value = value;
    n->next = NULL;

    head->next = n;
  }
}

struct Node *newList(int value)
{
  struct Node *ret = (struct Node *)malloc(sizeof(struct Node));
  ret->value = value;
  ret->next = NULL;
  return ret;
}

void appendSlice(struct Node *head, int arr[], int length)
{
  for (int i = 0; i < length; i++)
    append(head, arr[i]);
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

#endif // !SINGLY_H