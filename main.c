/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:22:27 by sad-aude          #+#    #+#             */
/*   Updated: 2020/11/27 17:24:10 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

int     testing_ft_strlen()
{
    int     test_counter = 0;
    char    *zero = "";
    char    *one = "1";
    char    *two = "de";
    char    *three = "lol";
    char    *four = "1un1";
    char    *five = "under";
    char    *six = "     ?";
    char    *freeze = "J’suis giga, t’es nano, ils peuvent pas m’voir comme si j’ai l’anneau";
    char    *long_one = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    printf("\033[1mLet's testing ft_strlen !\n\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTested string %d : [%s]\n\033[0m", test_counter, zero);
    printf("The valid function gives : [%lu]\n", strlen(zero));
    printf("The wrong function gives : [%zu]\n", ft_strlen(zero));
	printf("It means the test is : %s\n", ((strlen(zero) == ft_strlen(zero)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    printf("\033[1mTested string %d : [%s]\n\033[0m", ++test_counter, one);
    printf("The valid function gives : [%lu]\n", strlen(one));
    printf("The wrong function gives : [%zu]\n", ft_strlen(one));
	printf("It means the test is : %s\n", ((strlen(one) == ft_strlen(one)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    printf("\033[1mTested string %d : [%s]\n\033[0m", ++test_counter, two);
    printf("The valid function gives : [%lu]\n", strlen(two));
    printf("The wrong function gives : [%zu]\n", ft_strlen(two));
	printf("It means the test is : %s\n", ((strlen(two) == ft_strlen(two)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    printf("\033[1mTested string %d : [%s]\n\033[0m", ++test_counter, three);
    printf("The valid function gives : [%lu]\n", strlen(three));
    printf("The wrong function gives : [%zu]\n", ft_strlen(three));
	printf("It means the test is : %s\n", ((strlen(three) == ft_strlen(three)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    printf("\033[1mTested string %d : [%s]\n\033[0m", ++test_counter, four);
    printf("The valid function gives : [%lu]\n", strlen(four));
    printf("The wrong function gives : [%zu]\n", ft_strlen(four));
	printf("It means the test is : %s\n", ((strlen(four) == ft_strlen(four)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    printf("\033[1mTested string %d : [%s]\n\033[0m", ++test_counter, five);
    printf("The valid function gives : [%lu]\n", strlen(five));
    printf("The wrong function gives : [%zu]\n", ft_strlen(five));
	printf("It means the test is : %s\n", ((strlen(five) == ft_strlen(five)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    printf("\033[1mTested string %d : [%s]\n\033[0m", ++test_counter, six);
    printf("The valid function gives : [%lu]\n", strlen(six));
    printf("The wrong function gives : [%zu]\n", ft_strlen(six));
	printf("It means the test is : %s\n", ((strlen(six) == ft_strlen(six)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    printf("\033[1mTested string %d : [%s]\n\033[0m", ++test_counter, freeze);
    printf("The valid function gives : [%lu]\n", strlen(freeze));
    printf("The wrong function gives : [%zu]\n", ft_strlen(freeze));
	printf("It means the test is : %s\n", ((strlen(freeze) == ft_strlen(freeze)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    printf("\033[1mTested string %d : [%s]\n\033[0m", ++test_counter, long_one);
    printf("The valid function gives : [%lu]\n", strlen(long_one));
    printf("The wrong function gives : [%zu]\n", ft_strlen(long_one));
	printf("It means the test is : %s\n", ((strlen(long_one) == ft_strlen(long_one)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    return (1);
}

int     testing_ft_strcpy()
{
    int     test_counter = 0;
    char    *zero = "";
    char    *freeze = "J’suis giga, t’es nano, ils peuvent pas m’voir comme si j’ai l’anneau";
    char    *long_one = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    char    destzero[10];
    char    destfreeze[79];
    char    destlong_one[445];
    printf("\033[1mLet's testing ft_strcpy !\n\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTested string %d : [%s]\n\033[0m", test_counter, zero);
    printf("The valid function gives : [%s]\n", strcpy(destzero, zero));
    printf("The wrong function gives : [%s]\n", ft_strcpy(destzero, zero));
    printf("-------------------------\n");
	printf("It means the (strcmp on strcpy and ft_strcpy)test is : %s\n", ((!strcmp(strcpy(destzero, zero), ft_strcpy(destzero, zero))) ? CORRECT : WRONG));
    printf("It means the (strcmp on ft_strcpy and source)test is : %s\n", ((!strcmp(ft_strcpy(destzero, zero), zero)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    printf("\033[1mTested string %d : [%s]\n\033[0m", test_counter, freeze);
    printf("The valid function gives : [%s]\n", strcpy(destfreeze, freeze));
    printf("The wrong function gives : [%s]\n", ft_strcpy(destfreeze, freeze));
    printf("-------------------------\n");
	printf("It means the (strcmp on strcpy and ft_strcpy)test is : %s\n", ((!strcmp(strcpy(destfreeze, freeze), ft_strcpy(destfreeze, freeze))) ? CORRECT : WRONG));
    printf("It means the (strcmp on ft_strcpy and source)test is : %s\n", ((!strcmp(ft_strcpy(destfreeze, freeze), freeze)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    printf("\033[1mTested string %d : [%s]\n\033[0m", test_counter, long_one);
    printf("The valid function gives : [%s]\n", strcpy(destlong_one, long_one));
    printf("The wrong function gives : [%s]\n", ft_strcpy(destlong_one, long_one));
    printf("-------------------------\n");
	printf("It means the (strcmp on strcpy and ft_strcpy)test is : %s\n", ((!strcmp(strcpy(destlong_one, long_one), ft_strcpy(destlong_one, long_one))) ? CORRECT : WRONG));
    printf("It means the (strcmp on ft_strcpy and source)test is : %s\n", ((!strcmp(ft_strcpy(destlong_one, long_one), long_one)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    return (1);
}

int     testing_ft_strcmp()
{
    int     test_counter;

    test_counter = 0;
    printf("\033[1mLet's testing ft_strcmp !\n\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d : s1 is [%s], s2 is [%s]\n\033[0m", test_counter, "", "");
    printf("The valid function gives : [%d]\n", strcmp("", ""));
    printf("The wrong function gives : [%d]\n", ft_strcmp("", ""));
	printf("It means the test is : %s\n", ((strcmp("", "") == ft_strcmp("", "")) ? CORRECT : WRONG));
    printf("-------------------------\n");
    printf("\033[1mTest %d : s1 is [%s], s2 is [%s]\n\033[0m", test_counter, "Colors", "");
    printf("The valid function gives : [%d]\n", strcmp("Colors", ""));
    printf("The wrong function gives : [%d]\n", ft_strcmp("Colors", ""));
	printf("It means the test is : %s\n", ((strcmp("Colors", "") == ft_strcmp("Colors", "")) ? CORRECT : WRONG));
    printf("-------------------------\n");
    printf("\033[1mTest %d : s1 is [%s], s2 is [%s]\n\033[0m", test_counter,"salome", "salomesalome");
    printf("The valid function gives : [%d]\n", strcmp("salome", "salomesalome"));
    printf("The wrong function gives : [%d]\n", ft_strcmp("salome", "salomesalome"));
	printf("It means the test is : %s\n", ((strcmp("salome", "salomesalome") == ft_strcmp("salome", "salomesalome")) ? CORRECT : WRONG));
	printf("-------------------------\n");
    printf("\033[1mTest %d : s1 is [%s], s2 is [%s]\n\033[0m", test_counter, "hello world!", "hello world!");
    printf("The valid function gives : [%d]\n", strcmp("hello world!", "hello world!"));
    printf("The wrong function gives : [%d]\n", ft_strcmp("hello world!", "hello world!"));
    printf("%s\n", ((strcmp("hello world!", "hello world!") == ft_strcmp("hello world!", "hello world!"))) ? CORRECT : WRONG);
    printf("-------------------------\n");
    printf("\033[1mTest %d : s1 is [%s], s2 is [%s]\n\033[0m", test_counter, "are you there ?", "no");
    printf("The valid function gives : [%d]\n", strcmp("are you there ?", "no"));
    printf("The wrong function gives : [%d]\n", ft_strcmp("are you there ?", "no"));
    printf("%s\n", ((strcmp("are you there ?", "no") == ft_strcmp("are you there ?", "no"))) ? CORRECT : WRONG);
    printf("-------------------------\n");
    printf("\033[1mTest %d : s1 is [%s], s2 is [%s]\n\033[0m", test_counter, "1", "1 2 3 4 5 6 7 8");
    printf("The valid function gives : [%d]\n", strcmp("1", "1 2 3 4 5 6 7 8"));
    printf("The wrong function gives : [%d]\n", ft_strcmp("1", "1 2 3 4 5 6 7 8"));
    printf("%s\n", ((strcmp( "1", "1 2 3 4 5 6 7 8") == ft_strcmp("1", "1 2 3 4 5 6 7 8"))) ? CORRECT : WRONG);
    printf("-------------------------\n");
    printf("\033[1mTest %d : s1 is [%s], s2 is [%s]\n\033[0m", test_counter, "", "Lorem Ipsum... ");
    printf("The valid function gives : [%d]\n", strcmp("", "Lorem Ipsum... "));
    printf("The wrong function gives : [%d]\n", ft_strcmp("", "Lorem Ipsum... "));
    printf("%s\n", ((strcmp("", "Lorem Ipsum... ") == ft_strcmp("", "Lorem Ipsum... "))) ? CORRECT : WRONG);
    printf("-------------------------\n");
    return (1);
}

int     testing_ft_write()
{
    int     test_counter = 0;
    int     fd = open("write_in.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    char    *zero = "";
    char    *test = "test\n";
    char    *test1 = "test1\n";
    char    *djae = "J'groove comme un White Barry\n";
    char    *write_in = "I came in that file to write something.\n";

    printf("\033[1mLet's testing ft_write !\n\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%ld]\n", write(1, test, strlen(test)));
    printf(" = The wrong function gives : [%ld]\n", ft_write(1, test, strlen(test)));
	printf("It means the test is : %s\n", (write(1, test, strlen(test)) == ft_write(1, test, strlen(test))? CORRECT : WRONG));
    perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%ld]\n", write(1, test1, strlen(test1)));
    printf(" = The wrong function gives : [%ld]\n", ft_write(1, test1, strlen(test1)));
	printf("It means the test is : %s\n", (write(1, test1, strlen(test1)) == ft_write(1, test1, strlen(test1))? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%ld]\n", write(1, zero, -1));
    printf(" = The wrong function gives : [%ld]\n", ft_write(1, zero, -1));
	printf("It means the test is : %s\n", (write(1, zero, -1) == ft_write(1, zero, -1)? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%ld]\n", write(1, djae, strlen(djae)));
    printf(" = The wrong function gives : [%ld]\n", ft_write(1, djae, strlen(djae)));
	printf("It means the test is : %s\n", (write(1, djae, strlen(djae)) == ft_write(1, djae, strlen(djae))? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
	printf(" = The valid function gives : [%ld]\n", write(0, NULL, 7));
	printf(" = The wrong function gives : [%ld]\n", ft_write(0, NULL, 7));
    printf("It means the test is : %s\n", (write(0, NULL, 7) == ft_write(0, NULL, 7)? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
	printf(" = The valid function gives : [%ld]\n", write(0, NULL, 7));
	printf(" = The wrong function gives : [%ld]\n", ft_write(0, NULL, 7));
    printf("It means the test is : %s\n", (write(0, NULL, 7) == ft_write(0, NULL, 7)? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest on fd %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
	printf(" = The valid function gives : [%ld]\n", write(fd, write_in, strlen(write_in)));
	printf(" = The wrong function gives : [%ld]\n", ft_write(fd, write_in, strlen(write_in)));
    printf("It means the test is : %s\n", (write(fd, write_in, strlen(write_in)) == ft_write(fd, write_in, strlen(write_in))? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
	printf(" = The valid function gives : [%ld]\n", write(2, NULL, -3));
	printf(" = The wrong function gives : [%ld]\n", ft_write(2, NULL, -3));
    printf("It means the test is : %s\n", (write(2, NULL, -3) == ft_write(2, NULL, -3)? CORRECT : WRONG));
    perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    return (1);
}

int     testing_ft_read()
{
    int     test_counter = 0;
    int     fd = open("ft_read.s", O_RDONLY);
    int     fd1 = open("include/main.h", O_RDONLY);
    int     fd2 = open("Makefile", O_RDONLY);
    int     fd3 = open("empty", O_RDONLY);
    char    buffer[100];
    printf("\033[1mLet's testing ft_read !\n\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%ld]\n", read(fd, buffer, 5));
    printf(" = The wrong function gives : [%ld]\n", ft_read(fd, buffer, 5));
	printf("It means the test is : %s\n", (read(fd, buffer, 5) == ft_read(fd, buffer, 5)? CORRECT : WRONG));
    perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%ld]\n", read(fd, buffer, -1));
    printf(" = The wrong function gives : [%ld]\n", ft_read(fd, buffer, -1));
	printf("It means the test is : %s\n", (read(fd, buffer, -1) == ft_read(fd, buffer, -1)? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%ld]\n", read(fd, buffer, 0));
    printf(" = The wrong function gives : [%ld]\n", ft_read(fd, buffer, 0));
	printf("It means the test is : %s\n", (read(fd, buffer, 0) == ft_read(fd, buffer, 0)? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%ld]\n", read(fd1, buffer, 100));
    printf(" = The wrong function gives : [%ld]\n", ft_read(fd1, buffer, 100));
	printf("It means the test is : %s\n", (read(fd1, buffer, 100) == ft_read(fd1, buffer, 100)? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%ld]\n", read(fd2, buffer, 75));
    printf(" = The wrong function gives : [%ld]\n", ft_read(fd2, buffer, 75));
	printf("It means the test is : %s\n", (read(fd2, buffer, 75) == ft_read(fd2, buffer, 75)? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%ld]\n", read(fd3, buffer, 10));
    printf(" = The wrong function gives : [%ld]\n", ft_read(fd3, buffer, 10));
	printf("It means the test is : %s\n", (read(fd3, buffer, 10) == ft_read(fd3, buffer, 10)? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    return (1);
}

int     testing_ft_strdup()
{
    char    *zero = "";
    char    *destzero;
    char    *destdupzero;
    int     test_counter = 0;
    char    *freeze = "J’suis giga, t’es nano, ils peuvent pas m’voir comme si j’ai l’anneau";
    char    *destfreeze;
    char    *destdupfreeze;
    char    *long_one = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    char    *destlong_one;
    char    *destduplong_one;
    printf("\033[1mLet's testing ft_strdup !\n\033[0m");
     printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%s]\n", destdupzero = strdup(zero));
    printf(" = The wrong function gives : [%s]\n", destzero = ft_strdup(zero));
    printf("-------------------------\n");
	printf("It means the (strcmp on source and dest)test is : %s\n", ((!strcmp(destzero, zero)) ? CORRECT : WRONG));
    printf("It means the (strcmp on strdup dest result and ft_strdup dest result)test is : %s\n", ((!strcmp(destzero, destdupzero)) ? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%s]\n", destdupfreeze = strdup(freeze));
    printf(" = The wrong function gives : [%s]\n", destfreeze = ft_strdup(freeze));
    printf("-------------------------\n");
	printf("It means the (strcmp on source and dest)test is : %s\n", ((!strcmp(destfreeze, freeze)) ? CORRECT : WRONG));
    printf("It means the (strcmp on strdup dest result and ft_strdup dest result)test is : %s\n", ((!strcmp(destfreeze, destdupfreeze)) ? CORRECT : WRONG));
    //perror("\033[32mSyscall check with errno\033[0m");
    printf("-------------------------\n");
    printf("\033[1mTest %d\n\033[0m", ++test_counter);
    printf("-------------------------\n");
    printf(" = The valid function gives : [%s]\n", destduplong_one = strdup(long_one));
    printf(" = The wrong function gives : [%s]\n", destlong_one = ft_strdup(long_one));
    printf("-------------------------\n");
	printf("It means the (strcmp on source and dest)test is : %s\n", ((!strcmp(destlong_one, long_one)) ? CORRECT : WRONG));
    printf("It means the (strcmp on strdup dest result and ft_strdup dest result)test is : %s\n", ((!strcmp(destlong_one, destduplong_one)) ? CORRECT : WRONG));
    printf("-------------------------\n");
    return (1);
}

int     main()
{ 
    testing_ft_strlen();
    testing_ft_strcpy();
    testing_ft_strcmp();
    testing_ft_write();
    testing_ft_read();
    testing_ft_strdup();
    printf("Test is finished.\n");
    return (0);
}
