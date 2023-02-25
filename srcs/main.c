/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: red <red@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:48:12 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/02/25 17:54:40 by red              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

int	g_exit_code = 0;

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	test_tab(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->tokens[i])
	{
		printf("token %d : %s\n", i, shell->tokens[i]);
		i++;
	}
}

void	prompt(t_shell *shell)
{
	shell->finished = 0;
	shell->line = readline("minishell $> ");
	if (!shell->line)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(shell->line))
		add_history(shell->line);
	if (count_tokens(shell->line) > 0)
		shell->tokens = tokens_tab(shell, 0);
	test_tab(shell);
	free_tab(shell->tokens);
	free(shell->line);
}

int	main(int ac, char **av, char **env)
{
	t_shell	shell;
	char	**new_env;

	(void)ac;
	(void)av;
	(void)env;
	(void)shell;
	(void)new_env;
	my_pwd();
	//while (1)
	//{
	//	signal_handle_interactive();
	//	prompt(&shell);
	//}
	return (0);
}
