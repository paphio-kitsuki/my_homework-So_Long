/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:14 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/11 17:56:14 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

UINT	create_argb(UCHAR alpha, UCHAR r, UCHAR g, UCHAR b)
{
	return ((UINT)(alpha << 24 | r << 16 | g << 8 | b));
}

UCHAR	get_alpha(UINT argb)
{
	return ((UCHAR)(argb >> 24 & 0xFF));
}

UCHAR	get_red(UINT argb)
{
	return ((UCHAR)(argb >> 16 & 0xFF));
}

UCHAR	get_green(UINT argb)
{
	return ((UCHAR)(argb >> 8 & 0xFF));
}

UCHAR	get_blue(UINT argb)
{
	return ((UCHAR)(argb & 0xFF));
}
