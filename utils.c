/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:31:32 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/10/01 11:32:59 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftex/libft.h"
#include "minitalk.h"

void	siguser1_kill(pid_t pid, int *shift)
{
	(void)shift;
	if (*shift == 7)
	{
		write(STDERR, "Only supports ASCII characters\n", 31);
		exit(1);
	}
	if (kill(pid, SIGUSER1) == -1)
	{
		write(STDERR, "kill Error\n", 11);
		exit(1);
	}
}

void	siguser2_kill(pid_t pid)
{
	if (kill(pid, SIGUSER2) == -1)
	{
		write(STDERR, "kill Error\n", 11);
		exit(1);
	}
}

void	error_handler(int argc, pid_t pid)
{
	if (pid < 2)
	{
		write(STDERR, "pid Error\n", 10);
		exit(1);
	}
	if (argc != 3)
	{
		write(STDERR, "input Error\n", 12);
		exit(1);
	}
}
