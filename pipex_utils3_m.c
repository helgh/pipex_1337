/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:26:55 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/02/28 18:32:13 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	find_separator(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != 32)
		i++;
	while (str[i] != 0)
	{
		while (str[i] == 32)
			i++;
		if (str[i] == 39)
			return (str[i]);
		i++;
	}
	return (32);
}
