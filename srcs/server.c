/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:52:18 by tlemesle          #+#    #+#             */
/*   Updated: 2021/08/11 15:59:20 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_g_data(t_data *data)
{
	data->client_pid = 0;
	data->i = 0;
	g_data = data;
	memset(g_data->byte, 0, 8);
}

int	byte_to_char(void)
{
	int	binary_table[8];
	int	ascii_value;
	int	i;

	binary_table = {128, 64, 32, 16, 8, 4, 2, 1};
	i = -1;
	ascii_value = 0;
	g_data->i = 0;
	g_data->byte[8] = '\0';
	while (i++ <= 8)
		if (g_data->byte[i] == '1')
			ascii_value = ascii_value + binary_table[i];
	if (ascii_value == 0)
	{
		write(1, "\n", 1);
		init_g_data(g_data);
		return (1);
	}
	write(1, &ascii_value, 1);
	return (0);
}

void	rewrite_byte(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (!g_data->client_pid)
		g_data->client_pid = (int)info->si_pid;
	else
	{
		if (signum == SIGUSR1)
			g_data->byte[g_data->i++] = '1';
		else if (signum == SIGUSR2)
			g_data->byte[g_data->i++] = '0';
		if (g_data->i == 8)
			if (byte_to_char())
				return ;
	}
	safekill(g_data->client_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	t_data				data;

	(void)av;
	init_g_data(&data);
	if (ac != 1)
		exit(0);
	printf("PID : %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = rewrite_byte;
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		exit(0);
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
		exit(0);
	while (1)
		pause();
	return (0);
}
