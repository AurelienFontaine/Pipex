/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:32:24 by afontain          #+#    #+#             */
/*   Updated: 2023/05/09 15:41:13 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
  
# include "../GNL/get_next_line.h"

typedef enum e_fd
{
	DEFAULT = -1,
	IN,
	OUT,
	MAX_FD,
	HEREDOC,
}t_fd;

typedef struct s_lst
{
	char	*cmd;
	char	**command;
	void	*next;
}	t_lst;

typedef struct s_data
{
	int		ac;
	char	**av;
	char	**env;
}	t_data;

typedef struct s_file
{
	char	*file1;
	char	*file2;
}	t_file;

typedef struct s_pipex
{
	int			infile;
	int			outfile;
	int			cmds;
	int			fds[2];
	char		**paths;
	pid_t		child[2];
	t_file		file;
	t_lst		*lst;
	t_data		data;
}	t_pipex;

//Main
int		main(int ac, char **av, char **env);

//utils
char	*ft_strdup(char *src);
int		ft_strncmp(char *s1, char *s2, size_t n);
size_t	ft_strlcpy(char *dest, char *src, size_t size);

//Split
char	**ft_split(char *s, char c);

#endif