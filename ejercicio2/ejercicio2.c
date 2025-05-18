#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isPalindrome(const char *s) {
    size_t i = 0, j = strlen(s);
    if (j == 0) return 0;
    j--;
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++; j--;
    }
    return 1;
}

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        perror("Error al abrir input.txt");
        return EXIT_FAILURE;
    }

    size_t bufCap = 16, len = 0;
    char *wordBuf = malloc(bufCap);
    if (!wordBuf) {
        perror("malloc");
        fclose(fp);
        return EXIT_FAILURE;
    }

    char *longest = strdup("");
    if (!longest) {
        perror("strdup");
        free(wordBuf);
        fclose(fp);
        return EXIT_FAILURE;
    }

    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            char c = tolower(ch);
            if (len + 1 >= bufCap) {
                bufCap *= 2;
                char *tmp = realloc(wordBuf, bufCap);
                if (!tmp) {
                    perror("realloc");
                    free(wordBuf);
                    free(longest);
                    fclose(fp);
                    return EXIT_FAILURE;
                }
                wordBuf = tmp;
            }
            wordBuf[len++] = c;
        } else if (len > 0) {
            wordBuf[len] = '\0';
            if (isPalindrome(wordBuf) && len > strlen(longest)) {
                free(longest);
                longest = strdup(wordBuf);
            }
            len = 0;
        }
    }

    if (len > 0) {
        wordBuf[len] = '\0';
        if (isPalindrome(wordBuf) && len > strlen(longest)) {
            free(longest);
            longest = strdup(wordBuf);
        }
    }

    printf("El palíndromo más largo es: %s\n", longest);

    free(wordBuf);
    free(longest);
    fclose(fp);
    return 0;
}
