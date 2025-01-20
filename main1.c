/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:17:33 by chrhu             #+#    #+#             */
/*   Updated: 2023/12/29 15:07:56 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//-----------------------------MANDATORY---------------------
#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include "/home/ngeny/42/color/fct_color.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*line;
	int		j;
	
	//Lis un fichier texte normal
	fd1 = open("/home/ngeny/42/42_cursus/get_next_line/text.txt", O_RDONLY);
	//Lis un fichier sans \n
	fd2 = open("/home/ngeny/42/42_cursus/get_next_line/text_no_newline.txt", O_RDONLY);
	//Lis un fichier avec \n
	fd3 = open("/home/ngeny/42/42_cursus/get_next_line/text_newline.txt", O_RDONLY);
	//Lis un ficher null
	fd4 = open("/home/ngeny/42/42_cursus/get_next_line/text_null.txt", O_RDONLY);
	
/****************condition erreur******************/
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
	{
		red(); printf("Error opening file");
		//perror("Error opening file");
		return (1);
	}
	
	printf("\nbuffer = %d\n", BUFFER_SIZE);
	
/****************Lis un fichier texte normal******************/
	j = 1;
	purple(); printf("\n------Read text-------\n");
	while (j < 9)
	{
		line = get_next_line(fd1);
		if (!line)
		{
			red(); printf("Reached end of file or error.\n\n");
			break ;
		}
		green(); printf("Line %d\n", j);
		white(); printf("%s\n", line);
		free(line);
		j++;
	}
	close(fd1);
	
/******************Lis un fichier sans \n********************/
	j = 1;
	purple(); printf("\n----Read text_no_newline----\n");
	while (j < 9)
	{
		line = get_next_line(fd2);
		if (!line)
		{
			red(); printf("Reached end of file or error.\n\n");
			break ;
		}
		green(); printf("Line %d\n", j);
		white(); printf("%s\n", line);
		free(line);
		j++;
	}
	close(fd2);
	
/********************Lis un fichier avec \n********************/
	j = 1;
	purple(); printf("\n-----Read text_newline-----\n");
	while (j < 9)
	{
		line = get_next_line(fd3);
		if (!line)
		{
			red(); printf("Reached end of file or error.\n\n");
			break ;
		}
		green(); printf("Line %d\n", j);
		white(); printf("%s\n", line);
		free(line);
		j++;
	}
	close(fd3);

/********************Lis un fichier NULL********************/
	j = 1;
	purple(); printf("\n-----Read text_null-----\n");
	while (j < 9)
	{
		line = get_next_line(fd4);
		if (!line)
		{
			red(); printf("Reached end of file or error.\n\n");
			break ;
		}
		green(); printf("Line %d\n", j);
		white(); printf("%s\n", line);
		free(line);
		j++;
	}
	close(fd4);
	
/**********Lis un nombre de 42 fichiers (impossible a lire)**********/
	while (1)
	{
		purple();printf("\n--------Read invalide fd :-----------\n");
		line = get_next_line(42);
		if (!line)
		{
			red(); printf("Reached end of file or error.\n\n");
			white(); printf("\n");
			break ;
		}
		printf("Line read: %s\n", line);
		free(line);
	}

/*********Lis avec stdin (entrer un string dans le terminal)**********/
	/* int i = 0;
	while (i < 1)
	{
		purple(); printf("\nRead stdin :\n");
		line = get_next_line(0);
		if (!line)
		{
			red(); printf("Reached end of file or error.\n");
			white(); printf("\n");
			break ;
		}
		white(); printf("Line read: %s\n", line);
		i++;
		free(line);
	} */

	free(line);
	return (0);
}
