#include "ft.h"

int ft_lstiter_test()
{
    int error = 0;
    char s1[] = "HELLO";
    char s2[] = "darkness";
    char s3[] = "MY";
    char s4[] = "old";
    char s5[] = "FRIEND";
    char *strs[6];
    strs[0] = s1;
    strs[1] = s2;
    strs[2] = s3;
    strs[3] = s4;
    strs[4] = s5;
    strs[5] = 0;


    char **expected = (char *[6]){"hEllO" , "dArKnESS" , "MY" , "Old" , "frIEnd", 0};
    t_list *lst = create_linked_list((void **)strs, 5);

    ft_lstiter(lst, &ft_f);

    if (!is_valid_list(&lst, expected))
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
    return (error);
}
