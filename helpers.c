#include "blockchain.h"

char *my_strcpy(char *str1, char *str2) {
    if (str1 == NULL) {
        return NULL;
    }

    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0';

    return str1;
};

char *my_strncpy(char *str1, char *str2, int n) {

    if (str1 == NULL) {
        return NULL;
    }

    while (n >= 0) {
        if (*str2 == '\0') {
            break;
        }
        *str1 = *str2;
        str1++;
        str2++;
        n--;
    }

    *str1 = '\0';

    return str1;

};

char *my_strcat(char *str1, char *str2) {
  while(*str1 != '\0') {
    str1++;
  }

  while(*str2 != '\0') {
    *str1 = *str2;
    str1++;
    str2++;
  }

  *str1 = '\0';

  return str1;
}


char *my_strchr(char *str, int c) {

  while(*str) {

    if(*str == c) {
      return str;
    }

    str++;
  }

  return NULL;
}

int my_atoi(char *str) {
    int res = 0;
    int i = 0;
    int sign = 1;

    if (str[0] == '-') {
        i++;
        sign = -1;
    }

    for (; str[i] != '\0'; ++i) {
        res = res * 10 + (str[i] - '0');
    }

    return sign * res;
};

int my_strcmp( char *_str1_, char *_str2_) {

    while (*_str1_ == *_str2_) {
        if (*_str1_ == '\0' || *_str2_ == '\0') {
            break;
        }

        _str1_++;
        _str2_++;
    }

    if (*_str1_ > *_str2_) {
        return 1;
    } else if (*_str1_ < *_str2_) {
        return -1;
    }

    return 0;
};

char **stringToArray(char *str) {
    int strLen = strlen(str);
    int j = 0;
    int n = 0;

    if (!strLen) {
        return NULL;
    }

    int words = 1;

    for (int i = 0; i <= strLen; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            words++;
        }
    }

    char **output = (char**)malloc(words * sizeof(char*));

    for (int i = 0; i <= words + 1; i++) {
        output[i] = (char *)malloc(strLen * sizeof(char));
    }


    while (*str != '\0') {
        if (*str == ' ') {
            output[n][j] = '\0';
            j = 0;
            n++;
        } else {
            output[n][j] = *str;
            j++;
        }

       str++;

    }

    output[n+1][0] = 0;

    return output;
}

void my_memset(void *data, int c, size_t size)
{
    unsigned char *temp;
    temp = data;

    while (size > 0) {
        *temp++ = (unsigned char)c;
        size--;
    }
}

void *my_memalloc(size_t dataSize) {
    void *memalloc;

    if ((memalloc = (void *)malloc(dataSize))) {
        my_memset(memalloc, 0, dataSize);
        return (memalloc);
    }
    return (NULL);
}

void my_memcpy(void *dst, const void *src, size_t dataSize) {
    const unsigned char *tsrc = src;
    unsigned char *tdst = dst;

    size_t i = 0;
    while (i < dataSize) {
        tdst[i] = tsrc[i];
        i++;
    }
}

void my_memdel(void **data) {
    if (data != NULL && *data != NULL) {
        free(*data);
        *data = NULL;
    }
}

void my_del(void *data, size_t size) {
    my_memdel(&data);
    (void) size;
}

/*List functions for block*/

t_list *my_lstnew(void *data, size_t dataSize) {
    t_list *new;
    if (dataSize != 0 && (new = (t_list*)malloc(sizeof(t_list)))) {
        if ((new->data = my_memalloc(dataSize))) {
            if (data != NULL) {
                my_memcpy(new->data, data, dataSize);
                new->dataSize = dataSize;
            }
            else {
                new->data = NULL;
                new->dataSize = 0;
            }
        return (new);
        }
    }
    return (NULL);
}

void my_lstpush_back(t_list **lst, void *data, size_t dataSize) {
    t_list *new;
    t_list *current = *lst;

    if ((new = my_lstnew(data, dataSize))) {
        if (current == NULL)
            *lst = new;
        else {
            while (current->next)
                current = current->next;
            current->next = new;
        }
    }
}

void my_lstprint(t_list **head) {
    t_list *current = *head;
    while (current) {
        size_t i = 0;
        while (i < current->dataSize) {
            write(1, (char *)current->data + i, 1);
            i++; }

        current= current->next;
    }
}

void printNodesId(t_node *node)  {
    while (node != NULL)  {
      printf("%d\n", node->id);
      node = node->next;
    }
}

void printNodesInfo(t_node *node)  {
    while (node != NULL)  {
      t_list *blockInChain = node->blocks;
      printf("node %d ", node->id);

      while(blockInChain != NULL) {
          printf("blocks %s ", (char*)blockInChain->data);
          blockInChain = blockInChain->next;
      }
      printf("\n");
      node = node->next;
    }
}

void freeArray(char **array) {

  int rows = sizeof(array) / sizeof(array[0]);

  for(int i = 0; i < rows; i++) {
    free(array[i]);
  }

  free(array);
}

void	my_putchar_fd(int c, int fd)
{
	unsigned char ch;

	ch = (unsigned char)c;
	write(fd, &ch, sizeof(ch));
}

void    my_putchar(int c) {
    my_putchar_fd(c, 1);
}

void	my_putstr_fd(char const *s, int fd)
{
	char *temp;

	temp = (char *)s;
	if (s != NULL)
		while (*temp)
			write(fd, temp++, 1);
}

void my_putstr(char const *s) {
    my_putstr_fd(s, 1);
}

void	my_putnbr_fd(int n, int fd)
{
	long l;

	l = (long)n;
	if (n == -2147483648)
		my_putstr_fd("-2147483648", fd);
	else
	{
		if (l < 0)
		{
			my_putchar_fd('-', fd);
			l = -l;
		}
		if (l / 10)
			my_putnbr_fd(l / 10, fd);
		my_putchar_fd(l % 10 + '0', fd);
	}
}

void	my_putnbr(int n)
{
	my_putnbr_fd(n, 1);
}
