#include "ft.h"

int ft_lstclear_test()
{
    int error = 0;
    char **strs = (char *[6]){"hello", "darkness", "my", "old", "friend", 0};
    t_list *lst = create_linked_list((void **)strs, 5);

    ft_lstclear(&lst, &del);

    if (lst != 0)
    {
        error++;
        printf(RED "\nFAILED clearing linked list, lst points to %p"DEFAULT, lst);
    }

    if (error == 0)
        printf(GREEN "OK" DEFAULT);
    return (error);
}
