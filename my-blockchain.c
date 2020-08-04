#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "blockchain.h"

int main(int argc, char **argv) {

    int numberOfNodes = 0;
    t_list *Blocks;
    t_node *Nodes;

    int sync = 0;

    Nodes = NULL;
    Blocks = NULL;

    /*readFromArchive(&sync, &numberOfNodes, &Nodes);*/

    showPrompt(&sync, &numberOfNodes, &Nodes);

}
