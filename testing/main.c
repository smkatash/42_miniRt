/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:49:20 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/05 11:20:53 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int main(void) 
{
    const int height = 256;
    const int width = 256;
    
    printf("P3\n%d %d\n255\n", width, height);
    for (int h = height - 1; h >= 0; --h) {
        for (int w = 0; w < width; ++w) {
            auto double r = (double)w / (width - 1);
            auto double g = (double)h / (height - 1);
            auto double b = 0.25;
            int ir = (int)(255.999 * r);
            int ig = (int)(255.999 * g);
            int ib = (int)(255.999 * b);
            printf("%d %d %d\n", ir, ig, ib);
        }
    }
    return (0);
}