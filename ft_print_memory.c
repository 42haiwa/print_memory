/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:03:46 by cjouenne          #+#    #+#             */
/*   Updated: 2023/08/05 13:45:50 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned long	ft_strlen(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

void	ft_putnbr_base(unsigned long n, char *base)
{
	if (n < ft_strlen(base))
		write(1, &base[n], 1);
	if (n >= ft_strlen(base))
	{
		ft_putnbr_base(n / ft_strlen(base), base);
		ft_putnbr_base(n % ft_strlen(base), base);
	}
}

int	ft_is_printable(char c)
{
	if ((c >= 0 && c <= 31) || c == 127)
		return (0);
	return (1);
}

void	print_line(unsigned char *_addr, char *_s_addr)
{
	int				i;

	i = 0;
	while (i < 16)
	{
		if (*(_addr + i) < 16)
			write(1, "0", 1);
		ft_putnbr_base((unsigned long)(*(_addr + i)), "0123456789abcdef");
		if (*(_addr + i + 1) < 16)
			write(1, "0", 1);
		ft_putnbr_base((unsigned long)(*(_addr + i + 1)), "0123456789abcdef");
		write(1, " ", 1);
		i += 2;
	}
	i = -1;
	while (++i < 16)
	{
		if (!ft_is_printable(*(_s_addr + i)))
			write(1, ".", 1);
		else
			write(1, _s_addr + i, 1);
	}
}

void	*ft_print_memory(void *addr, unsigned long size)
{
	size_t			i;
	unsigned long	start;

	i = 0;
	start = (unsigned long) addr;
	while (i < size)
	{
		ft_putnbr_base(start + i, "0123456789abcdef");
		write(1, ": ", 2);
		print_line((unsigned char *)(addr + i), (char *)(addr + i));
		write(1, "\n", 1);
		i += 16;
	}
	return (addr + i);
}
/*
int	main(void)
{
	char	buf[] = "Hello World !\n";
	ft_print_memory(buf, 32);
}
*/
