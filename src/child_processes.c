/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:08:32 by smoore            #+#    #+#             */
/*   Updated: 2024/06/22 15:19:23 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	first_child_process(t_pipex p, char **envp)
{
	if (!p.c1.cmd || !p.rd)
		return ;
	dup2(p.pipe[1], 1);
	close(p.pipe[0]);
	dup2(p.rd, 0);
	execve(p.c1.cmd, p.c1.args, envp);
}

void	second_child_process(t_pipex p, char **envp)
{
	if (!p.c2.cmd || !p.wr)
		return ;
	dup2(p.pipe[0], 0);
	close(p.pipe[1]);
	dup2(p.wr, 1);
	execve(p.c2.cmd, p.c2.args, envp);
}
