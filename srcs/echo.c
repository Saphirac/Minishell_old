/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: red <red@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:03:09 by red               #+#    #+#             */
/*   Updated: 2023/02/25 17:30:13 by red              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_echo(char *str, char *bsn)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	if (!(ft_strlen(bsn) == 2 && ft_strncmp(bsn, "-n", 2) == 0))
		ft_putchar_fd('\n', STDOUT_FILENO);
}
