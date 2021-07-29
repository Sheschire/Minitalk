/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:53:52 by tlemesle          #+#    #+#             */
/*   Updated: 2021/07/29 17:45:11 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
#endif

#include <unistd.h>
#include <sys/types.h> // getpid()
#include <signal.h> // sigaction
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  s_data{
	char *av2;
	int av1;
	int i;
	int j;
	char byte[9];
	int	client_pid;
}               t_data;

t_data *g_data;

void    init_sigaction(struct sigaction *sa);
int	    ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void    handler(int sigtype);