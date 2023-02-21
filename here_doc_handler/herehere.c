/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herehere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:32:38 by maparigi          #+#    #+#             */
/*   Updated: 2023/02/22 00:38:51 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	czeck_hd(const char *str)
{
	const char	hdt[3] = "<<-";
	const char	hd[2] = "<<";

	if (ft_strncmp(str, hdt, 3) == 0)
		return (2);
	else if (ft_strncmp(str, hd, 2) == 0)
		return (1);
	return (0);
}

void	find_hd(char *arg_l)
{
	int	i;

	i = -1;
	while (arg_l[++i])
	{
		if (czeck_hd(arg_l + i) == 2)
			printf("heredoct : %s\n", arg_l + i);
		else if (czeck_hd(arg_l + i) == 1)
			printf("heredoc : %s\n", arg_l + i);
	}
	return ;
}

/*******************************************/

int	main(int ac, char **av)
{
	(void)ac;
	find_hd(av[1]);
}

/*******************************************/
