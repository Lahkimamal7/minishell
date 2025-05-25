#include <stdio.h>      // pour printf, fgets
#include <string.h>     // pour strtok, strcmp, strcspn
#include <unistd.h>     // pour fork, execvp
#include <sys/wait.h>   // pour wait

int main() {
    char ligne[1024];    // boîte pour stocker la ligne tapée
    char *args[64];      // tableau de mots (commande + arguments)

    while (1) {
        printf("🌸 MonShell $ ");   // afficher le prompt

        // lire la ligne entrée par l'utilisateur (depuis clavier)
        if (fgets(ligne, sizeof(ligne), stdin) == NULL) break;

        // enlever le saut de ligne '\n' de la fin de la ligne
        ligne[strcspn(ligne, "\n")] = '\0';

        // découper la ligne en mots avec strtok (séparateur = espace)
        int i = 0;
        char *token = strtok(ligne, " ");
        while (token != NULL) {
            args[i++] = token;       // remplir le tableau d'arguments
            token = strtok(NULL, " ");
        }
        args[i] = NULL;              // terminer le tableau par NULL pour execvp

        // si l'utilisateur n'a rien tapé, on continue
        if (args[0] == NULL) continue;

        // gérer la commande "exit" pour quitter le shell
        if (strcmp(args[0], "exit") == 0){

printf("         ／＞　 フ\n");
printf("         | 　_　_|\n");
printf("       ／` ミ＿xノ\n");
printf("      /　　　　 |\n");
printf("     /   ヽ　　 ﾉ\n");
printf("     |　  |　|　|\n");
printf("／￣|　   |　|　|\n");
printf("(￣ヽ＿_ヽ_)__)\n");
printf("＼二)\n");

printf("Bye bye ~ prends soin de toi !\n");
break;
}

        // créer un processus enfant
        pid_t pid = fork();

        if (pid == 0) {
            // Dans le fils : on remplace le programme par la commande tapée
            execvp(args[0], args);
            // si execvp échoue, afficher un message d'erreur
            perror("Erreur");
            return 1;
        } else if (pid > 0) {
            // Dans le père : on attend la fin du fils
            wait(NULL);
        } else {
            // si fork échoue
            perror("fork");
        }
    }

    return 0;
}

