/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:55:28 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/01/10 04:20:16 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

extern int	g_exit_code;

typedef struct s_shell
{
	char *line;
} t_shell;

void	handle_signal(int sig);
void	signal_handle_interactive(void);
void	signal_handle_non_interactive(void);

#endif