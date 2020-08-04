#include "blockchain.h"


t_node *searchNodes(t_node *head, int id) {

  t_node *temp = head;

  if(temp == NULL) {
    return NULL;
  }

  while(temp != NULL) {

    if (temp->id == id) {
      return temp;
    }
    temp = temp->next;
  }

  return NULL;
}


void addToNodes(t_node **head, int id) {

  t_node *currentNode = searchNodes(*head, id);

  if (currentNode) {
    printf("%s\n", "Node exists");
    return;
  }

  t_node *newNode = (t_node *)malloc(sizeof(t_node));
  newNode->id = id;
  newNode->blocks = NULL;
  newNode->next = NULL;

  if(*head == NULL) {
    *head = newNode;
    return;
  }

  t_node *temp = *head;

  while(temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;

  return;
};

void removeFromNodes(t_node **head, int id) {

  t_node *currentNode = searchNodes(*head, id);

  if (!currentNode) {
    printf("%s\n", "Error: No such node id");
    return;
  }

  t_node *temp = *head;
  t_node *prev;

  if (temp != NULL && temp->id == id) {
    *head = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp->id != id) {
    prev = temp;
    temp = temp->next;
  }

  if(temp == NULL) {
    return;
  }

  prev->next = temp->next;
  free(temp);
};

void addBlockToNode(t_node **head, int id, void *data, size_t dataSize) {
  t_node *currentNode = searchNodes(*head, id);
  t_list *blocksLst = currentNode->blocks;

  my_lstpush_back(&blocksLst, data, dataSize);


  currentNode->blocks = blocksLst;

}

int countNodes(t_node *node) {
  int count = 0;

  while (node != NULL)  {
    count++;
    node = node->next;
  }

  return count;
};
