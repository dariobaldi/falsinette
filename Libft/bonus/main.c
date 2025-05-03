#include "ft.h"

int main()
{
    int errors = 0;

    // printf(PURPLE "\nft_lstnew\n");
    // errors += ft_lstnew_test();
    // printf(PURPLE "\nft_lstadd_front\n");
    // errors += ft_lstadd_front_test();
    // printf(PURPLE "\nft_lstsize\n");
    // errors += ft_lstsize_test();
    // printf(PURPLE "\nft_lstlast\n");
    // errors += ft_lstlast_test();
    // printf(PURPLE "\nft_lstadd_back\n");
    // errors += ft_lstadd_back_test();
    printf(PURPLE "\nft_lstdelone\n");
    errors += ft_lstdelone_test();

    return (errors);
}
