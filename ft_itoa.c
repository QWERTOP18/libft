/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:59:25 by ymizukam          #+#    #+#             */
/*   Updated: 2024/10/29 21:47:27 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

static void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_revstr(char *s)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	while (i < len / 2)
	{
		ft_swap(&s[i], &s[len - i - 1]);
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	sign = (n < 0) ? -1 : 1;
	str = malloc(12);
	if (!str)
		return (NULL);
	i = 0;
	while (n)
	{
		str[i++] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[i++] = '-';
	str[i] = '\0';
	ft_revstr(str);
	return (str);
}
