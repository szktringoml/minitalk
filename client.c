/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:25:36 by string            #+#    #+#             */
/*   Updated: 2023/10/01 11:16:43 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libftex/libft.h"

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
	static int	shift = 7;
	static int	i = 8;

	while (*str)
	{
		printf("1\n");
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
	printf("2\n");
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

void error_handler(int argc, pid_t pid)
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

int	main(int argc, char *argv[])
{
	unsigned char	*str;
	pid_t pid;
	pid = (pid_t)ft_atoi(argv[1]);
	error_handler(argc, pid);
	str = argv[2];
	ft_send_message((const unsigned char *)str, pid);
	printf("3\n");
	exit(0);
}
