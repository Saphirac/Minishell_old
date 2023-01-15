/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:35:35 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/01/12 18:20:23 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_tokens(char *str)
{
	int i;
	int nb_tokens; 

	i = 0;
	nb_tokens = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break;
		while (str[i] && str[i] != ' ' && str[i] != '"' && str[i] != 39)
			i++;
		if (str[i] == ' ' || str[i] == '\0')
		{
			printf("yo\n");
			nb_tokens++;
		}
		if (str[i] == '"')
		{
			i++;
			if (str[i] == '"')
				nb_tokens++;
			while (str[i] && str[i] != '"')
			{
				i++;
				if (str[i] == '"')
				{
					printf("here\n");
					nb_tokens++;
					//break;
				}
			}
		}
		i++;
	}
	return (nb_tokens);
}