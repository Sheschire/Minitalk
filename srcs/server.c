/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:52:18 by tlemesle          #+#    #+#             */
/*   Updated: 2021/07/28 17:54:35 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*byte_to_char(char *byte)
{
	int binary_table[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int i = -1;
    int ascii_value = 0;

    while (i++ <= 8)
        if (byte[i] == '1')
            ascii_value = ascii_value + binary_table[i];
	return (ascii_value);
}

void	rewrite_byte(int signum)
{
	static char	byte[9];
	int	i = 0;

	
	if (sigtype == SIGUSR1)
		write(1, "1", 1);
	if (sigtype == SIGUSR2)
		write(1, "0", 2);
}

void    init_sigaction(struct sigaction *sa)
{
	sa->sa_handler = rewrite_byte;
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = 0;
}

int		main(int ac, char **av)
{
	struct sigaction sa;
	
	(void)av;
	if (ac != 1)
	{
		printf("Too much arguments !\n");
		exit(0);
	}
	printf("PID : %d\n", getpid());
	init_sigaction(&sa);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}