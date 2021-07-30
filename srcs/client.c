/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:12:01 by tlemesle          #+#    #+#             */
/*   Updated: 2021/07/30 13:12:06 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int 	check_argv(int ac, char **av)
{
	int i;

	i = -1;
	if (ac != 3)
		return (0);
	while (av[1][i++])
		if (av[1][i] < 0 && av[1][i] > 9)
			return (0);
	return (1);
}

char	*char_to_byte(char c)
{
	char	*byte;
	int		i;
	int		j;
	
	i = -1;
	j = 7;
	byte = (char *)malloc(sizeof(char) * 9);
	byte[8] = '\0';
	while (i++ < 8)
		if ((1 << i) & c)
			byte[j--] = '1';
		else
			byte[j--] = '0';
	return (byte);
}

void	signal_to_server(int pid, char bit)
{
	if (bit == '1')
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	send_bit(int signum)
{
	static int i = 0;
	static int j = 0;
	char *byte;

	if (signum == SIGUSR1)
	{
		byte = char_to_byte(g_data->av2[i]);
		signal_to_server(g_data->av1, byte[j]);
		j++;
		if (j == 8)
		{
			if (g_data->av2[i] == '\0')
			{
				free(byte);
				exit(0);
			}
			i++;
			j = 0;
		}
		free(byte);
	}
}


int 	main(int ac, char **av)
{
	t_data	data;

	if (check_argv(ac, av) == 0)
	{
		printf("Error detected in program arguments !\n");
		exit(0);
	}
	data.av1 = ft_atoi(av[1]);
	data.av2 = av[2];
	data.i = 0;
	data.j = 0;
	g_data = &data;
	kill(data.av1, SIGUSR1);
	signal(SIGUSR1, send_bit);
	while (1)
	{
		printf("test");
		pause();
	}
}