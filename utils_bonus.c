/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:25:46 by string            #+#    #+#             */
/*   Updated: 2023/09/29 15:50:50 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	siguser1_kill(pid_t pid)
{
	if (kill(pid, SIGUSER1) == -1)
	{
		write(STDERR, "kill Error\n", 13);
		exit(1);
	}
}

void	siguser2_kill(pid_t pid)
{
	if (kill(pid, SIGUSER2) == -1)
	{
		write(STDERR, "kill Error\n", 13);
		exit(1);
	}
}

void	null_terminated_char_submit(pid_t pid)
{
	if (kill(pid, SIGUSER2) == -1)
	{
		write(STDERR, "kill Error\n", 13);
		exit(1);
	}
	usleep(10);
}
