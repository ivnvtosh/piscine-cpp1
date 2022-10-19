/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 02:30:37 by ccamie            #+#    #+#             */
/*   Updated: 2022/10/19 03:07:17 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int myToUpper(int character) {
    if (character >= 97 && character <= 122) {
		return character - 32;
	} else {
		return character;
	}
}

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return EXIT_SUCCESS;
	}

	int j = 1;
	while (j < argc) {

		int i = 0;
		while (int character = argv[j][i]) {
			std::cout << (char)myToUpper(character);
			i += 1;
		}

		j += 1;
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;
}
