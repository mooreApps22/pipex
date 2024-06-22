/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:08:32 by smoore            #+#    #+#             */
/*   Updated: 2024/06/22 15:39:02 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_pipe(t_pipex *p)
{
	close(p->pipe[0]);
	close(p->pipe[1]);
}

void	free_t_cmd(t_cmd *c)
{
	int	i;

	i = 0;
	while (c->list[i])
		free(c->list[i++]);
	free(c->list);
	i = 0;
	while (c->args[i])
		free(c->args[i++]);
	free(c->args);
	free(c->cmd);
	c = NULL;
}
