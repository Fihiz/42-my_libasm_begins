/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lou_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 17:24:39 by lolopez           #+#    #+#             */
/*   Updated: 2020/12/02 20:58:29 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}

static void test_strlen(void)
{
	red();
	printf("TESTS STRLEN\n");
	yellow();
	printf("|%s|\n", "");
	reset();
	printf("[ft_strlen] : %zu\n" , ft_strlen(""));
	printf("[strlen]: %lu\n\n", strlen(""));
	yellow();
	printf("|%s|\n","salut les zouz !! 123456 :)");
	reset();
	printf("[ft_strlen] : %zu\n",ft_strlen("salut les zouz !! 123456 :)"));
	printf("[strlen]: %lu\n\n", strlen("salut les zouz !! 123456 :)"));
}

static void test_strcpy(void)
{
	char	dst[100];
	red();
	printf("TESTS STRCPY\n\n");
	reset();
	yellow();
	printf("|%s|\n", "");
	reset();
	printf("dst ft_strcpy: [%s]\n", ft_strcpy(dst, ""));
	printf("dst strcpy: [%s]\n\n", strcpy(dst, ""));
	yellow();
	printf("|%s|\n", "Coucouc les zouz 12389978!!!");
	reset();
	printf("dst ft_strcpy: [%s]\n", ft_strcpy(dst, "Coucouc les zouz 12389978!!!"));
	printf("dst strcpy: [%s]\n\n", strcpy(dst, "Coucouc les zouz 12389978!!!"));
}


static void test_strcmp(void)
{
	red();
	printf("TESTS STRCMP\n\n");
	yellow();
	printf("s1 = |%s| && s2 = |%s|\n", "", "");
	reset();
	printf("ft_strcmp: [%d]\n", ft_strcmp("", ""));
	printf("strcmp: [%d]\n\n", strcmp("", ""));
	yellow();
	printf("s1 = |%s| && s2 = |%s|\n","Coucou les moches" ,"Coucouc les zouz 12389978!!!");
	reset();
	printf("ft_strcmp: [%d]\n", ft_strcmp("Coucou les moches", "Coucouc les zouz 12389978!!!"));
	printf("strcmp: [%d]\n\n", strcmp("Coucou les moches", "Coucouc les zouz 12389978!!!"));
	yellow();
	printf("s1 = |%s| && s2 = |%s|\n", "wesh", "wesh");
	reset();
	printf("ft_strcmp: [%d]\n", ft_strcmp("wesh", "wesh"));
	printf("strcmp: [%d]\n\n", strcmp("wesh", "wesh"));
		yellow();
	printf("s1 = |%s| && s2 = |%s|\n", "wesh 119", "");
	reset();
	printf("ft_strcmp: [%d]\n", ft_strcmp("wesh 119", ""));
	printf("strcmp: [%d]\n\n", strcmp("wesh 119", ""));
}

static void test_write(void)
{
	int file_mine;
	int file_real;
	int	nb = 0;
	int	fakefd;
	char string[101];
	int retr;
	int retm;

	errno = 0;
	file_mine = open("./files/write/ft_writetest.txt", O_RDWR | O_CREAT | O_APPEND);
	file_real = open("./files/write/writetest.txt", O_RDWR | O_CREAT | O_APPEND);
	fakefd = open("./files/write/pouet", O_RDONLY | O_CREAT);

	red();
	printf("TEST WRITE\n");
	printf("write on a file : my write file './files/write/ft_writetest.txt', true write file './files/write/writetest.txt'\n");
	reset();


	printf("try with your own string (100 Char max)\nput your string here :");
	fgets(string, 100, stdin);
	printf("how many char do you want to write ?\nput your nb here :");
	scanf("%d", &nb);


	yellow();
	printf("\nwriting on a read only  file\n");
	reset();
	retr = write(fakefd, string, nb);
	printf("write : err n°%d\n",errno);
   errno = 0;	
	retm = ft_write(fakefd, string, nb);
		printf("ft_write : err n°%d\n",errno);
	errno = 0;
	printf("ret value of write = %d\nret value of ft_write = %d\n\n", retr, retm);


	yellow();
	printf("writing on the file\n");
	reset();
	retr = write(file_real, string, nb);
	if (errno != 0)
		printf("write : err n°%d\n",errno);
	errno = 0;
	retm = ft_write(file_mine, string, nb);
	if (errno != 0)
		printf("ft_write : err n°%d\n",errno);
	errno = 0;
	printf("ret value of write = %d\nret value of ft_write = %d\n\n", retr, retm);

	yellow();
	printf("writing on stdout\n");
	reset();
	printf("\ntest write :\n");
	retr = write(1, string, nb);
	if (errno != 0)
		printf("write : err n°%d\n",errno);
	errno = 0;
	printf("\nretour = %d\n", retr);
	printf("\ntest ft_write :\n");
	retm = ft_write(1, string, nb);
	if (errno != 0)
		printf("ft_write : err n°%d\n",errno);
	errno = 0;
	printf("\nretour = %d\n", retm);
	close(file_mine);
	close(file_real);
	close(fakefd);
}

static void	test_read(void)
{
	char	ft_readbuff[1001];
	char	readbuff[1001];
	int		nb = 1000;
	int		onlywr;
	int		bouquin;
	int		retr;
	int		retm;

	bouquin = open("files/read/livre.txt", O_RDWR);
	onlywr = open("files/read/coucou", O_WRONLY | O_CREAT);
	errno = 0;

	red();
	printf("TEST READ\n\n");
	printf("You can't read more than 1000 char\n");

	memset(readbuff,0, 1001);
	memset(ft_readbuff,0, 1001);
	yellow();
	printf("\n\nReading from stdin\n");
	red();
	printf("read:\n");
	reset();
	retr = read(0, readbuff, nb);
	if (errno != 0)
		printf("ERROR (errno = %d)\n", errno);
	printf("[%s]\nret = %d\n",readbuff, retr);
	errno = 0;
	red();
	printf("ft_read:\n");
	reset();
	retm = ft_read(0, ft_readbuff, nb);
	if (errno != 0)
		printf("ERROR (errno = %d)\n", errno);
	printf("[%s]\nret = %d\n",ft_readbuff, retm);
	errno = 0;

	memset(readbuff,0, 1001);
	memset(ft_readbuff,0, 1001);
	yellow();
	printf("\n\ntest from 'files/read/livre.txt'\n");
	red();
	printf("read:\n");
	reset();
	retr = read(bouquin, readbuff, nb);
	if (errno != 0)
		printf("ERROR (errno = %d)\n", errno);
	printf("[%s]\nret = %d\n",readbuff, retr);
	errno = 0;
	red();
	printf("ft_read:\n");
	reset();
	retm = ft_read(bouquin, ft_readbuff, nb);
	if (errno != 0)
		printf("ERROR (errno = %d)\n", errno);
	printf("[%s]\nret = %d\n",ft_readbuff, retm);
	errno = 0;

	memset(readbuff,0, 1001);
	memset(ft_readbuff,0, 1001);
	yellow();
	printf("\n\ntest with a O_WRONLY file\n");
	red();
	printf("read:\n");
	reset();
	printf("\n");
	retr = read(onlywr, readbuff, nb);
	if (errno != 0)
		printf("ERROR (errno = %d)\n", errno);
	printf("[%s]\nret = %d\n",readbuff, retr);
	errno = 0;
	red();
	printf("ft_read:\n");
	printf("\n");
	reset();
	retm = ft_read(onlywr, ft_readbuff, nb);
	if (errno != 0)
		printf("ERROR (errno = %d)\n", errno);
	printf("[%s]\nret = %d\n",ft_readbuff, retm);
	errno = 0;

	memset(readbuff,0, 1001);
	memset(ft_readbuff,0, 1001);
	yellow();
	printf("\n\ntest with count < 0\n");
	red();
	printf("read:\n");
	reset();
	retr = read(bouquin, readbuff, -3);
	if (errno != 0)
		printf("ERROR (errno = %d)\n", errno);
	printf("[%s]\nret = %d\n",readbuff, retr);
	errno = 0;
	red();
	printf("ft_read:\n");
	reset();
	retm = ft_read(bouquin, ft_readbuff, -3);
	if (errno != 0)
		printf("ERROR (errno = %d)\n", errno);
	printf("[%s]\nret = %d\n",ft_readbuff, retm);
	errno = 0;

}

static void	test_strdup(void)
{
	char	*vraie;
	char	*mienne;
	red();
	printf("TESTS STRDUP\n\n");
	reset();

	yellow();
	printf("|%s|\n", "On va manger du poulay");
	reset();
	mienne = ft_strdup("On va manger du poulay");
	vraie = strdup("On va manger du poulay");
	printf("chaine de ft_strdup: [%s]\n", mienne);
	printf("chaine de strdup: [%s]\n\n", vraie);
	printf("freeing strdup pointer\n");
	free(vraie);
	vraie = NULL;
	printf("freeing ft_strdup pointer\n\n");
	free(mienne);
	mienne = NULL;

	yellow();
	printf("|%s|\n", "");
	reset();
	mienne = ft_strdup("");
	vraie = strdup("");
	printf("chaine de ft_strdup: [%s]\n", mienne);
	printf("chaine de strdup: [%s]\n\n", vraie);
	printf("freeing strdup pointer\n");
	free(vraie);
	vraie = NULL;
	printf("freeing ft_strdup pointer\n\n");
	free(mienne);
	mienne = NULL;
}

// static void		test_atoi_base(void)
// {
// 	red();
// 	printf("TEST ATOI_BASE\n");

// 	yellow();
// 	printf("testing simple binary '11111111' = 255\n");
// 	reset();
// 	printf("%d\n", ft_atoi_base("11111111", "01"));

// 	yellow();
// 	printf("testing the number of the beast in hexa '      ---+-29A'\n");
// 	reset();
// 	printf("%d\n", ft_atoi_base("      ---+-29A", "0123456789ABCDEF"));

// 	yellow();
// 	printf("testing -541000 on my PONEY base '  -----+OOYEPEPPPokmabichette'\n");
// 	reset();
// 	printf("%d\n", ft_atoi_base("  -----+OOYEPEPPPokmabichette", "PONEY"));

// 	yellow();
// 	printf("Error testing base with only one char\n");
// 	reset();
// 	printf("%d\n", ft_atoi_base("bof", "o"));

// 	yellow();
// 	printf("Error testing base with whitespace\n");
// 	reset();
// 	printf("%d\n", ft_atoi_base("bof", "o\n"));
	
// 	yellow();
// 	printf("Error testing base with 2 same char\n");
// 	reset();
// 	printf("%d\n", ft_atoi_base("bof", "bbof"));
// }

int		main(int ac, char **av)
{
	if (ac != 2)
	{
	printf("Execute test with arguments :\n\
		./test strlen\n\
		./test strcpy\n\
		./test strcmp\n\
		./test write\n\
		./test read\n\
		./test strdup\n\
		./test atoi_base\n\
to test the different functions\n");
		return (0);
	}

	if (strncmp(av[1], "strlen\0", 7) == 0)
		test_strlen();
	else if (strncmp(av[1], "strcpy\0", 7) == 0)
		test_strcpy();
	else if (strncmp(av[1], "strcmp\0", 7) == 0)
		test_strcmp();
	else if (strncmp(av[1], "write\0", 6) == 0)
		test_write();
	else if (strncmp(av[1], "read\0", 5) == 0)
		test_read();
	else if (strncmp(av[1], "strdup\0", 7) == 0)
		test_strdup();
	// else if (strncmp(av[1], "atoi_base\0", 10) == 0)
	// 	test_atoi_base();
	return (1);
}