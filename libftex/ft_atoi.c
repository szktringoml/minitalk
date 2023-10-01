/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:36:51 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/10/01 11:05:50 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	nb;
	size_t		i;
	int			minus_flag;

	i = 0;
	nb = 0;
	minus_flag = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus_flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		(nb = (nb * 10) + str[i] - 48);
		i++;
	}
	return (nb * minus_flag);
}
