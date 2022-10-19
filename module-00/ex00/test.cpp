/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 03:04:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/10/19 15:13:22 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <unistd.h>

#define TARGET (char *)"./megaphone.out"
#define BUFFER 1024

void fatal() {
	perror("Test");
	exit(EXIT_FAILURE);
}

void print(char *string) {
	int i = 0;
	while (int character = string[i]) {
		if (i != 0 && i % 40 == 0) {
			std::cout << "\n          ";
		}

		switch (character) {
		case '\n':
			std::cout << ((i + 1) % 40 == 0 ? "\\\n          n" : "\\n");
			break;
		default:
			std::cout << (char)character;
			break;
		}
		i += 1;
	}

	std::cout << std::endl;
}

void test(char *expected, char **argv, char **envp) {
	static int index = 0;

	char string[BUFFER];

	int fd[2];
	if (pipe(fd) < 0) {
		fatal();
	}

	pid_t pid = fork();
	if (pid < 0) {
		fatal();
	}
	if (pid == 0) {
		if (dup2(fd[1], STDOUT_FILENO) < 0) {
			fatal();
		}
		if (close(fd[0]) < 0) {
			fatal();
		}
		if (close(fd[1]) < 0) {
			fatal();
		}
		if (execve(TARGET, argv, envp) < 0) {
			fatal();
		}
	}

	if (close(fd[1]) < 0) {
		fatal();
	}

	int status;
	waitpid(pid, &status, 0x02);
	if (WIFEXITED(status) != 0 && WEXITSTATUS(status) != EXIT_SUCCESS) {
		exit(EXIT_SUCCESS);
	}

	ssize_t readed = read(fd[0], string, BUFFER);
	if (readed < 0) {
		fatal();
	}
	if (close(fd[0]) < 0) {
		fatal();
	}
	string[readed] = '\0';

	if (std::strcmp(string, expected) != 0) {
		std::cout << "---------------------" << "TEST-0" << index << "----------------------\n";

		std::cout << "Expected: ";
		print(expected);
	
		std::cout << "Returned: ";
		print(string);
	
		std::cout << std::endl;
	}

	index += 1;
}

int main(int argc, char **argv, char **envp) {
	(void)argc;
	(void)argv;

	char *arg[16];

	arg[0] = TARGET;
	arg[1] = NULL;
	test((char *)"* LOUD AND UNBEARABLE FEEDBACK NOISE  *\n", arg, envp);

	arg[0] = TARGET;
	arg[1] = (char *)"shhhhh... I think the students are asleep...";
	arg[2] = NULL;
	test((char *)"SHHHHH... I THINK THE STUDENTS ARE ASLEEP. ..\n", arg, envp);

	arg[0] = TARGET;
	arg[1] = (char *)"Damnit";
	arg[2] = (char *)" ! ";
	arg[3] = (char *)"Sorry students, I thought this thing was off.";
	arg[4] = NULL;
	test((char *)"DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF. \n", arg, envp);

	return EXIT_SUCCESS;
}
