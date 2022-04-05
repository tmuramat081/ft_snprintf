#ifndef FT_SPRINTF_H
# define FT_SPRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>

/**********ft_snprintf.c**********/
int		ft_snprintf(char *buff, size_t left, const char *s, ...);
static int 	ft_dosnprintf(char *buff, size_t left, const  char *fmt, va_list *ap);
static int	switch_conv_function(char *buff, size_t *left, const char fmt, va_list *ap);
/**********converter.c**********/
int		copy_character_to_buff(char *buff, size_t *left, int c);
int		copy_string_to_buff(char *buff, size_t *left, void *str);
int		convert_decimal_to_buff(char *buff, size_t *left, va_list *ap, bool is_signed);
int		convert_address_to_buff(char *buff, size_t *left, va_list *ap);
int		convert_hexadecimal_to_buff(char *buff, size_t *left, va_list *ap, bool is_large);
/**********utils**********/
char	*ft_itoa_base(unsigned long long value, char *buff, int base);
void	str_toupper(char *str);

#endif
