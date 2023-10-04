/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:25:52 by string            #+#    #+#             */
/*   Updated: 2023/10/01 11:33:48 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	error_handler(int argc, pid_t pid);

void	siguser1_kill(pid_t pid, int *shift);

void	siguser2_kill(pid_t pid);

void	null_terminated_char_submit(pid_t pid);

void	ft_send_message(const unsigned char *str, pid_t pid);

void	ft_handler_from_client(int sig, siginfo_t *info, void *context);

# define SIGUSER1 10
# define SIGUSER2 12
# define STDERR 2

#endif