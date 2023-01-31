/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 05:28:05 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/01/31 20:00:57 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*cp_token(char *tokens, char *str, int i, int j)
{
	int	k;

	k = 0;
	tokens = malloc(sizeof(char) * (j - i) + 1);
	if (!tokens)
		return (-1);
	while (i < j)
	{
		tokens[k] = str[i];
		k++;
		j++;
	}
	tokens[k + 1] = '\0';
}

int	sub_tokens(t_shell *shell, int i, int j, int k)
{
	if (!shell->line[j])
	{
		if (cp_token(shell->tokens[k], shell->line, i, j) == -1)
			return (-1);
		k++;make 
		return (0);
	}
	if (shell->line[j] == ' ')
	{
		if (cp_token(shell->tokens[k], shell->line, i, j) == -1)
			return (-1);
		k++;
	}
	if (count_quotes(shell->line, j) > 0)
	{
		j = count_quotes(shell->line, j);
		if (cp_token(shell->tokens[k], shell->line, i, j) == -1)
			return (-1);
		k++;
	}
	return (0);
}

char	**tokens_tab(t_shell *shell)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (count_tokens(shell->line) == 0)
		return (NULL);
	shell->tokens = malloc(sizeof(char *) * count_tokens(shell->line) + 1);
	if (!shell->tokens)
		return (NULL);
	while (shell->line[i])
	{
		while (shell->line[i] && shell->line[i] == ' ')
			i++;
		if (!shell->line[i])
			return (shell->tokens);
		j = i;
		while (shell->line[j] != ' ' && shell->line[j] != '"'
			&& shell->line[j] != '\'' && shell->line[j])
			j++;
		if (sub_tokens(shell->tokens, i, j, k) != 0)
			return (NULL);
		i += j;
	}
	return (shell->tokens);
}
