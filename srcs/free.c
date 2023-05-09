/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:46:14 by afontain          #+#    #+#             */
/*   Updated: 2023/05/09 15:48:50 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_free(void *adrr)
{
	free(adrr);
	adrr = NULL;	
}

void free_tab(char **tab)
{
	int	i;
	
	i = 0;
	while (tab)
	{
		free(tab[i]);
		i++;
	}
	ft_free(tab);
}