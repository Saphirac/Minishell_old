/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:55:28 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/02/28 04:50:29 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <libft.h>

extern int	g_exit_code;

typedef struct s_shell
{
	char	*line;
	char	**tokens;
	char	**env;
	char	*l_hd;
	char	**tk_hd;
}	t_shell;

void	handle_signal(int sig);
void	signal_handle_interactive(void);
void	signal_handle_non_interactive(void);
int		count_tokens(char *str);
int		count_quotes(char *str, int i);
char	**tokens_tab(t_shell *shell, int i);
char	**get_commands(t_shell *shell);
char	*expand_single_quotes(char *token);
char	*expand_double_quotes(t_shell *shell, char *token);
char	*search_env(char **env, char *token);
char	*expand_dollar(char *token, char *tmp);

// Utils //
void	ft_free(char **tab);
char	*access_path(char **paths, char *cmd);
char	*add_path(char *str, char *av1, char c);
char	*find_apath(char **env);

// Heredoc
char	**tokens_tab_hd(t_shell *shell, int i)

#endif