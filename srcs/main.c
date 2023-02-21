/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:48:12 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/02/21 02:31:41 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

int	g_exit_code = 0;

void	test_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		printf("token %d : %s\n", i, str[i]);
		i++;
	}
}

char	**mini_env(void)
{
    char	**env;

	env = malloc(sizeof(char *) * 4);
	env[0] = ft_strdup("PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
	env[1] = ft_strdup("PWD=/Users/minishell");
	env[2] = ft_strdup("_=/usr/bin/env");
	env[3] = NULL;
	return (env);
}

void	prompt(t_shell *shell)
{
	char	**cmd;

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
	cmd = get_commands(shell);
	test_tab(cmd);
	ft_free(shell->tokens);
	free(shell->line);
	free(cmd);
}

int	main(int ac, char **av, char **env)
{
	t_shell	shell;

	(void)ac;
	(void)av;
	shell.env = env;
	printf("env[0] : %s\n", env[0]);
	while (1)
	{
		signal_handle_interactive();
		prompt(&shell);
	}
	return (0);
}
