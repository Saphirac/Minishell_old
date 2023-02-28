/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_tk_hd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 05:28:05 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/02/28 04:46:48 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**tokens_tab_hd(t_shell *shell, int i)
{
	int		j;
	int		k;

	k = 0;
	shell->tk_hd = malloc(sizeof(char *) * 1);
	if (!shell->tk_hd)
		return (NULL);
	while (shell->l_hd[i])
	{
		while (shell->l_hd[i] && shell->l_hd[i] == ' ')
			i++;
		if (!shell->l_hd[i])
			return (shell->tk_hd);
		j = i;
		while (shell->l_hd[j] != ' ' && shell->l_hd[j] != '"'
			&& shell->l_hd[j] != '\'' && shell->l_hd[j])
			j++;
		k = sub_tokens_hd(shell, i, j, k);
		if (k < 0)
			return (NULL);
		i = (j + count_quotes(shell->l_hd, j));
	}
	shell->tk_hd[count_tokens(shell->l_hd)] = NULL;
	return (shell->tk_hd);
}
