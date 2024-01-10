/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelloWorld.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:14:29 by daehlee           #+#    #+#             */
/*   Updated: 2024/01/10 17:17:34 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	int num = 20;
	std::cout << "Hello World!" << std::endl;
	std::cout << "Hello "
			  << "World!" << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;
	return 0;
}