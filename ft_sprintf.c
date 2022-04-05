#include "ft_sprintf.h"
#include "libft.h"

static int 	switch_conv_function(char *buff, size_t *left, const char fmt, va_list *ap)
{
	if  (fmt == 'c')
		return (copy_character_to_buff(buff, left, va_arg(*ap, int)));
	else if (fmt == 's')
		return (copy_string_to_buff(buff, left, va_arg(*ap, void *)));
	else if (fmt == 'd' || fmt == 'i')
		return (convert_decimal_to_buff(buff, left, ap, true));
	else if (fmt == 'u')
		return (convert_decimal_to_buff(buff, left, ap, false));
	else if (fmt == 'p')
		return (convert_address_to_buff(buff, left, ap));
	else if (fmt == 'x')
		return (convert_hexadecimal_to_buff(buff, left, ap, false));
	else if (fmt == 'X')
		return (convert_hexadecimal_to_buff(buff, left, ap, true));
	else if (fmt == '%')
		return (copy_character_to_buff(buff, left, '%'));
	return (-1);
}

static int ft_dosnprintf(char *buff, size_t left, const char *fmt, va_list *ap)
{
	int size;
	int	ret_len;

	size = 0;
	ret_len = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			size = copy_character_to_buff(buff, &left, *fmt);
		else
			size = switch_conv_function(buff, &left, *(fmt + 1), ap);
		if (size == -1)
			return (-1);
		fmt++;
		buff += size;
		left -= size;
		ret_len += size;
	}
	*buff = '\0';
	return (ret_len - 1);
}

int ft_snprintf(char *buff, size_t n, const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	ret = ft_dosnprintf(buff, n, fmt, &ap);
	va_end (ap);
	return (ret);
}
