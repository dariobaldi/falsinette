#include "ft.h"

int main()
{
    int errors = 0;

    printf(PURPLE "ft_lstnew:");
    errors += ft_lstnew_test();
    printf(PURPLE "\nft_lstadd_front:");
    errors += ft_lstadd_front_test();
    printf(PURPLE "\nft_lstsize:");
    errors += ft_lstsize_test();
    printf(PURPLE "\nft_lstlast:");
    errors += ft_lstlast_test();
    printf(PURPLE "\nft_lstadd_back:");
    errors += ft_lstadd_back_test();
    printf(PURPLE "\nft_lstdelone:");
    errors += ft_lstdelone_test();
    printf(PURPLE "\nft_lstclear_test:");
    errors += ft_lstclear_test();
    printf(PURPLE "\nft_lstiter_test:");
    errors += ft_lstiter_test();
    printf(PURPLE "\nft_lstmap_test:");
    errors += ft_lstmap_test();

    return (errors);
}
