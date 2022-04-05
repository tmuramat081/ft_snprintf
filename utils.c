#include "ft_sprintf.h"
#include "libft.h"

/* Suport for base(radix), unsigned long long. */
char	*ft_uitoa_base(unsigned long long value, char *buff, int base)
{
	char	*offset;

	if (!buff)
		return (NULL);
	offset = buff;
	if (0 > (signed long long)value && base == 10)
	{
		*offset++ = '-';
		value = -value;
	}
	if (value / base)
		offset = ft_itoa_base(value / base, offset, base);
	*offset = (value % base) + '0';
	if (*offset > '9')
		*offset += 'a' - '9' - 1;
	*++offset = '\0';
	return (offset);
}
