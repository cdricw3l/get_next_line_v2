/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inet_pton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:44:28 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/31 00:43:34 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libip.h"

static int	ipv4_value_check(char **str)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			if (!ft_isdigit(str[i][j++]))
				return (0);
		value = ft_atoi(str[i++]);
		if (value > 255 || value < 0)
			return (0);
	}
	return (i);
}

int	get_ipv4(char *addr_str, struct in_addr *addr)
{
	int		len;
	char	**split;

	split = ft_split(addr_str, '.');
	if (!split)
		return (0);
	len = ipv4_value_check(split) - 1;
	if (len != 3)
	{
		ft_split_clean(&split);
		return (0);
	}
	ft_bzero(addr, sizeof(struct in_addr));
	while (len >= 0)
	{
		addr->s_addr |= ft_atoi(split[len--]);
		if (len >= 0)
			addr->s_addr = addr->s_addr << 8;
	}
	ft_split_clean(&split);
	return (1);
}

int	ft_inet_pton(int familly, char *addr_str, struct in_addr *addr)
{
	if (familly == AF_INET)
		return (get_ipv4(addr_str, addr));
	return (1);
}
