/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: red <red@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:27:06 by red               #+#    #+#             */
/*   Updated: 2023/02/22 11:48:26 by red              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**red_env(char *torem, char **env)
{
	char	**new_env;
	int		nocpy;
	int		i;

	new_env = (char **)malloc(sizeof(char *) * tab_val(env));
	if (!new_env)
		return (NULL);
	i = -1;
	nocpy = find_strintab(torem, env);
	if (nocpy == -1)
	{
		free(new_env);
		return (NULL);
	}
	while (env[++i] && i != nocpy)
		new_env[i] = env[i];
	i += 1;
	nocpy = i - 1;
	while (env[i])
		new_env[nocpy++] = env[i++];
	new_env[nocpy] = NULL;
	return (new_env);
}

char	**my_unset(char *str, char **env)
{
	if (find_strintab(str, env) != -1)
		return (red_env(str, env));
	return (NULL);
}
