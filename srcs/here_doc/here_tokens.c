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

char	*stock_hd(t_shell *shell)
{
	if (!shell->stock_hd && shell->line)
		shell->stock_hd = ft_strdup(shell->line);
	if (shell->stock_hd && shell->line)
		shell->stock_hd = ft_strjoin(shell->stock_hd, shell->line);
	return (shell->stock_hd);
}

