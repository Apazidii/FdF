/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:16:58 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/08 20:16:58 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

void	exit_errno(void)
{
	perror(strerror(errno));
	exit(0);
}
