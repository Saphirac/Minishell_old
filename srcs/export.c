/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: red <red@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:58:59 by red               #+#    #+#             */
/*   Updated: 2023/02/25 17:55:31 by red              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_export(char *str)
{
	int	i;
	int	equal;

	i = -1;
	equal = 0;
	if (str[0] == '=')
		return (1);
	while (str[++i])
		if (str[i] == '=')
			equal += 1;
	if (equal == 0)
		return (2);
	return (0);
}

static char	**inc_env(char *toadd, char **env)
{
	char	**new_env;
	int		i;

	new_env = (char **)malloc(sizeof(char *) * (tab_val(env) + 2));
	if (!new_env)
		return (NULL);
	i = -1;
	while (env[++i])
		new_env[i] = env[i];
	new_env[i] = toadd;
	i += 1;
	new_env[i] = NULL;
	return (new_env);
}

char	**my_export(char *str, char **env)
{
	if (is_valid_export(str) == 0)
		return (inc_env(str, env));
	//if (is_valid_export(str) == 1)
	//	(g_exit_code == 1);
	return (env);
}
