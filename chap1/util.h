#include <assert.h>

typedef char *string;
typedef char bool;

#define TRUE 1
#define FALSE 0

#define NULL ((void *)0)
#define TRUE 1
#define FALSE 0

#define TREE_EQUAL(tree, treetf)         \
    ((tree)->left == (treetf)->left &&   \
     (tree)->right == (treetf)->right && \
     strcmp((tree)->key, (treetf)->key) == 0)

void *checked_malloc(int);
string String(char *);

typedef struct tree *T_tree;

struct tree
{
    T_tree left;
    string key;
    T_tree right;
    void* bindings;
};

typedef struct U_boolList_ *U_boolList;
struct U_boolList_
{
    bool head;
    U_boolList tail;
};
U_boolList U_BoolList(bool head, U_boolList tail);

T_tree Tree(T_tree l, string k, T_tree r);
T_tree insert(string key, T_tree t,void* bindings);
bool isMember(T_tree tree, string key);