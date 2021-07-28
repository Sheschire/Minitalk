/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:53:52 by tlemesle          #+#    #+#             */
/*   Updated: 2021/07/28 16:28:23 by tlemesle         ###   ########.fr       */
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

void    init_sigaction(struct sigaction *sa);
int	    ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void    handler(int sigtype);