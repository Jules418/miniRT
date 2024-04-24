/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:22:03 by jules             #+#    #+#             */
/*   Updated: 2024/04/24 11:35:57 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>

/**
 * @brief Solve a quadratic equation ax^2 + bx + c = 0
 * @param float[6] a, b, c are in the first 3 slots of the array
 * 
 * 	Puts the discriminant in the 4th slot, 5th ans 6th are the 2 solutions
 * 		(if any)
*/
void	solve_quadratic(float coefs[6]);

#endif