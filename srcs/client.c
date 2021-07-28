/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:12:01 by tlemesle          #+#    #+#             */
/*   Updated: 2021/07/28 16:53:15 by tlemesle         ###   ########.fr       */
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

int 	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*byte;
	
	i = 0;
	byte = 0;
	if (check_argv(ac, av) == 0)
	{
		printf("Error detected in program arguments !\n");
		exit(0);
	}
	while (av[2][i])
	{
		byte = char_to_byte(av[2][i]);
		j = 0;
		while (byte[j])
		{
			signal_to_server(ft_atoi(av[1]), byte[j]);
			j++;
			usleep(100);
		}
		free(byte);
		i++;
	}
}