#include "blockchain.h"

void readFromArchive(int *sync, int *numberOfNodes, t_node **Nodes) {
  char *str = NULL;
  int fd = open("archive.txt", O_RDONLY);
  int count = 0;


  while((str = my_readline(fd))) {

    if (count == 0) {

      *sync = my_atoi(str);
      count++;

    } else if (count == 1) {

      *numberOfNodes = my_atoi(str);
      count++;

    } else {

      char **array = stringToArray(str);

      int id = my_atoi(array[0]);

      int i = 1;

      while (array[i][0] != 0) {
        /*printf("%s\n", array[i]);*/
        i++;
      }

      addToNodes(Nodes, id);
      count++;

    }

    free(str);
  }

}

void writeInArchive(int sync, int numberOfNodes, t_node *Nodes) {
  int filedesc = open("archive.txt", O_RDONLY | O_WRONLY | O_TRUNC);

  if (filedesc < 0) {
      printf("Can't open the file");
      return;
  }

  my_putnbr_fd(sync, filedesc);
  write(filedesc, "\n", 1);
  my_putnbr_fd(numberOfNodes, filedesc);
  write(filedesc, "\n", 1);

  while (Nodes != NULL)  {

    my_putnbr_fd(Nodes->id, filedesc);
    write(filedesc, " ", 1);

    t_list *blocks = Nodes->blocks;

    while (blocks) {
        write(filedesc, blocks->data, strlen(blocks->data));
        write(filedesc, " ", 1);
        blocks = blocks->next;
    }

    write(filedesc, "\n", 1);
    Nodes = Nodes->next;
  }

}
