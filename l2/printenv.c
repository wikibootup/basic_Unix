void printenv() {
	char **env;
	env = environ;
	while(*env) {
		printf("%s\n", *env);
		env++;
	}
}
