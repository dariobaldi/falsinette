#include "ft.h"

int ft_lstmap_test()
{
    int error = 0;
    char *strs[] = {"HELLO" , "darkness" , "MY" , "OLD" , "friend", 0};
    char **expected = (char *[6]){"hEllO" , "dArKnESS" , "MY" , "Old" , "frIEnd", 0};
    t_list *lst = create_linked_list((void **)strs, 5);
    t_list *lst2;

    lst2 = ft_lstmap(lst, &ft_f2, &del2);

    if (!is_valid_list(&lst2, expected))
    {
        error++;
        printf(RED "\nFAILED" DEFAULT "\nExpected:\n");
        putarray(expected);
        printf("Got:\n");
        putlist(&lst);
    }

    if (error == 0)
        printf(GREEN "OK" DEFAULT);

    lstclear(&lst, &del);
    lstclear(&lst2, &del2);
    return (error);
}
