/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:04:55 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 15:31:26 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_error_exit(char *message, int exit_number)
{
	ft_putstr_fd(message, STDERR_FILENO);
	exit(exit_number);
}
