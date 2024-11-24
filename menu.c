#include "menu.h"

void display_start_page() {
    clear();

    // Affichage du titre du jeu en ASCII art
    mvprintw(2, (COLS - 72) / 2, ":::::::::: :::::::::::             ::::::::  :::    ::: ::::    ::::  :::    ::: :::::::::  ");
    mvprintw(3, (COLS - 72) / 2, ":+:            :+:                :+:    :+: :+:    :+: +:+:+: :+:+:+ :+:    :+: :+:    :+: ");
    mvprintw(4, (COLS - 72) / 2, "+:+            +:+                +:+        +:+    +:+ +:+ +:+:+ +:+ +:+    +:+ +:+    +:+ ");
    mvprintw(5, (COLS - 72) / 2, ":#::+::#       +#+                +#++:++#++ +#++:++#++ +#+  +:+  +#+ +#+    +:+ +#++:++#+  ");
    mvprintw(6, (COLS - 72) / 2, "+#+            +#+                       +#+ +#+    +#+ +#+       +#+ +#+    +#+ +#+        ");
    mvprintw(7, (COLS - 72) / 2, "+#+            #+#                #+#    #+# #+#    #+# #+#       #+# #+#    #+# #+#        ");
    mvprintw(8, (COLS - 72) / 2, "###            ###     ##########  ########  ###    ### ###       ###  ########  ###        ");

    // Instructions pour jouer
    mvprintw(15, (COLS - 40) / 2, "Commands to play the game:");
    mvprintw(17, (COLS - 40) / 2, "    [^]          ");
    mvprintw(18, (COLS - 40) / 2, " [<][V][>] :  Move the player\n");
    mvprintw(20, (COLS - 40) / 2, "[________] :  Fire bullets\n");
    mvprintw(22, (COLS - 40) / 2, "    'Q'    :  Quit the game");

    // Invite pour commencer le jeu
    mvprintw(27, (COLS - 40) / 2, "Press 's' to start the game!");

    refresh();
}


void display_end_page(int you_win, int game_over) {
    clear();

    // Message principal : victoire ou défaite
    if (you_win) {
        mvprintw(5, (COLS - 26) / 2, "CONGRATULATIONS! YOU WON!");
    } else if (game_over) {
        mvprintw(5, (COLS - 18) / 2, "GAME OVER! YOU LOST!");
    }

    // Options
    mvprintw(10, (COLS - 30) / 2, "Press 'r' to restart the game");
    mvprintw(11, (COLS - 30) / 2, "Press 'q' to quit");

    refresh();
}


