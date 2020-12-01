/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:22:16 by sad-aude          #+#    #+#             */
/*   Updated: 2020/11/27 18:19:16 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>

#define CORRECT "\033[34m[CORRECT]\033[0m"
#define WRONG   "\033[31m[WRONG]\033[0m"

size_t      ft_strlen(const char *s);
char        *ft_strcpy(char *dest, const char *src);
int         ft_strcmp(const char *s1, const char *s2);
ssize_t     ft_write(int fd, const void *buf, size_t count);
ssize_t     ft_read(int fd, void *buf, size_t count);
char        *ft_strdup(const char *s);

#endif