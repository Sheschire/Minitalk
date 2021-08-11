/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:40:41 by tlemesle          #+#    #+#             */
/*   Updated: 2021/08/11 16:00:06 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	safekill(int client_pid, int signum)
{
	if (kill(client_pid, signum) < 0)
	{
		printf("ERROR : SIGNUM CANNOT BE RECEIVED PROPERLY\n");
		exit(0);
	}
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	minus;

	nb = 0;
	minus = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * minus);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
