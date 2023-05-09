/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:31:17 by afontain          #+#    #+#             */
/*   Updated: 2023/05/09 14:34:09 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	(void)av;
	(void)env;
	int pid;
	
	if (ac <= 4)
		return (write(2, "Pas assez de parametres\n", 25));
	pid = fork();
	if (pid == 0)
	{
		sleep(10);
		printf("Je suis l'enfant\n");
	}
	else
	{
		printf("je suis le parent\n");
		wait(NULL);
	}
	printf("Hello World\n");
}

// ac = 7 :
// av[1] = file
// av[ac - 1] = file