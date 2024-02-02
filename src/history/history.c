/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:21:51 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/02 12:46:01 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    history(char *s)
{
    char    **arr;

    int i;
    arr = ft_split(s, ' ');
    if (arr == NULL)
        return ;
    add_history(s);
    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}