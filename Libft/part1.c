#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include "libft.h"
#include "../utils/constants.h"
#include "ft.h"

char *strs[] = {
    "",
    "Don't Panic.",
    "I'm gonna make him an offer he can't refuse.",
    "Gentlemen, you can't fight in here! This is the War Room!",
    "Here's Johnny!",
    "Well, cut my legs off and call me Shorty!",
    NULL};

int main()
{
    int errors = 0;

    // ft_print();
    errors += ft_test_1(&ft_isalpha, &isalpha, "isalpha");
    errors += ft_test_1(&ft_isdigit, &isdigit, "isdigit");
    errors += ft_test_1(&ft_isalnum, &isalnum, "isalnum");
    errors += ft_test_1(&ft_isascii, &isascii, "isascii");
    errors += ft_test_1(&ft_isprint, &isprint, "isprint");
    errors += ft_test_strlen();
    errors += ft_test_memset();
    errors += ft_test_bzero();
    errors += ft_test_memcpy();
    errors += ft_test_memmove();
    errors += ft_test_strlcpy();
    errors += ft_test_strlcat();
    errors += ft_test_1(&ft_toupper, &toupper, "toupper");
    errors += ft_test_1(&ft_tolower, &tolower, "tolower");
    errors += ft_test_strchr();
    errors += ft_test_strrchr();
    errors += ft_test_strncmp();
    errors += ft_test_memchr();
    errors += ft_test_memcmp();
    errors += ft_test_strnstr();
    errors += ft_test_atoi();
    errors += ft_test_calloc();
    errors += ft_test_strdup();

    return (errors);
}

int ft_test_1(int (*f)(int), int (*original)(int), char *name)
{
    int c = -1;
    int result, expected;

    while (c < 128)
    {
        result = (*f)(c);
        expected = (*original)(c);

        if ((!result && expected) || (result && !expected))
        {
            printf(RED "%s: KO\tFor %d got %d instead of %d\n" DEFAULT, name, c, result, expected);
            return (1);
        }
        c++;
    }
    printf(GREEN "%s: OK\n" DEFAULT, name);
    return (0);
}

int ft_test_strlen()
{
    int i;
    int expected, result;

    i = 0;
    while (strs[i])
    {
        result = ft_strlen(strs[i]);
        expected = strlen(strs[i]);

        if (result != expected)
        {
            printf(RED "strlen: KO\tFor \"%s\" got %d instead of %d\n" DEFAULT, strs[i], result, expected);
            return (1);
        }
        i++;
    }
    printf(GREEN "strlen: OK\n" DEFAULT);
    return (0);
}

int ft_test_memset()
{
    int i, cmp;
    void *expected, *result;
    char dst1[10], dst2[10];

    i = 42;
    while (i < 127)
    {
        result = ft_memset(dst1, i, 10);
        expected = memset(dst2, i, 10);

        cmp = strncmp(result, expected, 10);
        if (cmp)
        {
            printf(RED "memset: KO\tFor %d got %d for strncmp\n" DEFAULT, i, cmp);
            return (1);
        }
        i++;
    }
    printf(GREEN "memset: OK\n" DEFAULT);
    return (0);
}

int ft_test_bzero()
{
    int cmp;
    char dst1[10], dst2[10];

    memset(dst1, 21, 10);
    memset(dst2, 42, 10);

    ft_bzero(dst1, 10);
    bzero(dst2, 10);

    cmp = strncmp(dst1, dst2, 10);
    if (cmp)
    {
        printf(RED "bzero: KO\tGot %d for strncmp\n" DEFAULT, cmp);
        return (1);
    }
    printf(GREEN "bzero: OK\n" DEFAULT);
    return (0);
}

int ft_test_memcpy()
{
    int i, len, n, cmp;
    void *expected, *result;
    char dst1[10], dst2[10];

    i = 0;
    while (strs[i])
    {
        len = strlen(strs[i]);
        if (len > 10)
            n = 10;
        else
            n = len;
        result = ft_memcpy(dst1, strs[i], n);
        expected = memcpy(dst2, strs[i], n);

        cmp = strncmp(result, expected, n);
        if (cmp)
        {
            printf(RED "memcpy: KO\tFor \"%s\" got %d for cmp\n" DEFAULT, strs[i], cmp);
            return (1);
        }
        i++;
    }
    printf(GREEN "memcpy: OK\n" DEFAULT);
    return (0);
}

int ft_test_memmove()
{
    int cmp;
    void *expected, *result;
    char dst1[] = "Hello World";
    char dst2[] = "Hello World";

    result = ft_memmove(dst1 + 3, dst1, 5);
    expected = memmove(dst2 + 3, dst2, 5);
    cmp = strncmp(result, expected, 12);
    if (cmp)
    {
        printf(RED "memmove: KO\toverlapping src and dst\n" DEFAULT);
        return (1);
    }

    result = ft_memmove(dst1 + 5, dst1, 3);
    expected = memmove(dst2 + 5, dst2, 3);
    cmp = strncmp(result, expected, 12);
    if (cmp)
    {
        printf(RED "memmove: KO\tnon overlapping src and dst\n" DEFAULT);
        return (1);
    }
    printf(GREEN "memmove: OK\n" DEFAULT);
    return (0);
}

int ft_test_strlcpy()
{
    int i;
    int expected, result;
    char dst1[45], dst2[45];

    i = 0;
    while (strs[i])
    {
        result = ft_strlcpy(dst1, strs[i], 45);
        expected = strlcpy(dst2, strs[i], 45);

        if (result != expected)
        {
            printf(RED "strlcpy: KO\tFor \"%s\" got %d instead of %d\n" DEFAULT, strs[i], result, expected);
            return (1);
        }
        else if (strcmp(dst1, dst2))
        {
            printf(RED "strlcpy: KO\tFor \"%s\" comparison got %d\n" DEFAULT, strs[i], strcmp(dst1, dst2));
            return (1);
        }
        i++;
    }
    printf(GREEN "strlcpy: OK\n" DEFAULT);
    return (0);
}

int ft_test_strlcat()
{
    int i;
    int expected, result;
    char dst1[45], dst2[45];

    i = 0;
    while (strs[i])
    {
        strcpy(dst1, "Test");
        strcpy(dst2, "Test");
        result = ft_strlcat(dst1, strs[i], 45);
        expected = strlcat(dst2, strs[i], 45);

        if (result != expected)
        {
            printf(RED "strlcat: KO\tFor \"%s\" got %d instead of %d\n" DEFAULT, strs[i], result, expected);
            return (1);
        }
        else if (strcmp(dst1, dst2))
        {
            printf(RED "strlcat: KO\tFor \"%s\" comparison got %d\n" DEFAULT, strs[i], strcmp(dst1, dst2));
            return (1);
        }
        i++;
    }
    printf(GREEN "strlcat: OK\n" DEFAULT);
    return (0);
}

int ft_test_strchr()
{
    int i, c;
    char *expected, *result;

    i = 0;
    while (strs[i])
    {
         // Looking for the first appearence of a and then \0
         c = 97;
         while (c >= 0)
         {
             result = ft_strchr(strs[i], c);
             expected = strchr(strs[i], c);
     
             if (result != expected)
             {
                 printf(RED "strchr: KO\tFor \"%s\" and c=%d got %p instead of %p\n" DEFAULT, strs[i],c, result, expected);
                 return (1);
             }
             c -= 97;
         }
         i++;
    }
    printf(GREEN "strchr: OK\n" DEFAULT);
    return (0);
}

int ft_test_strrchr()
{
    int i, c;
    char *expected, *result;

    i = 0;
    while (strs[i])
    {
         // Looking for the first appearence of a and then \0
         c = 97;
         while (c >= 0)
         {
             result = ft_strrchr(strs[i], c);
             expected = strrchr(strs[i], c);
     
             if (result != expected)
             {
                 printf(RED "strrchr: KO\tFor \"%s\" and c=%d got %p instead of %p\n" DEFAULT, strs[i],c, result, expected);
                 return (1);
             }
             c -= 97;
         }
         i++;
    }
    printf(GREEN "strrchr: OK\n" DEFAULT);
    return (0);
}

int ft_test_strncmp()
{
    int i, j;
    int expected, result;

    i = 0;
    while (strs[i])
    {
        j = 0;
        while (strs[j])
        {
            result = ft_strncmp(strs[i], strs[j], 30);
            expected = strncmp(strs[i], strs[j], 30);

            if (result != expected)
            {
                printf(RED "strncmp: KO\tFor \"%s\" got %d instead of %d\n" DEFAULT, strs[i], result, expected);
                return (1);
            }
            j++;
        }
        i++;
    }
    printf(GREEN "strncmp: OK\n" DEFAULT);
    return (0);
}

int ft_test_memchr()
{
    int i, c, len;
    char *expected, *result;

    i = 0;
    while (strs[i])
    {
        len = strlen(strs[i]);
         // Looking for the first appearence of a and then \0
         c = 97;
         while (c >= 0)
         {
             result = ft_memchr(strs[i], c, len + 1);
             expected = memchr(strs[i], c, len + 1);
     
             if (result != expected)
             {
                 printf(RED "memchr: KO\tFor \"%s\" and c=%d got %p instead of %p\n" DEFAULT, strs[i],c, result, expected);
                 return (1);
             }
             c -= 97;
         }
         i++;
    }
    printf(GREEN "memchr: OK\n" DEFAULT);
    return (0);
}

int ft_test_memcmp()
{
    int i, j, len, ilen, jlen;
    int expected, result;

    i = 0;
    while (strs[i])
    {
        j = 0;
        while (strs[j])
        {
            ilen = strlen(strs[i]);
            jlen = strlen(strs[j]);
            len = ilen;
            if (ilen > jlen)
                len = jlen;
            result = ft_memcmp(strs[i], strs[j], len);
            expected = memcmp(strs[i], strs[j], len);

            if (result != expected)
            {
                printf(RED "memcmp: KO\tFor \"%s\" got %d instead of %d\n" DEFAULT, strs[i], result, expected);
                return (1);
            }
            j++;
        }
        i++;
    }
    printf(GREEN "memcmp: OK\n" DEFAULT);
    return (0);
}

int ft_test_strnstr()
{
    int     i;
    char    *expected, *result;
    char    *ref = "an";

    i = 0;
    while (strs[i])
    {
        result = ft_strnstr(strs[i], ref, 22);
        expected = strnstr(strs[i], ref, 22);

        if (result != expected)
        {
            printf(RED "strnstr: KO\tFor \"%s\" got %p instead of %p\n" DEFAULT, strs[i], result, expected);
            return (1);
        }
        i++;
    }
    printf(GREEN "strnstr: OK\n" DEFAULT);
    return (0);
}

int ft_test_atoi()
{
    int i;
    int expected, result;

    char *tests[] = {
        "42",              // simple positive number
        "    42",          // leading spaces
        "-42",             // negative number
        "+42",             // explicit positive sign
        "0042",            // leading zeros
        "   -0042",        // spaces + sign + leading zeros
        "4193 with words", // numbers followed by letters
        "words and 987",   // letters before numbers (invalid)
        "-91283472332",    // number smaller than INT_MIN
        "91283472332",     // number larger than INT_MAX
        ","                // empty string
        "   ",             // only spaces
        ",+"               // only plus sign, no digits
        ",-"               // only minus sign, no digits
        "00000",           // multiple zeros
        "0",               // single zero
        "  -0012a42",      // number then letter, should stop parsing at 'a'
        "  + 413",         // plus sign followed by space (invalid)
        "--2",             // two minus signs (invalid)
        "++1",             // two plus signs (invalid)
        "  -13-8",         // two numbers separated by a minus inside
        "2147483647",      // INT_MAX
        "-2147483648",     // INT_MIN
        "2147483648",      // INT_MAX + 1
        "-2147483649",     // INT_MIN - 1
        NULL};

    i = 0;
    while (tests[i])
    {
        result = ft_atoi(tests[i]);
        expected = atoi(tests[i]);

        if (result != expected)
        {
            printf(RED "atoi: KO\tFor \"%s\" got %d instead of %d\n" DEFAULT, strs[i], result, expected);
            return (1);
        }
        i++;
    }
    printf(GREEN "atoi: OK\n" DEFAULT);
    return (0);
}

int ft_test_calloc()
{
    int failed = 0;
    int i;
    void *p;

    p = ft_calloc(0, sizeof(int));
    if(p != NULL)
    {
        printf(RED "calloc: KO\tcount == 0 not managed\n" DEFAULT);
        failed++;
        free(p);
	}
    p = ft_calloc(5, 0);
    if(p != NULL)
    {
        printf(RED "calloc: KO\tsize == 0 not managed\n" DEFAULT);
        failed++;
        free(p);
	}
	p = ft_calloc(5, sizeof(int));
    if(p == NULL)
    {
        printf(RED "calloc: KO\tcouldn't allocate memory for 5 ints\n" DEFAULT);
        failed++;
	}
    else
    {
        i = 0;
        while (i < 5)
        {
            if (*(int *)(p + i) != 0)
            {
                printf(RED "calloc: KO\tmemory is not set to 0\n" DEFAULT);
                failed++;
                break;
            }
            i++;
        }
        free(p);
    }
	p = ft_calloc(INT_MAX, sizeof(int));
    if(p != NULL)
    {
        printf(RED "calloc: KO\tint overflow is not verified\n" DEFAULT);
        free(p);
        failed++;
	}

    if (!failed)
        printf(GREEN "calloc: OK\n" DEFAULT);
	return (failed);
}

int ft_test_strdup()
{
	int failed = 0;
	char src[] = "This is the same";
	char *dest;

	dest = ft_strdup(src);
	if (dest == src && !strcmp(src, dest))
	{
        printf(RED "strdup: KO\treturned same pointer as src\n" DEFAULT);
        failed = 1;

	}
	if (strcmp(src, dest))
	{
        printf(RED "strdup: KO\tcopied string is not the same\nExpected:%s\nResult:%s\n" DEFAULT, src, dest);
		failed = 1;
	}

	free(dest);
    if (!failed)
        printf(GREEN "strdup: OK\n" DEFAULT);

	return (failed);
}