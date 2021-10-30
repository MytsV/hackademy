#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
    char *key;
    void *data;
    struct node *left;
    struct node *right;
} node_t;

//allocates memory to a node
node_t *allocnode()
{
    node_t *ptr = malloc(sizeof(node_t));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->key = NULL;
    ptr->data = NULL;
    return ptr;    
}

//the function compares two strings
int my_strcmp(char *str1, char *str2)
{
    for (; *str1 != '\0' && *str2 != '\0'; str1++, str2++) 
    {
        if (*str1 < *str2)
        {
            return -1;
        }
        else if (*str1 != *str2)
        {
            return 1;
        }
    }
    return 0;
}

//inserts a new node into a binary tree
node_t *insert(node_t *root, char *key, void *data)
{
    if (root == NULL)
    {
        root = allocnode();
    }

    if (root->key == NULL)
    {
        root->key = key;
        root->data = data;
        return root;
    }
    
    if (my_strcmp(root->key, key) < 0)
    {
        if (root->right == NULL)
        {
            root->right = allocnode();
        }
        insert(root->right, key, data);
        return root;
    }
    else if (my_strcmp(root->key, key) > 0)
    {
        if (root->left == NULL)
        {
            root->left = allocnode();
        }
        insert(root->left, key, data);
        return root;
    }
    else
    {
        root->data = data;
        return root;
    }  
}

//the function determines the length of a string
unsigned int get_str_len(const char *s)
{   
    int len = 0; 
    for (; *s != '\0'; s++)
    {   
        len++;
    }
    return len;
}

void my_puts_new_line()
{   
    char str[] = "\n";
    write(STDOUT_FILENO, str, sizeof(str) - 1);
}

//writes a string to standard output
void my_puts(void *s)
{
    write(STDOUT_FILENO, s, get_str_len((char *)s));
    my_puts_new_line();
}

//prints a node of a binary tree
void print_node(node_t *node)
{
    if (node == NULL)
    {
        my_puts("None");
        return;
    }

    my_puts(node->key);
    my_puts(node->data);
}

//visits a binary tree
void visit_tree(node_t *node, void (*fp)(node_t *root))
{
    if (node == NULL)
    {    
        return;
    }
    (*fp)(node);
    visit_tree(node->left, fp);
    visit_tree(node->right, fp);
}

//frees memory of a binary tree
void destroy_tree(node_t *node, void (*fdestroy)(node_t *root))
{
    visit_tree(node, fdestroy);
}
