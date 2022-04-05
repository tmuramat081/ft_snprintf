#include "ft_sprintf.h"
#include "libft.h"
#include <stdio.h>

int main ()
{
	int ret;
	char str[50];

	ret = ft_snprintf(str, 5, "ABCDEFGHIJKL");
	printf("%s\n", str);
	printf("%d\n", ret);
	fflush(stdout);
	ret = snprintf(str, 5, "ABCDEFGHIJKL");
	printf("%s\n", str);
	printf("%d\n", ret);
	fflush(stdout);
	ret = ft_snprintf(str, 2, "%c%c%c", 'a', 'b', 'c');
	printf("%s\n", str);
	printf("%d\n", ret);
	fflush(stdout);
	ret = snprintf(str, 2, "%c%c%c", 'a', 'b', 'c');
	printf("%s\n", str);
	printf("%d\n", ret);
	fflush(stdout);
	ret = ft_snprintf(str, 10, "Number:%d", INT_MAX);
	printf("%s\n", str);
	printf("%d\n", ret);
	fflush(stdout);
	ret = snprintf(str, 10, "Number:%d", INT_MAX);
	printf("%s\n", str);
	printf("%d\n", ret);
	fflush(stdout);
	ret = ft_snprintf(str, 8, "%x", -1);
	printf("%s\n", str);
	printf("%d\n", ret);
	fflush(stdout);
	ret = snprintf(str, 8, "%x", -1);
	printf("%s\n", str);
	printf("%d\n", ret);
	fflush(stdout);
	return (0);
}
