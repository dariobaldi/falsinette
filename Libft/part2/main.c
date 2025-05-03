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
    // TODO: test split
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
    

    return (errors);
}
