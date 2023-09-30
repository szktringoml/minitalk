/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:25:52 by string            #+#    #+#             */
/*   Updated: 2023/09/25 13:54:24 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const unsigned char *s);

int		ft_atoi(const char *str);

void	siguser1_kill(pid_t pid, int *shift);

void	siguser2_kill(pid_t pid);

void	null_terminated_char_submit(pid_t pid);

void	ft_send_message(const unsigned char *str, pid_t pid);

void	ft_handler_from_client(int sig, siginfo_t *info, void *context);

# define SIGUSER1 10
# define SIGUSER2 12
# define STDERR 2

#endif