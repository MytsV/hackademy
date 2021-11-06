#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
    void *data;
    struct node *next;
} node_t;

//the function creates a list
node_t *list_create(void *data)
{
    node_t *ptr = malloc(sizeof(node_t));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

//the function frees the memory from a linked list
void list_destroy(node_t **head, void (*fp)(void *data))
{
    if (*head == NULL)
    {
        return;
    }
    list_destroy(&(*head)->next, fp);
    (*fp)((*head)->data);
    free(*head);
    *head = NULL;
}

//the function adds an element to the end of a list
void list_push(node_t *head, void *data)
{
    if (head == NULL)
    {
        return;
    }

    while (head->next != NULL) 
    {
        head = head->next; 
    }
    head->next = list_create(data);
}

//the function adds an element to the start of a list
void list_unshift(node_t **head, void *data)
{
    if (*head == NULL) 
    {
        return;
    }    

    node_t *first = *head;
    *head = list_create(data);
    (*head)->next = first;     
}

//the function removes the last element of a list
void *list_pop(node_t **head)
{
    node_t *ptr = (*head);
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    node_t *del_node = ptr->next;
    ptr->next = NULL;
    return del_node; 
}

//the function removes the first element of a list
void *list_shift(node_t **head)
{
    node_t *del_node = *head;
    *head = (*head)->next;
    return del_node;
}

//in readme it says to remove by pointer, but in header file - by position. i implemented both variants
void *list_remove_ptr(node_t **head, node_t *ptr)
{
    node_t *ptr_search = *head;
    while (ptr_search->next != ptr && ptr_search->next != NULL)
    {
        ptr_search = ptr_search->next;
    }
    ptr_search->next = ptr->next;
    return ptr;
}

//the function removes list elements by position
void *list_remove(node_t **head, int pos)
{
    node_t *ptr = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        ptr = (*head)->next;
    }
    node_t *del_node = ptr->next;
    ptr->next = del_node->next;
    return del_node;
}

//the function visits a list
void list_visitor(node_t *head, void (*fp)(void *data))
{
    while (head != NULL)
    {
        (*fp)(head->data);
        head = head->next;
    }
}