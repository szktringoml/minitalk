/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:25:46 by string            #+#    #+#             */
/*   Updated: 2023/10/04 11:18:31 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	siguser1_kill(pid_t pid)
{
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

void	null_terminated_char_submit(pid_t pid)
{
	if (kill(pid, SIGUSER2) == -1)
	{
		write(STDERR, "kill Error\n", 11);
		exit(1);
	}
	usleep(10);
}

void	error_handler(int argc, pid_t pid)
{
	if (pid <= 1)
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