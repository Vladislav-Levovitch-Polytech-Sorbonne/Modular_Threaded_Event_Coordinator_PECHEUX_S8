#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main()
{
	char	*buffer = NULL;
	size_t	buf_size = 2048;

	// alloc buffer qui stockera la commande entree par l'user
	buffer = (char *)calloc(sizeof(char), buf_size);
	if (buffer == NULL) {
		perror("Malloc failure");
		return (EXIT_FAILURE);
	}

	// ecriture d'un prompt
	write(1, "$> ", 3);

	// lecture de STDIN en boucle
	while (getline(&buffer, &buf_size, stdin) > 0) {
		printf("cmd = %s\n", buffer);
		write(1, "$> ", 3);
	}

	printf("Bye \n");
	free(buffer);
}
