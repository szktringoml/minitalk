/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:07:16 by string            #+#    #+#             */
/*   Updated: 2023/09/25 14:07:17 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	unsigned char	c;

	c = 227;
	write(1, &c, 1);
	c = 129;
	write(1, &c, 1);
	c = 130;
	write(1, &c, 1);
	return (0);
}