/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:22:27 by sad-aude          #+#    #+#             */
/*   Updated: 2020/11/18 22:46:22 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

int     testing_ft_strlen()
{
    int test_counter;
    char *zero;
    char *one;
    char *two;
    char *three;
    char *four;
    char *five;
    char *six;
    char *freeze;
    char *long_one;

    test_counter = 0;
    zero = "";
    one = "1";
    two = "de";
    three = "lol";
    four = "1un1";
    five = "under";
    six = "     ?";
    freeze = "J’suis giga, t’es nano, ils peuvent pas m’voir comme si j’ai l’anneau";
    long_one = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
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
    printf("\033[1mTested string %d : [%s]\n\033[0m", ++test_counter, long_one);
    printf("The valid function gives : [%lu]\n", strlen(long_one));
    printf("The wrong function gives : [%zu]\n", ft_strlen(long_one));
	printf("It means the test is : %s\n", ((strlen(long_one) == ft_strlen(long_one)) ? CORRECT : WRONG));
    return (1);
}

int     main()
{ 
    testing_ft_strlen();
    return (0);
}
