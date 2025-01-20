/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:18:49 by chrhu             #+#    #+#             */
/*   Updated: 2023/12/29 10:56:13 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//-------------------------------BONUS-----------------------
#include "get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>
#include "/home/ngeny/42/color/fct_color.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*line1;
	char	*line2;
	char	*line3;
	char	*line4;
	int		i = 1;

	fd1 = open("/home/ngeny/42/42_cursus/get_next_line/text.txt", O_RDONLY);
	fd2 = open("/home/ngeny/42/42_cursus/get_next_line/text_no_newline.txt", O_RDONLY);
	fd3 = open("/home/ngeny/42/42_cursus/get_next_line/text_newline.txt", O_RDONLY);
	fd4 = open("/home/ngeny/42/42_cursus/get_next_line/text_null.txt", O_RDONLY);
	
	printf("buffer = %d", BUFFER_SIZE);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
	{
		perror("Error opening file\n");
		return (1);
	}

/*******************1st*************************/
	while (i < 8)
	{
		purple(); printf("\n----------Open text %d time:-----------\n", i);
		line1 = get_next_line(fd1);	
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		line4 = get_next_line(fd4);

		green(); printf("Line text: \n");
		white(); printf("%s\n", line1);
		if (!line1)
		{
			red(); printf("Reached end of file or error file 1.\n");
		}
		
		green(); printf("Line text_no_newline: \n");
		white(); printf("%s\n", line2);
		if (!line2)
		{
			red(); printf("Reached end of file or error file 2.\n");
		}
		
		green(); printf("Line text_newline: \n");
		white(); printf("%s\n", line3);
		if (!line3)
		{
			red(); printf("Reached end of file or error file 3.\n");
		}
		
		green(); printf("Line text_null: \n");
		white(); printf("%s\n", line4);
		if (!line4)
		{
			red(); printf("Reached end of file or error file 4.\n");
		}
		
		if (!line1 && !line2 && !line3 && !line4)
		{
			white(); printf("\n");
			break;
		}
		
		i++;
		free(line1);
		free(line2);
		free(line3);
		free(line4);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
