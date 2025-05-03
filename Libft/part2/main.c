#include "ft.h"

int main()
{
    int errors = 0;

    printf(PURPLE "\nft_substr\n");
    errors += ft_substr_test();
    printf(PURPLE "\nft_ft_strjoin\n");
    errors += ft_strjoin_test();
    printf(PURPLE "\nft_ft_strtrim\n");
    errors += ft_strtrim_test();
    printf(PURPLE "\nft_split\n");
    errors += ft_split_test();
    printf(PURPLE "\nft_ft_itoa\n");
    errors += ft_itoa_test();
    printf(PURPLE "\nft_strmapi\n");
    errors += ft_strmapi_test();
    printf(PURPLE "\nft_striteri\n");
    errors += ft_striteri_test();
    printf(PURPLE "\nft_putchar_fd\n");
    errors += ft_putchar_fd_test();
    printf(PURPLE "\nft_putstr_fd\n");
    errors += ft_putstr_fd_test();
    printf(PURPLE "\nft_putendl_fd\n");
    errors += ft_putendl_fd_test();
    printf(PURPLE "\nft_putnbr_fd\n");
    errors += ft_putnbr_fd_test();
    

    return (errors);
}
