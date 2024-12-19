/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:48:22 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/17 11:39:39 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s;
	int		len;

	len = 0;
	while (src[len])
		++len;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len + 1] = '\0';
	while (len >= 0)
	{
		s[len] = src[len];
		len--;
	}
	return (s);
}

/*#include <stdio.h>

int main(void)
{
    char *str = "bonjour";
    char *copy = ft_strdup(str);
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != copy[i])
            printf("%s", "faux");
        i++;
    }
    printf("%s\n", str);
    printf("%s", copy);
    
    free(copy);
}*/