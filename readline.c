#include "blockchain.h"

char *createLine(char *strFromBuf) {
  int lineLength = 0;
  char *temp;
  int tempInx = 0;
  char *newLine;

  while(strFromBuf[lineLength] != '\n' && strFromBuf[lineLength] != '\0') {
    lineLength++;
  }

  newLine = (char *)malloc(lineLength * sizeof(char) + 1);

  if(strFromBuf[lineLength] == '\n') {
    my_strncpy(newLine, strFromBuf, lineLength);
  } else {
    my_strcpy(newLine, strFromBuf);
  }

  newLine[lineLength] = '\0';

  temp = (char *)malloc(strlen(strFromBuf) * sizeof(char) + 1);

  for(int j = lineLength + 1; strFromBuf[j] != '\0'; j++) {
    temp[tempInx] = strFromBuf[j];
    tempInx++;
  }

  temp[tempInx] = '\0';

  my_strcpy(strFromBuf, temp);

  free(temp);

  return newLine;
}

char *my_readline(int fd) {
  char buffer[BUFF_SIZE + 1];
  char *line;

  static char strFromBuf[4095];

  int size_read = 0;

  while((size_read = read(fd, buffer, BUFF_SIZE)) > 0) {
    buffer[size_read] = '\0';
    my_strcat(strFromBuf, buffer);
    if(my_strchr(strFromBuf, '\n')) {
      break;
    };
  }

  line = createLine(strFromBuf);

  int len = strlen(line);

  if(size_read == 0 && len == 0) {
    return NULL;
  }

  return line;
};
