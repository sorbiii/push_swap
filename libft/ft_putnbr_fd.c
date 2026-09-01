/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:43:59 by nadamczy          #+#    #+#             */
/*   Updated: 2024/12/19 13:44:55 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	char	c;

	if (i == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (i < 0)
	{
		write(fd, "-", 1);
		i *= (-1);
	}
	if (i < 10)
	{
		c = i + 48;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
}

/*int main()
{
	ft_putnbr_fd(-71787878, 1);
}*/
