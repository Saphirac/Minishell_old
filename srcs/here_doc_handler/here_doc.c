/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:32:38 by maparigi          #+#    #+#             */
/*   Updated: 2023/03/01 16:03:07 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	czeck_hd(const char *str)
{
	const char	hd[2] = "<<";

	else if (ft_strncmp(str, hd, 2) == 0)
		return (1);
	return (0);
}

void	find_hd(char *arg_l)
{
	
}

char	*stock_hd(t_shell *shell, char *stop_signal)
{	
	shell->l_hd = readline("> ");
	if (!shell->l_hd)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		exit(EXIT_FAILURE);
	}
	while (shell->l_hd && ft_strncmp(shell->l_hd, stop_signal, ft_strlen(stop_signal)))
	{
		signal_handle_heredoc();
		shell->stock_hd = stock_hd(shell);
		free(shell->l_hd);
		shell->l_hd = readline("> ");
	}
	return (shell->stock_hd);
}

/*******************************************/

int	main(int ac, char **av)
{
	(void)ac;
	find_hd(av[1]);
}

/*******************************************/
