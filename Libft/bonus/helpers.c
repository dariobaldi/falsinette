#include "ft.h"

t_list	*lstnew(void *content)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}

void	lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

void	lstclear(t_list **lst, void (*del)(void	*))
{
	t_list	*next;

    if (!lst)
    {
        return ;
    }

	while (*lst)
	{
		next = (*lst)->next;
		lstdelone(*lst, del);
		*lst = next;
	}
}

t_list *create_linked_list(void **contents, size_t size)
{
    t_list *head = NULL;
    t_list *temp = NULL;

    for (size_t i = 0; i < size; i++) {
        t_list *new_node = lstnew(contents[i]);
        if (!new_node) {
            return NULL;
        }

        if (!head) {
            head = new_node;
        } else {
            temp->next = new_node;
        }

        temp = new_node;
    }

    return head;
}

int  is_valid_list(t_list **lst, char **expected)
{
    int i, len;
    t_list *current;

    i = 0;
    if (!lst)
        return (0);
    current = *lst;
    while (expected[i])
    {
        len = strlen(expected[i]);
        if (!current)
            return (0);
        if (!current->content && expected[i])
        return(0);
        if (!current->content && !expected[i])
        {
            i++;
            current = current->next;
            continue;
        }
        if (strncmp((char *)(current->content), expected[i], len))
            return (0);
        current = current->next;
        i++;
    }
    return (1);
}

void  putlist(t_list **lst)
{
    int first = 1;
    char    *str;
    t_list *current;

    if (!lst)
    {
        printf("\t**No list**\n");
        return ;
    }
    current = *lst;
    printf("\t[");
    while (current)
    {
        if (!first)
            printf(" , ");
        str = (char *)current->content;
        if (str)
            printf("\"%s\"", str);
        else
            printf("NULL");
        first = 0;
        current = current->next;
    }
    printf("]\n");
}

void  putarray(char **array)
{
    int first = 1;

    printf("\t[");
    while (*array)
    {
        if (!first)
            printf(" , ");
        printf("\"%s\"", *array);
        first = 0;
        array++;
    }
    printf("]\n");
}

void del(void *content)
{
    content++;
};

void del2(void *content)
{
    free(content);
};

int strslen(char **strs)
{
    int i;

    i = 0;
    while (strs[i])
        i++;
    return (i);
}

t_list	*ft_getitem(t_list *lst, int index)
{
    int i;

    i = 0;
	while (lst && i <= index)
	{
        if (i == index)
            return (lst);
		if (lst->next == NULL)
			return (NULL);
		lst = lst->next;
        i++;
	}
	return (NULL);
}

void ft_f(void *value)
{
    char *c = (char *)value;
    while (*c)
    {
    if (*c % 2 != 0)
        *c = toupper(*c);
    else
        *c = tolower(*c);
    c++;
    }
}

void *ft_f2(void *value)
{
    char *str = (char *)value;
    int len = strlen(str);
    char *result = malloc (sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    strlcpy(result, str, len + 1);
    ft_f(result);
    return (result);
}