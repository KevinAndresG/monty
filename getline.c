char *read_line(void)
{
	char *line = NULL; /*save the readed line after the prompt*/
	size_t size = 0;   /*number of characters readed*/
	char *prompt = "Holbies$ ";

	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, prompt, strlen(prompt));
	if (getline(&line, &size, stdin) == -1)
	{
		exit(EXIT_FAILURE);
		free(line);
		return (NULL);
	}
		return (line);
}
