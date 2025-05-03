#include "ft.h"

int main()
{
    int errors = 0;

    printf(PURPLE "ft_substr: ");
    errors += ft_substr_test();
    printf(PURPLE "\nft_ft_strjoin: ");
    errors += ft_strjoin_test();
    printf(PURPLE "\nft_ft_strtrim: ");
    errors += ft_strtrim_test();
    printf(PURPLE "\nft_split: ");
    errors += ft_split_test();
    printf(PURPLE "\nft_ft_itoa: ");
    errors += ft_itoa_test();
    printf(PURPLE "\nft_strmapi: ");
    errors += ft_strmapi_test();
    printf(PURPLE "\nft_striteri: ");
    errors += ft_striteri_test();
    printf(PURPLE "\nft_putchar_fd: ");
    errors += ft_putchar_fd_test();
    printf(PURPLE "\nft_putstr_fd: ");
    errors += ft_putstr_fd_test();
    printf(PURPLE "\nft_putendl_fd: ");
    errors += ft_putendl_fd_test();
    printf(PURPLE "\nft_putnbr_fd: ");
    errors += ft_putnbr_fd_test();
    

    return (errors);
}
