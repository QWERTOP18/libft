/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:23:21 by ymizukam          #+#    #+#             */
/*   Updated: 2024/10/29 21:44:08 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	little_len = ft_strlen(little);
	i = 0;
	while (*(big + i) && i + little_len <= len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

#ifdef DEBUG

int	main(void)
{
	const char	*largestring = "Foo Bar Baz";
	const char	*smallstring = "Bar";
	char		*ptr;
	char		*ptr1;

	ptr = strnstr(largestring, smallstring, 4);
	ptr1 = ft_strnstr(largestring, smallstring, 4);
	printf("ptr: %p\n", ptr);
	printf("ptr1: %p\n", ptr1);
	return (0);
}

#endif