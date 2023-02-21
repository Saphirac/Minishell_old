/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:11:30 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/02/21 02:31:07 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_single_quotes(char *token)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * (ft_strlen(token) - 2 + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (token[++i])
		ret[i - 1] = token[i];
	ret[i - 1] = '\0';
	return (ret);
}

char	*expand_double_quotes(t_shell *shell, char *token)
{
	char	*ret;
	int		i;
	char	*tmp;

	i = 1;
	while (token[i] && token[i] != '$')
		i++;
	if (token[i] == '$')
	{
		tmp = search_env(shell->env, token, i);
		if (!tmp)
			return (NULL);
		ret = expand_dollar(shell->env, token, tmp, i);
		if (!ret)
			return (NULL);
		return (ret);
	}
	return (NULL);
}

int	compare_env_token(char *env, char *token)
{
	int	i;

	i = 0;
	while (env[i] && token[i] && env[i] != '=')
	{
		if (env[i] != token[i])
			return (-1);
		if (env[i] == '=' && token[i] == '\0')
			return (i);
		i++;
	}
	return (-2);
}

char	*search_env(char **env, char *token)
{
	int		i;
	int		tmp;
	char	*ret;

	i = -1;
	tmp = -1;
	while (env[++i] && tmp < 0)
		tmp = compare_env_token(env[i], token + 1);
	if (env[i] && tmp > 0)
	{
		ret = ft_strdup(env[i] + tmp);
		if (!ret)
			return (NULL);
		return (ret);
	}
	return (NULL);
}
