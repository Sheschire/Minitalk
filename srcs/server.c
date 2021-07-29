/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:52:18 by tlemesle          #+#    #+#             */
/*   Updated: 2021/07/29 18:35:15 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		byte_to_char(char *byte)
{
	int binary_table[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int i = -1;
    int ascii_value = 0;

	printf("BYTEBYTEBYTEBYTE = %s", byte);
    while (i++ <= 8)
        if (byte[i] == '1')
            ascii_value = ascii_value + binary_table[i];
	printf("ascii _value = %d\n", ascii_value);
	if (ascii_value == 255)
		exit(0);
	return (ascii_value);
}

void	init_g_data(t_data *data)
{
	data->client_pid = 0;
	data->i = 0;
	g_data = data;
	memset(g_data->byte, 0, 8);
}

void	rewrite_byte(int signum, siginfo_t *info, void *context)
{
	(void)context;
	printf("signum received = %d\n", signum);
	if (!g_data->client_pid)
	{
		g_data->client_pid = (int)info->si_pid;
		printf("pid client = %d\n", g_data->client_pid);
	}
	else
	{
		if (signum == SIGUSR1)
			g_data->byte[g_data->i++] = '1';
		else if (signum == SIGUSR2)
		{
			printf("ON RENTRE DANS USR2 -------------> i = %d\n", g_data->i);
			g_data->byte[g_data->i++] = '0';
		}
		if (g_data->i == 8)
		{
			g_data->byte[8] = '\0';
			g_data->i = 0;
			int ascii_value = byte_to_char(g_data->byte);
			if (ascii_value == 0)
			{
				write(1, "\n", 1);
				init_g_data(g_data);
				//kill(g_data->client_pid, SIGUSR2);
				return ;
			}
			write(1, &ascii_value, 1);
		}
	}
	kill(g_data->client_pid, SIGUSR1);
}

int		main(int ac, char **av)
{
	struct sigaction sa;
	t_data	data;

	(void)av;
	init_g_data(&data);
	if (ac != 1)
	{
		printf("Too much arguments !\n");
		exit(0);
	}
	printf("PID : %d\n", getpid());
	//init_sigaction(&sa);
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