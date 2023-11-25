/*|-----------------------|*/
/*|> CipherBlast.c ~ 4$X <|*/
/*|-----------------------|*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void obf_flag(char *word, int key);

int main(int argc, char *argv[]) {
    printf(
    "                                                                  \n"
    "  ,- _~.          ,,                _-_ _,,   ,,               ,  \n"
    " (' /|    '       ||                   -/  )  ||   _          ||  \n"
    "((  ||   \\\\ -_-_  ||/\\\\  _-_  ,._-_   ~||_<   || < \\\\,  _-_, =||= \n"
    "((  ||   || || \\\\ || || || \\\\  ||      || \\\\  ||  /-|| ||_.   ||  \n"
    " ( / |   || || || || || ||/    ||      ,/--|| || (( ||  ~ ||  ||  \n"
    "  -____- \\\\ ||-'  \\\\ |/ \\\\,/   \\\\,    _--_-'  \\\\  \\\\/\\\\ ,-_-   \\\\, \n"
    "            |/      _/               (                            \n"
    "            '                                                     \n"
    );

    printf("|> Starting program...\n");
    if (argc < 3) {
	printf("|> Usage: %s <word_to_decrypt> <xor_key>\n", argv[0]);
	return 1;
    }
    char *word = argv[1];
    int key = atoi(argv[2]);
    obf_flag(word, key);
    printf("|> Crypted/Decrypted word: %s\n|> Finished.\n", word);
}

void obf_flag(char *word, int key) {
    int size = strlen(word);
    for (int i = 0; i < size; i++) {
    	word[i] ^= key;
    }
}


