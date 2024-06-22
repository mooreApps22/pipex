/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:08:32 by smoore            #+#    #+#             */
/*   Updated: 2024/06/22 15:25:48 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	wr_error(char *s)
{
	ft_putstr_fd(s, 2);
}

void	free_t_pipex(t_pipex *p)
{
	close(p->rd);
	close(p->wr);
	free_t_cmd(&p->c1);
	free_t_cmd(&p->c2);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	p;

	init_t_pipex(&p, ac, av, envp);
	if (pipe(p.pipe) < 0)
		wr_error(E_PIPE);
	p.pid1 = fork();
	if (p.pid1 == 0 && p.rd && p.rd != -1 && p.c1.cmd)
		first_child_process(p, envp);
	p.pid2 = fork();
	if (p.pid2 == 0 && p.wr && p.wr != -1 && p.c2.cmd)
		second_child_process(p, envp);
	close_pipe(&p);
	waitpid(p.pid1, NULL, 0);
	waitpid(p.pid2, NULL, 0);
	free_t_pipex(&p);
	return (0);
}
