/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:29:48 by ngeny             #+#    #+#             */
/*   Updated: 2023/12/18 13:49:14 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_save(char *save)
{
	char	*new_line;
	int		cur_save;
	int		cur_new;

	cur_save = 0;
	cur_new = 0;
	while (save[cur_save] && save[cur_save] != '\n')
		cur_save++;
	if (!save[cur_save])
	{
		free (save);
		return (NULL);
	}
	new_line = (char *) malloc(sizeof(char) * (ft_strlen(save) - cur_save + 1));
	if (new_line == NULL)
		return (NULL);
	cur_save++;
	while (save[cur_save] != '\0')
		new_line[cur_new++] = save[cur_save++];
	new_line[cur_new] = '\0';
	free (save);
	return (new_line);
}

char	*fetch_line(char *save)
{
	int		cur;
	char	*line;

	cur = 0;
	line = NULL;
	if (!save[cur])
		return (NULL);
	while (save[cur] && save[cur] != '\n')
		cur++;
	line = (char *) malloc(sizeof(char) * cur + 2);
	if (line == NULL)
		return (NULL);
	cur = 0;
	while (save[cur] && save[cur] != '\n')
	{
		line[cur] = save[cur];
		cur++;
	}
	if (save[cur] == '\n')
		line[cur++] = '\n';
	line[cur] = '\0';
	return (line);
}

char	*copy_buff(int fd, char *save)
{
	char	*buff;
	int		ck_eol;
	int		nb_read;

	ck_eol = -1;
	nb_read = 1;
	buff = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	while (ck_eol == -1 && nb_read != 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[nb_read] = '\0';
		ck_eol = check_eol(buff);
			save = ft_strjoin(save, buff);
		if (nb_read < 1)
			ck_eol = 1;
	}
	free (buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = copy_buff(fd, save);
	if (!save)
		return (NULL);
	line = fetch_line(save);
	save = clean_save(save);
	return (line);
}
