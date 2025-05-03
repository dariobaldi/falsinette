#ifndef FT_H
# define FT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../utils/constants.h"
#include "libft.h"

int ft_lstnew_test();
int ft_lstadd_front_test();
int ft_lstsize_test();
int ft_lstlast_test();
int ft_lstadd_back_test();
int ft_lstdelone_test();


// HELPERS
t_list	*lstnew(void *content);
t_list *create_linked_list(void **contents, size_t size);
int  is_valid_list(t_list **lst, char **expected);
void  putlist(t_list **lst);
void  putarray(char **array);
void	lstclear(t_list **lst, void (*del)(void	*));
void del(void *content);
int strslen(char **strs);
t_list	*ft_getitem(t_list *lst, int index);

#endif