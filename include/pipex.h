/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:08:32 by smoore            #+#    #+#             */
/*   Updated: 2024/06/22 15:36:40 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <errno.h>
# include <sys/wait.h>

# define E_AC "Must have four arguments\n"
# define E_IN "No such file or directory\n"
# define E_CMD "command not found\n"
# define E_PIPE "Error with pipe\n"
# define E_PATH "No such pathway in enviorment variables\n"
# define E_LIST "Error while splitting enviorment variables\n"

typedef struct s_cmd
{
	char	*paths;
	char	**list;
	char	**args;
	char	*cmd;
}			t_cmd;

typedef struct s_pipex
{
	int				rd;	
	int				wr;	
	struct s_cmd	c1;
	struct s_cmd	c2;
	int				pipe[2];
	pid_t			pid1;
	pid_t			pid2;
}			t_pipex;

// main
void	wr_error(char *s);

// init t_pipex 
void	validate_args(t_pipex *p, char **av);
void	init_t_pipex(t_pipex *p, int ac, char **av, char **envp);

// init t_cmd
char	*path_finder(char **envp);
char	*load_cmd(char **list, char *cmd);
char	*init_t_cmd(t_cmd *c, char *av, char **envp);

// child processes
void	first_child_process(t_pipex p, char **envp);
void	second_child_process(t_pipex p, char **envp);

// free, close pipe
void	close_pipe(t_pipex *p);
void	free_t_cmd(t_cmd *c);

#endif
