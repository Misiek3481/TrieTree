#include <cstdio>
#include <cstdlib>
#include "Trie.h"

int main()
{
    int n, k, commands, min, max;
    if(std::scanf("%d %d %d %d %d\n", &commands, &min, &max, &n, &k) != 5)
    {
		fprintf(stderr, "Error: Invalid input attributes format provided.\n");
		exit(1);
	}
    Trie t(n, k);
    for (int i = 0; i < commands; i++) {
        t.ReadCommand();
    }
}
