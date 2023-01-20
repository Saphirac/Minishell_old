/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:35:35 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/01/20 17:09:23 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_double_quotes(char *str, int i)
{
	int	len_token;

	len_token = 0;
	if (str[i] == '"')
	{
		len_token++;
		i++;
		if (str[i] == '"')
			return (len_token + 1);
		while (str[i] && str[i] != '"')
		{
			len_token++;
			i++;
			if (str[i] == '"')
				return (len_token + 1);
			if (str[i] == '\0')
				return (1);
		}
	}
	return (len_token);
}

int	count_single_quotes(char *str, int i)
{
	int	len_token;

	len_token = 0;
	if (str[i] == 39)
	{
		i++;
		len_token++;
		if (str[i] == 39)
			return (len_token + 1);
		while (str[i] && str[i] != 39)
		{
			len_token++;
			i++;
			if (str[i] == 39)
				return (len_token + 1);
			if (str[i] == '\0')
				return (1);
		}
	}
	return (len_token);
}

int	count_tokens(char *str)
{
	int	i;
	int	nb_tokens;

	i = -1;
	nb_tokens = 0;
	while (str[++i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '\0')
		{
			if (str[i - 1] != ' ')
			{
				printf("here 1\n");
				nb_tokens++;
			}
			break;
		}
		while (str[i] && str[i] != ' ' && str[i] != '"' && str[i] != 39)
			i++;
		if (str[i] == ' ' || str[i] == '\0')
		{
			printf("here 2\n");
			nb_tokens++;
		}
		if (count_double_quotes(str, i) > 0)
		{
			printf("here 3\n");
			nb_tokens++;
		}
		i += count_double_quotes(str, i);
		if (count_single_quotes(str, i) > 0)
		{
			printf("here 4\n");
			nb_tokens++;
		}
		i += count_single_quotes(str, i);
	}
	return (nb_tokens);
}
