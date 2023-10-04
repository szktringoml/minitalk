/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:25:36 by string            #+#    #+#             */
/*   Updated: 2023/10/01 11:32:36 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftex/libft.h"
#include "minitalk.h"

void	null_terminated_char_submit(pid_t pid)
{
	if (kill(pid, SIGUSER2) == -1)
	{
		write(STDERR, "kill Error\n", 11);
		exit(1);
	}
	usleep(10);
}

void	ft_send_message(const unsigned char *str, pid_t pid)
{
	static int	shift;
	static int	i;

	shift = 7;
	i = 8;
	while (*str)
	{
		if ((*str >> shift) % 2 == 1)
			siguser1_kill(pid, &shift);
		if ((*str >> shift) % 2 == 0)
			siguser2_kill(pid);
		shift--;
		if (shift == -1)
		{
			shift = 7;
			str++;
		}
		usleep(120);
	}
	sleep(1);
	while (i--)
		null_terminated_char_submit(pid);
}

//void create_blockset(struct sigaction *s_sigaction, sigset_t *blockset)
//{
//	if(sigemptyset(&s_sigaction->sa_mask) == -1)
//	{
//		write(1, "sigenptyset Error", 18);
//		exit(1);
//	}
//	if(sigemptyset(blockset) == -1)
//	{
//		write(1, "sigenptyset Error", 18);
//		exit(1);
//	}
//	if(sigaddset(blockset, SIGINT) == -1)
//	{
//		write(1, "sigaddset Error", 17);
//			exit(1);
//	}
//}

int	main(int argc, char *argv[])
{
	unsigned char	*str;
	pid_t			pid;

	pid = (pid_t)ft_atoi(argv[1]);
	error_handler(argc, pid);
	str = (unsigned char *)argv[2];
	ft_send_message((const unsigned char *)str, pid);
	exit(0);
}
