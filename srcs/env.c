/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: red <red@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:21:14 by red               #+#    #+#             */
/*   Updated: 2023/02/22 11:51:03 by red              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	my_env(char **env)
{
	int	i;

	i = -1;
	if (!env)
		return ;
	while (env[++i])
		if (env[i] != NULL)
			(ft_putstr_fd(env[i], STDOUT_FILENO),
				ft_putchar_fd(10, STDOUT_FILENO));
}
