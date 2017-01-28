enum readline_success {
	SUCCESS,
	TOO_LONG,
	ERROR};
	
enum readline_success readline(
	const char* prompt, char *buffer, int bufsize);
