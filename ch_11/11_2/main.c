#include "ht_table.c"
#include "ht_item.c"
#include "list.c"
#include "node.c"
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 1000

int main( void ) {
	srand(time(NULL));
	FILE * f;
	char linebuff[MAX_STR_LEN];
	size_t linebuffsize;


	ht_table * t = ht_table_new();

	f = fopen("words.txt", "r");

	if ( f != NULL )
	{
		printf("Building Table...\n");
		while ( fgets( linebuff, MAX_STR_LEN, f ) ) {
			linebuffsize = strlen( linebuff );

			if ( linebuff[linebuffsize - 1] == 10 )
			{
				linebuff[--linebuffsize] = '\0';
			}

			if ( linebuff[linebuffsize - 1] == 13 )
			{
				linebuff[--linebuffsize] = '\0';
			}
			// printf("%s\n", linebuff);
			ht_chained_insert( t, linebuff, 1 + rand() % 50 );
		}
	}
	else
	{

		printf("There was an error opening the file\n");
		return 1;
	}

	fclose( f );

	printf("End Building Table\nSearching Table\n");

	// Lets see if our search is good. Search for the word "zombie"
	Node * searched_node = ht_search( t, "zombie" );
	Print_Node( searched_node );

	return 0;
}