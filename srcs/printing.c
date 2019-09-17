/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:56:48 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/26 13:56:50 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_final(t_piece *p)
{
	ft_putnbr_fd(p->fin_pos[0], 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(p->fin_pos[1], 1);
	ft_putchar_fd('\n', 1);
}

void	ft_print_end(void)
{
	ft_putnbr_fd(0, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
}
