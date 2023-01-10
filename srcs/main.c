/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:48:12 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/01/10 05:33:55 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

int	g_exit_code = 0;

void prompt(t_shell *shell)
{
	shell->line = readline("minishell $> ");
	if (!shell->line)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		exit (EXIT_FAILURE);
	}
	if (ft_strlen(shell->line))
		add_history(shell->line);
	free(shell->line);
}

int	main(void)
{
	t_shell	shell;
	
	while (1)
	{
		signal_handle_interactive();
		prompt(&shell);
	}
	return (0);
}