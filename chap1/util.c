/*
 * util.c - commonly used utility functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void *checked_malloc(int len)
{
  void *p = malloc(len);
  if (!p)
  {
    fprintf(stderr, "\nRan out of memory!\n");
    exit(1);
  }
  return p;
}

string String(char *s)
{
  string p = checked_malloc(strlen(s) + 1);
  strcpy(p, s);
  return p;
}

U_boolList U_BoolList(bool head, U_boolList tail)
{
  U_boolList list = checked_malloc(sizeof(*list));
  list->head = head;
  list->tail = tail;
  return list;
}

T_tree Tree(T_tree l, string k, T_tree r)
{
  T_tree t = checked_malloc(sizeof(*t));
  t->left = l;
  t->key = k;
  t->right = r;
  return t;
}

T_tree insert(string key, T_tree t, void *bindings)
{
  if (t == NULL)
  {
    return Tree(NULL, key, NULL);
  }
  else if (strcmp(key, t->key) < 0)
  {
    return Tree(insert(key, t->left, bindings), t->key, t->right);
  }
  else if (strcmp(key, t->key) > 0)
  {
    return Tree(t->left, t->key, insert(key, t->right, bindings));
  }
  else
  {
    return Tree(t->left, key, t->right);
  }
}

bool isMember(T_tree tree, string key)
{
  while (tree != NULL)
  {
    int cmp = strcmp(key, tree->key);

    if (cmp == 0)
      return TRUE;
    else if (cmp < 0)
      tree = tree->left;
    else
      tree = tree->right;
  }

  return FALSE;
}

void *lookup(string key, T_tree t)
{
  while (t != NULL)
  {
    int cmp = strcmp(key, t->key);

    if (cmp == 0)
      return t->bindings;
    else if (cmp < 0)
      t = t->left;
    else
      t = t->right;
  }

  return NULL;
}