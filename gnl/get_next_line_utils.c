/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:38:24 by ngeny             #+#    #+#             */
/*   Updated: 2023/12/18 13:46:04 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	check_eol(char *buff)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	while (i < BUFFER_SIZE)
	{
		if (buff[i] == '\n' || buff[i] == '\0')
			return (i);
		i++;
	}
	i = -1;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = -1;
	j = 0;
	dest = NULL;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (dest == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		dest[i] = s1[i];
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}
