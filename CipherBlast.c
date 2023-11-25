/*|-----------------------|*/
/*|> CipherBlast.c ~ 4$X <|*/
/*|-----------------------|*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_KEY 100

void obf_word(char *word, int key);
void deobf_word(char *word);
void help_menu(char *name);

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
    char *name = argv[0];
    char *arg = argv[1];
    char *word = argv[2];
    if (argc == 4 && strcmp(arg, "-m") == 0) {
	int key = atoi(argv[3]);
	obf_word(word, key);
	printf("|> Crypted word: %s\n", word);
    } else if (argc > 2 && strcmp(arg, "-b") == 0) {
	deobf_word(word);
    } else {
	help_menu(name);
    }
    printf("|> Finished.\n");
}

void obf_word(char *word, int key) {
    printf("|> Entering manual mode...\n");
    size_t size = strlen(word);
    for (int i = 0; i < size; i++) {
    	word[i] ^= key;
    }
}

void deobf_word(char *word) {
    printf("|> Entering brute force mode...\n");
    size_t size = strlen(word);
    char unchanged[MAX_KEY][size + 1];
    for (int i = 1; i <= MAX_KEY; i++) {
	strcpy(unchanged[i], word);
        for (int j = 0; j < size; j++) {
            word[j] ^= i;
        }
        printf("|> Key [%03d] <||> Possible word: %sizes\n", i, word);
        strcpy(word, unchanged[i - 1]);
    }
}

void help_menu(char *name) {
    printf("|> Usage: %s <mode> <word_to_decrypt>\n"
   	   "|> Example: %s -m label 13\n"
   	   "\tOptions:\n"
   	   "\t\t-h --help help for CipherBlast\n"
    	   "\t\t-m --manual <word_to_encrypt> <key>\tmanual mode\n"
	   "\t\t-b --brute <word_to_decrypt>\t\tbrute mode\n", name, name);
}


