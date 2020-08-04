#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 8

#define false 0

typedef struct s_list {
    void *data;
    size_t dataSize;
    struct s_list *next;
} t_list;

typedef struct Node {
    int id;
    struct Node *next;
    t_list *blocks;
} t_node;


void addToNodes(t_node **head, int id);
void removeFromNodes(t_node **head, int id);
void printNodesId(t_node *node);
int countNodes(t_node *node);
char **stringToArray(char *str);
char *my_strcpy(char *str1, char *str2);
char *my_strncpy(char *str1, char *str2, int n);
char *my_strcat(char *str1, char *str2);
char *my_strchr(char *str, int c);
int my_atoi(char *str);
char *my_readline(int fd);
void readFromArchive(int *sync, int *numberOfNodes, t_node **Nodes);
void writeInArchive(int sync, int numberOfNodes, t_node *Nodes);
void showPrompt(int *sync, int *numberOfNodes, t_node **Nodes);
int my_strcmp( char *_str1_, char *_str2_);
t_list *my_lstnew(void *data, size_t dataSize);
void my_lstpush_back(t_list **lst, void *data, size_t dataSize);
void my_memset(void *data, int c, size_t size);
void *my_memalloc(size_t dataSize);
void my_memcpy(void *dst, const void *src, size_t dataSize);
void my_memdel(void **data);
void my_del(void *data, size_t size);
void my_lstprint(t_list **head);
void freeArray(char **array);
void addBlockToNode(t_node **head, int id, void *data, size_t dataSize);
void printNodesInfo(t_node *node);
void	my_putchar_fd(int c, int fd);
void    my_putchar(int c);
void	my_putstr_fd(char const *s, int fd);
void my_putstr(char const *s);
void	my_putnbr_fd(int n, int fd);
void	my_putnbr(int n);
