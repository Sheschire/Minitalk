/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:52:18 by tlemesle          #+#    #+#             */
/*   Updated: 2021/07/27 14:43:25 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(void)
{
	pid_t	pid_value;
	pid_t	tmp_value;
	char	*pid_to_print;
	int		pid_len;

	pid_len = 0;
	pid_value = getpid();
	tmp_value = pid_value;
	while ((int)tmp_value > 9)
	{
		pid_len++;
		tmp_value /= 10;
	}
	pid_to_print = malloc(sizeof(char) * pid_len + 1);
	if (!pid_to_print)
		return ;
	while ((int)pid_value > 9)
	{
		pid_to_print[pid_len] = (int)pid_value % 10 + '0';
		pid_value /= 10;
		pid_len--;
	}
	pid_to_print[pid_len] = (int)pid_value % 10 + '0';
	write(1, "PID : ", 6);
	write(1, pid_to_print, strlen(pid_to_print));
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	print_pid();
	return (0);
}