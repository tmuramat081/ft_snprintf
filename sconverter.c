#include "ft_sprintf.h"
#include "libft.h"

int	copy_character_to_buff(char *buff, size_t *left, int c)
{
	if (*left == 1)
		return (0);
	*buff = c;
	return (1);
}

int	copy_string_to_buff(char *buff, size_t *left, void *str)
{
	int ret_len;

	if (!str)
		return (ft_strlcpy(buff, "(null)", *left));
	ret_len = ft_strlcpy(buff, str, *left);
	return (ret_len);
}

int	convert_decimal_to_buff(char *buff, size_t *left, va_list *ap, bool is_signed)
{
	unsigned long long	value;
	char tmp[11];
	int		ret_len;

	if (is_signed == false)
		value = va_arg(*ap, unsigned int);
	else
		value = va_arg(*ap, int);
	ft_itoa_base(value, tmp, 10);
	ret_len = ft_strlcpy(buff, tmp, *left);
	return (ret_len);
}

int convert_address_to_buff(char *buff, size_t *left, va_list *ap)
{
	uintptr_t value;
	int	ret_len;
	char tmp[11];

	value = va_arg(*ap, uintptr_t);
	ft_itoa_base(value, tmp, 16);
	ret_len = ft_strlcpy(buff, "0x", *left);
	ret_len += ft_strlcat(buff, tmp, *left);
	return (ret_len);
}

int convert_hexadecimal_to_buff(char *buff, size_t *left, va_list *ap, bool is_large)
{
	unsigned long long value;
	int	ret_len;
	char tmp[11];

	value = va_arg(*ap, unsigned int);
	ft_itoa_base(value, tmp, 16);
	ret_len = ft_strlcpy(buff, tmp, *left);
	if (is_large == true)
		str_toupper(buff);
	return (ret_len);
}
