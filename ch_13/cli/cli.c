#include "../rbt_node.h"
#include "../rbt_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define cli_readline_buffersize 1024
#define cli_token_buffsize 64
#define cli_token_delim " \t\r\n\a"

// Initializing tree
rbt_tree * tree;

/**
 * Function declarations for builtins
 */
int insert(char **args);
int delete(char **args);
int search(char **args);
int print(char **args);
int load(char **args);
int cli_exit(char **args);
int new(char **args);


char *builtin_str[] = {
	"insert",
	"delete",
	"print",
	"load",
	"exit",
	"new"
};

int (*builtin_func[]) (char **) = {
	&insert,
	&delete,
	&print,
	&load,
	&cli_exit,
	&new
};

int cli_num_builtins() {
	return sizeof(builtin_str) / sizeof( char * );
}

/**
 * Builtin implementations
 */
int insert( char ** args ) {
	int i = 1;
	int num;
	rbt_node * n;

	// Should have a list of keys to insert
	while ( args[i] != NULL )
	{
		num = atoi(args[i]);

		if ( num == 0 )
		{
			printf("Integer value not given with value %s\n", args[i]);
			i++;
			continue;
		}

		// Search for duplicate keye'd node
		n = RBT_Search(tree, tree->root, num);

		if ( n != tree->null )
		{
			printf("Node with key of %c is already in tree\n", n->key);
			i++;
			continue;
		}

		// Insert new node
		n = rbt_node_new( num );

		RBT_Insert(tree, n);

		i++;
	}

	RB_Tree_Print( tree );
	return 1;
}

int delete( char ** args ) {
	int i = 1, num;
	rbt_node * n;

	while ( args[i] != NULL )
	{
		num = atoi(args[i]);

		if ( num == 0 )
		{
			printf("Integer value not given with value %s\n", args[i]);
			i++;
			continue;
		}

		// Search for node
		n = RBT_Search(tree, tree->root, num);

		if ( n == tree->null )
		{
			printf("Error: Missing Node with key %d\n", num);
			i++;
			continue;
		}

		// Delete node
		RBT_Delete(tree, n);

		i++;

	}
	return 1;
}

int load ( char ** args ) {
	printf("Not Implemented\n");
	return 0;
}

int print ( char ** args ) {

	if ( args[1] == NULL )
	{
		printf("Print argument takes either tree or node.\nUse \"tree\" to print the full tree, use \"node\" with a key specifier to print the data of that node\n");
	}
	else if ( strcmp("tree", args[1]) == 0 )
	{
		RB_Tree_Print(tree);
	}
	else if ( strcmp("node", args[1]) == 0 )
	{
		int i = 2, num;
		rbt_node * n;
		while ( args[i] != NULL )
		{
			num = atoi(args[i]);

			if ( num == 0 )
			{
				printf("Error: Must provide an integer valued key");
				i++;
				continue;
			}

			// search for node
			n = RBT_Search(tree, tree->root, num);

			if ( n == tree->null )
			{
				printf("Error: A node with that key is not in the tree");
				i++;
				continue;
			}

			Print_RBT_Node(n);
		}
	}
	return 1;
}

int new ( char ** args ) {
	rbt_tree_free( tree );

	tree = rbt_tree_new();

	return 1;
}

int cli_exit( char ** args ) {
	return 0;
}


char * CLIReadline(void)
{
	int buffSz = cli_readline_buffersize;
	int position = 0;
	char *buffer = malloc(sizeof(char) * buffSz);
	int c;

	if ( !buffer ) {
		fprintf(stderr, "cli: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1) {
		// Read a character
		c = getchar();

		if ( c == EOF || c == '\n' )
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		if ( position >= buffSz )
		{
			buffSz += cli_readline_buffersize;
			buffer = realloc(buffer, buffSz);

			if ( ! buffer )
			{
				fprintf(stderr, "cli: allocation buffer resize error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

char ** CLISplitLine(char * line) {
	int buffSz = cli_token_buffsize;
	int position = 0;
	char ** tokens = malloc(buffSz * sizeof(char *));
	char * token;

	if ( ! tokens )
	{
		fprintf(stderr, "cli: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, cli_token_delim);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if ( position >= buffSz )
		{
			buffSz += cli_token_buffsize;
			tokens = realloc(tokens, buffSz * sizeof(char *));
			if ( ! tokens )
			{
				fprintf(stderr, "cli: reallocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, cli_token_delim);
	}
	tokens[position] = NULL;
	return tokens;
}

int cli_launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if ( pid == 0 )
	{
		// Child process, execute command on child process.
		if (execvp(args[0], args) == - 1) {
			perror("cli");
		}
		exit(EXIT_FAILURE);
	}
	else if ( pid < 0 )
	{
		// Error Forking
		perror("lsh");
	}
	else {
		// Parent Process - Fork executed successfuly
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}

int CLIExecute(char **args) {
	int i;

	// Empty Command
	if ( args[0] == NULL )
	{
		return 1;
	}

	for (i = 0; i < cli_num_builtins(); i++)
	{
		// If we have a builtin available with that name available
		if ( strcmp(args[0], builtin_str[i]) == 0 )
		{
			return (*builtin_func[i])(args);
		}
	}

	return cli_launch(args);
}

void cli_loop(void)
{
	char * line;
	char ** args;
	int status;

	do {
		printf("> ");
		// read line
		line = CLIReadline();

		// Split arguments given to cli
		args = CLISplitLine(line);

		// Status of the execute will determine if we keep on running
		status = CLIExecute(args);

		free(line);
		free(args);
	} while ( status );
}

int main (int argc, char **argv) {
	if ( tree == NULL )
	{
		tree = rbt_tree_new();
	}

	// Main loop here
	cli_loop();

	return EXIT_SUCCESS;
}