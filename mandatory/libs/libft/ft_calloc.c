/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:03:13 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/28 14:49:53 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*buf;

	buf = malloc(nitems * size);
	if (buf == NULL)
		return (buf);
	ft_bzero(buf, size * nitems);
	return (buf);
}

//put in buffer the amount of memory(line 19)
//in calloc we put 0 to reserve the new memory slot(line 22)

// #include <stdio.h>
// #include <stdlib.h>

// int main () {
//    int i, n;
//    int *a;

//    printf("Number of elements to be entered:");
//    scanf("%d",&n);

//    a = (int*)calloc(n, sizeof(int));
//    printf("Enter %d numbers:\n",n);
//    for( i=0 ; i < n ; i++ ) {
//       scanf("%d",&a[i]);
//    }

//    printf("The numbers entered are: ");
//    for( i=0 ; i < n ; i++ ) {
//       printf("%d ",a[i]);
//    }
//    free( a );

//    return(0);
// }

// int main( void )
// {
//    long *buffer;

//    buffer = (long *)ft_calloc( 40, sizeof( long ) );
//    if( buffer != NULL )
//       printf( "Allocated 40 long integers\n" );
//    else
//       printf( "Can't allocate memory\n" );
//    free( buffer );
// }
