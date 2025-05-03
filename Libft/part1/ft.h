#ifndef FT_H
# define FT_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>
#include <limits.h>
#include "libft.h"
#include "../../utils/constants.h"

int ft_weirdcmp(int a, int b);
int ft_test_1(int (*f)(int), int (*original)(int), char *name);

int ft_test_strlen();
int ft_test_memset();
int ft_test_bzero();
int ft_test_memcpy();
int ft_test_memmove();
int ft_test_strlcpy();
int ft_test_strlcat();
int ft_test_strchr();
int ft_test_strrchr();
int ft_test_strncmp();
int ft_test_memchr();
int ft_test_memcmp();
int ft_test_strnstr();
int ft_test_atoi();
int ft_test_calloc();
int ft_test_strdup();

#endif