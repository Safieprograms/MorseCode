#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char morse_codes[41][8] = {
  " ",".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
  ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
  ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....",
  "-....", "--...", "---..", "----.", "-----", "--..--", ".-.-.-", "..--..",
  "-..-.",
};
const char texte[] = {' ','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ',', '.', '?', '/', '-'};

// Function to convert text to Morse code
void text_to_morse(char* str) {
    for (int l = 0; str[l] != '\0'; l++) {
        if (!isalnum(str[l]) && str[l] != ',' && str[l] != '.' && str[l] != '?' && str[l] != '/' && str[l] != '-' && str[l] != ' ') {
            printf("You can't use '%c'. Your text must contain only letters and numbers. Please try again!\n", str[l]);
            return;
        }
    }

    // Convert lowercase letters to uppercase
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }

    // Convert text to Morse code
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < 41; j++) {
            if (str[i] == texte[j]) {
                printf("%s ", morse_codes[j]);
                break;
            }
        }
    }
    printf("\n");
}

// Function to convert Morse code to text
void morse_to_text(const char* morse) {
    char* token = strtok(morse, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < sizeof(morse_codes) / sizeof(morse_codes[0]); i++) {
            if (strcmp(morse_codes[i], token) == 0) {
                printf("%c", texte[i]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("?");
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    char c;
    char string[500];
    int exit = 0;

    while (exit == 0) {
        printf("____________________________________________________________\n");
        printf(" \n \n \e[1m        Welcome to the morse Code convertor\e[0m \n");
        printf("____________________________________________________________\n \n \n");
        printf(
            "%s\n",
            "             ____           __     \n"
            "             \\===\\=========|__|=[]\n"
            "  <========^==='======>    _||_   \n"
            " _/_|_|_|_|_|_|_|_|_|_\\_^__||||_   \n"
            "|                              |   \n"
            "|                              |   \n"
            "+---/||\\----------------/||\\---+   \n"
            "   ^^^^^^              ^^^^^^");

        printf("Click the number relevant to your operation ! : \n");
        printf("1 \\ morse to text :\n");
        printf("2 \\ text to morse :\n");
        printf("3 \\ EXIT :\n");
        scanf(" %c", &c);  // Added a space before %c to consume the newline character
        fflush(stdin);

        switch (c) {
            case '1':
                printf("enter your morse code please ! : ");
                fgets(string, sizeof(string), stdin);
                string[strcspn(string, "\n")] = '\0';  // Remove the newline character
                printf("the generated text : ");
                morse_to_text(string);
                system("pause");
                break;
            case '2':
                printf("enter your text please ! : ");
                fgets(string, sizeof(string), stdin);
                string[strcspn(string, "\n")] = '\0';  // Remove the newline character
                printf(" the generated morse code : ");
                text_to_morse(string);
                

                system("pause");
                break;
            case '3':
                exit = 1;
                break;
            default:
                printf("enter a valid option please ! ");
                system("pause");
        }
    }

    return 0;
}