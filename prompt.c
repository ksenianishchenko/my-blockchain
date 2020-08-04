#include "blockchain.h"

void updateNodeList(char **array, t_node **Nodes) {

  int id = my_atoi(array[2]);

  if(!id) {
    puts("Id should be a number");
    return;
  }

  if ((my_strcmp(array[1], "add") == 0)) {

    addToNodes(Nodes, id);

  } else if (my_strcmp(array[1], "rm") == 0) {

    removeFromNodes(Nodes, id);

  } else {

    puts("Wrong command");

  }

}

void updateBlocksList(char **array, t_node **Nodes) {

  int id = my_atoi(array[3]);

  if(!id) {
    puts("Id should be a number");
    return;
  }

  if ((my_strcmp(array[1], "add") == 0)) {

    addBlockToNode(Nodes, id, array[2], sizeof(char*));
    printNodesInfo(*Nodes);

  } else if (my_strcmp(array[1], "rm") == 0) {

  } else {

    puts("Wrong command");

  }

}

void readPrompt(char **array, t_node **Nodes) {

  if(my_strcmp(array[0], "node") == 0) {

    updateNodeList(array, Nodes);

  } else if (my_strcmp(array[0], "block") == 0) {

    updateBlocksList(array, Nodes);

  } else if (my_strcmp(array[0], "sync") == 0) {

    printf("%s\n", "sync");

  } else if (my_strcmp(array[0], "ls") == 0) {

      if(my_strcmp(array[1], "-l") == 0) {
          printNodesInfo(*Nodes);
      } else {
          printNodesId(*Nodes);
      }

  } else {

    printf("%s\n", "Quit");

  }

}

void showPrompt(int *sync, int *numberOfNodes, t_node **Nodes) {

  char buff[100];

  while( 1 ) {
      /*printf("[%s%d]> ", ((*sync) ? "-" : "s"), *numberOfNodes);*/

      size_t bytesRead = read( STDIN_FILENO, buff, 100);

      buff[bytesRead - 1] = '\0';

      char **array = stringToArray(buff);

      readPrompt(array, Nodes);
      *numberOfNodes = countNodes(*Nodes);

      free(array);

  }
}
