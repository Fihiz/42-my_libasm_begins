/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astrid_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:37:47 by jgambard          #+#    #+#             */
/*   Updated: 2020/12/01 23:16:23 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);

int main()
{
	errno = 0;
	char	*s = "A23456789";
	printf("Test de ft_strlen:\n");
	printf("[Orig: %lu / Ours: %lu] String = '%s'\n", strlen(s), ft_strlen(s), s);
	s += 4;
	printf("[Orig: %lu / Ours: %lu] String = '%s'\n", strlen(s), ft_strlen(s), s);
	s += 5;
	printf("[Orig: %lu / Ours: %lu] String = '%s'\n", strlen(s), ft_strlen(s), s);

	printf("\nTest de ft_strcpy:\n");
	char	s_orig[100];
	char	s_ours[100];
	char	*ret;
	s = "A23456789";
	strcpy(s_orig, s);
	ret = ft_strcpy(s_ours, s);
	printf("[Orig: '%s' / Ours: '%s'] / [dest = %p return = %p]\n", s_orig, s_ours, s_ours, ret);
	s += 4;
	strcpy(s_orig, s);
	ret = ft_strcpy(s_ours, s);
	printf("[Orig: '%s' / Ours: '%s'] / [dest = %p return = %p]\n", s_orig, s_ours, s_ours, ret);
	s += 5;
	strcpy(s_orig, s);
	ret = ft_strcpy(s_ours, s);
	printf("[Orig: '%s' / Ours: '%s'] / [dest = %p return = %p]\n", s_orig, s_ours, s_ours, ret);

	printf("\nTest de ft_strcmp:\n");
	s = "A23456789";
	printf("[Orig: %i / Ours: %i] String = '%s'\n", strcmp(s, "A23456"), ft_strcmp(s, "A23456"), s);
	printf("[Orig: %i / Ours: %i] String = '%s'\n", strcmp(s, "A23458"), ft_strcmp(s, "A23458"), s);
	s = "123\18 2";
	printf("[Orig: %i / Ours: %i] String = '%s'\n", strcmp(s, "123\18 4"), ft_strcmp(s, "123\18 4"), s);
	printf("[Orig: %i / Ours: %i] String = '%s'\n", strcmp("123", "123"), ft_strcmp("123", "123"), s);
	printf("[Orig: %i / Ours: %i] String = '%s'\n", strcmp(s, "1"), ft_strcmp(s, "1"), s);

	int		ours;
	int		orig;
	char	*str = "salut";

	printf("\nTest de ft_write:\n");

	printf("Test avec : %s\n", str);
	dprintf(2, "Orig : ");
	orig = write(1, str, 5);
	printf("\nreturn : %i\n", orig);
	dprintf(2, "Ours : ");
	ours = ft_write(1, str, 5);
	printf("\nreturn : %i\n", ours);
	int		fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0600);
	ft_write(fd, "salut", 5);
	ft_write(fd, " ca va", 6);
	printf("Test de ft_write dans un fd:\n");
	system("cat test.txt");

	printf("\nTest d'errno dans ft_write (9):\n");
	ft_write(546456, "dff", 25);
	printf("errno = %i\n", errno);
	close(fd);

	fd = open("test.txt", O_RDWR | O_CREAT, 0600);
	char	orig_buffer[100];
	char	our_buffer[100];
	printf("\nTest de ft_read:\n");
	orig_buffer[read(fd, orig_buffer, 2)] = 0;
	printf("orig buffer : %s\n", orig_buffer);
	close(fd);
	fd = open("test.txt", O_RDWR | O_CREAT, 0600);
	our_buffer[ft_read(fd, our_buffer, 2)] = 0;
	printf("our buffer : %s\n", our_buffer);
	close(fd);

	errno = 0;
	printf("\nTest d'errno dans ft_read (9):\n");
	ft_read(546456, 0, 25);
	printf("errno = %i\n", errno);
	close(fd);


	printf("\nTest de ft_strdup:\n");
	str = "salutations";
	char	*orig_str = strdup(str);
	char	*ours_str = ft_strdup(str);
	printf("base : %p, origin : %p '%s', ours : %p '%s'\n", str, orig_str, orig_str, ours_str, ours_str);
	free(orig_str);
	free(ours_str);
	//system("leaks a.out");
	return (0);
}