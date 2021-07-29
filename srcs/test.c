/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:25:54 by tlemesle          #+#    #+#             */
/*   Updated: 2021/07/29 15:43:15 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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

int	main(int ac, char **av)
{
	int		pid;
	char	buffer[10100];
	char	*char_10 = "\"10 char !!\n\"";
	char	*char_100 = "\"Quand la vache se leve du mauvais pied, elle meuuuuuuhnace tous les passants qui se risquent par ici\n\"";
	char	*char_1000 = "\"ecpvZhf36Q2BESvHoybuadGNMfyDK5zlqVT2ryCqJkf2k7xEN4xMAL47hWSqeOzwIS2AJNXRe5qYOZuy7razgocdWFZzkcaMBDGUxViZVEE6QLQSdnTwVJ1VyYggucRQH5X1QWvDDrgZzn0XyckAhlvuOUPpodGofusFRPjlH5dcRbWMYnaJOQZDjo6ufSB553ob4r94mlsig0qReosLJBx72PW5jaUkRFmXvBtVhZj7jsA1H3JmckaSzu1ygxSWFuuMnpBTUMiFdZcoaBZpauINGRsiJfv3y1GXSpxxgxYQfqhmB44F2cpwRXqrRF1QJnLsjGQZ6yyQTLvxKsOfM71h1cUlAEZntpq3R47NZrZv206rOU2bppmFqtqBDkWgnHkTcjRxVeYhMY5OPvMPVcoQHqJFslrgSBP1jQeiD2pUSOvIbs8AHbFv0IR9lLAUkQGcE1qsuB7UhfaExaHM75nhmJi3NYLL5VglZP73rj0LV4BerxBCEZbbX8B5ipIFYqqBUtrEgZJ4hxd9HlN6RwJFsS1sV0Q3YUB3xbuzgABbeOg04GxzdKBPkleOi6OP3cBXLoS78EoDHomOLX2oHyXsiQNGjaJVNLVgdWehmKKnAcKzemPZoIMO7t3FunsN9fGHm1EWcoaJhoyDTQZ8P9Mk8ZFdUeViXvYj9vNtuzlHAQvRwvBTzc9jn8mpOEQiGAzfNxkPCUmON9flyztdkXy3QmE8xrVy2mMQc0fyMFG1NlMAzedaT2LQ4N83Vvv3AwztlUMC8X5e8Yl4QTT71IcqWrqSmaWMQWs0sG130USz37ItTktLZnqUsJf4JZgmP4FTGhOe5Tyi3EoOrFr6GOff6UifmyBweSMyMKGTwyJ45Yncy6FcCYJ8jFjXMszRuY5yn7Q1PXk29CdnBGiyw25KCtc0q4h636o31Q5BB3mpUiwGJrVboMfxoc7O2E9xMswlVmJ3j7L8MpNtRoanPtUXWlBIsP5NpqPbhHOY\n\"";
	char	*char_10000 = "\"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\n\"";

	
	pid = ft_atoi(av[1]);
	if (ac != 3)
	{
		printf("Wrong number of parameters\n");
		exit(0);
	}
	if (!ft_strcmp(av[2], "1"))
		snprintf(buffer, sizeof(buffer), "./client %d a", pid);
	else if (!ft_strcmp(av[2], "10"))
		snprintf(buffer, sizeof(buffer), "./client %d %s", pid, char_10);
	else if (!ft_strcmp(av[2], "100"))
		snprintf(buffer, sizeof(buffer), "./client %d %s", pid, char_100);
	else if (!ft_strcmp(av[2], "1000"))
		snprintf(buffer, sizeof(buffer), "./client %d %s", pid, char_1000);
	else if (!ft_strcmp(av[2], "10000"))
		snprintf(buffer, sizeof(buffer), "./client %d %s", pid, char_10000);
	system(buffer);
}