/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:22:16 by sad-aude          #+#    #+#             */
/*   Updated: 2020/11/18 22:17:18 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <string.h>
#include <stdio.h>
#include <errno.h>

#define CORRECT "\033[34m[CORRECT]\033[0m"
#define WRONG   "\033[31m[WRONG]\033[0m"

size_t      ft_strlen(const char *s);

#endif