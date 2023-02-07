/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:53:18 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/02/06 18:00:17 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_access(char **env, char *cmd)
{
	char	**paths;
	char	*str;

	paths = ft_split(find_apath(env), ':');
	str = access_path(paths, cmd);
	if (str == NULL)
	{
		free(str);
		ft_free(paths);
		return (NULL);
	}
	ft_free(paths);
	return (str);
}

int    cmd_is(char **env, char **tokens)
{
    int        i;
    char    *buffer;

    i = -1;
    while (buffer == NULL && tokens[++i])
        buffer = check_access(env, tokens[i]);
    if (!buffer)
        return (-2);
    free(buffer);
    return (i);
}

char	**get_commands(t_shell *shell)
{
	char	**return_commands;
	int		cmd;
	int		tmp;

	cmd = cmd_is(shell->env, shell->tokens);
	if (cmd != 1)
		tmp = 1;
	else
		return (NULL);
	if (shell->tokens[cmd + 1] && shell->tokens[cmd + 1][0] == '-')
		tmp = 2;
	return_commands = malloc(sizeof(char *) * tmp);
	return_commands[0] = ft_strdup(shell->tokens[cmd]);
	if (tmp > 1)
		return_commands[1] = ft_strdup(shell->tokens[cmd  + 1]);
	return_commands[tmp] = NULL;
	return (return_commands);
}