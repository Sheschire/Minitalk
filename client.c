/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:12:01 by tlemesle          #+#    #+#             */
/*   Updated: 2021/07/27 16:21:13 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int check_parameters(int ac, char **av)
{
    int i;

    i = -1;
    while (av[1][i++])
        if (av[1][i] < 0 && av[1][i] > 9)
            return (0);
    if (ac != 3)
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    if (check_parameters(ac, av) == 0)
    {
        printf("Error detected in program arguments !\n");
        exit(0);
    }
}