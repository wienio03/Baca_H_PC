#include <iostream>
struct OBJECT_TYPE
{
    int data_object;
};
struct NODE_STRUCT
{
    OBJECT_TYPE *object;
    unsigned char use;
    NODE_STRUCT *next;
};
unsigned char SIZE;
//-------------------------------------------------------//
//obsługa pamięci
NODE_STRUCT *NewNode(void)
{
    NODE_STRUCT *new_node = new NODE_STRUCT;
    new_node->object = new OBJECT_TYPE[SIZE];
    new_node->next = NULL;
    return new_node;
}

void DeleteNode(NODE_STRUCT *node)
{
    if (node->object != NULL) delete[] node->object;
    if (node->next != NULL) node->next = NULL;
    if (node != NULL) delete node;
}
void Clear(NODE_STRUCT **list_node )
{
    NODE_STRUCT *tmp;
    tmp=*list_node;
    while (tmp->next != NULL) {
        DeleteNode(tmp);
        tmp=tmp->next;
    }
}
//dodawanie obiektów
void AddFirst (NODE_STRUCT **list_node, OBJECT_TYPE *added_object){
    if((*list_node)->use=SIZE)
    {
        NODE_STRUCT* prev_first_node = *list_node;
        NODE_STRUCT* first_node = NewNode();
        first_node->next=prev_first_node;
        first_node->object=added_object;
        first_node->use++;
    }
    else{
    }
}
void AddLast (NODE_STRUCT **list_node, OBJECT_TYPE *added_object){
    NODE_STRUCT *tmp = *list_node;
    while(tmp!=NULL){
        tmp=tmp->next;
        if(tmp->next==NULL){
            if(tmp->use<SIZE) {
                tmp->use++;
                *(tmp->object + tmp->use) = *added_object;
                break;
            }
            else {
                NODE_STRUCT *added_node = NewNode();
                *(added_node->object)=*added_object;
                (added_node->use)++;
                while((*list_node)!=NULL){
                    *list_node=(*list_node)->next;
                    if((*list_node)==NULL){
                        (*list_node)->next=added_node;
                        break;
                    }
                }
            }
        }
    }
}
void RemoveFirst(NODE_STRUCT** list_node)
{
    if(*list_node!=NULL)
    {
        while((*list_node)->use!=0) (*list_node)->use--;
        DeleteNode(*list_node);
    }
}
void RemoveLast(NODE_STRUCT** list_node)
{
    if(*list_node!=NULL)
    {
        NODE_STRUCT* second_to_last=NULL;
        while((*list_node)->next!=NULL)
        {
            second_to_last=*list_node;
            (*list_node)=(*list_node)->next;
        }
        DeleteNode(*list_node);
        second_to_last->next=NULL;
    }
}
