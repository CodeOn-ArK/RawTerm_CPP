#include <menu.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

ITEM* my_item[] = {new_item("Choice 1", " "),
                   new_item("Choice 2", " "),
                   new_item("Choice 3", " "),
                   new_item("Choice 4", " "),
                   new_item("Choice 5", " "),
                   new_item("Choice 6", " "),
                   new_item("Choice 7", " "),
                   new_item("Exit", " "),
                   NULL};
ITEM* my_item1[] = {new_item("Choice 11", " "), new_item("Exit 1", " "), NULL};
ITEM* my_item2[] = {new_item("Choice 21", " "), new_item("Choice 22", " "),
                    new_item("Exit 2", " "), NULL};
ITEM* my_item3[] = {new_item("Choice 31", " "), new_item("Choice 32", " "),
                    new_item("Choice 33", " "), new_item("Exit 3", " "), NULL};
ITEM* my_item4[] = {new_item("Choice 41", " "), new_item("Choice 42", " "),
                    new_item("Choice 43", " "), new_item("Choice 44", " "),
                    new_item("Exit 4", " "),    NULL};
ITEM* my_item5[] = {new_item("Choice 51", " "),
                    new_item("Choice 52", " "),
                    new_item("Choice 53", " "),
                    new_item("Choice 54", " "),
                    new_item("Choice 55", " "),
                    new_item("Exit 5", " "),
                    NULL};
ITEM* my_item6[] = {new_item("Choice 61", " "), new_item("Choice 62", " "),
                    new_item("Choice 63", " "), new_item("Choice 64", " "),
                    new_item("Choice 65", " "), new_item("Choice 66", " "),
                    new_item("Exit 6", " "),    NULL};
ITEM* my_item7[] = {new_item("Choice 71", " "),
                    new_item("Choice 72", " "),
                    new_item("Choice 73", " "),
                    new_item("Choice 74", " "),
                    new_item("Choice 75", " "),
                    new_item("Choice 76", " "),
                    new_item("Choice 77", " "),
                    new_item("Exit 7", " "),
                    NULL};

int main(void) {
  int i, c, d;
  ITEM* cur_item;

  /* Initialize curses */
  initscr();
  start_color();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_MAGENTA, COLOR_BLACK);

  /* Initialize items */
  MENU* my_menu = new_menu(my_item);
  //	item_opts_off(my_items[3], O_SELECTABLE);
  //	item_opts_off(my_items[6], O_SELECTABLE);

  /* Set fore ground and back ground of the menu */
  set_menu_fore(my_menu, COLOR_PAIR(1) | A_REVERSE);
  set_menu_back(my_menu, COLOR_PAIR(2));
  set_menu_grey(my_menu, COLOR_PAIR(3));
  set_menu_format(my_menu, 1, 8);

  /* Post the menu */
  mvprintw(LINES - 3, 0, "Press <ENTER> to see the option selected");
  mvprintw(LINES - 2, 0, "Up,Down,Left & Right arrow keys to naviage ");
  post_menu(my_menu);
  refresh();

lp:
  while (c = getch()) {
    switch (c) {
      case KEY_LEFT:
        menu_driver(my_menu, REQ_LEFT_ITEM);
        break;
      case KEY_RIGHT:
        menu_driver(my_menu, REQ_RIGHT_ITEM);
        break;
      case 10: /* Enter */
        move(20, 0);
        clrtoeol();
        mvprintw(20, 0, "Item selected is : %s",
                 item_name(current_item(my_menu)));
        if (!strcmp("Exit", item_name(current_item(my_menu)))) {
          unpost_menu(my_menu);
          for (int i = 0; i < 8; ++i) free_item(my_item[i]);
          free_menu(my_menu);
          endwin();
          goto ret;
        } else if (!strcmp("Choice 1", item_name(current_item(my_menu)))) {
          unpost_menu(my_menu);
          MENU* my_menu1 = new_menu(my_item1);
          set_menu_fore(my_menu1, COLOR_PAIR(1) | A_REVERSE);
          set_menu_back(my_menu1, COLOR_PAIR(2));
          set_menu_grey(my_menu1, COLOR_PAIR(3));
          post_menu(my_menu1);
          refresh();
          while (d = getch()) {
            switch (d) {
              case KEY_UP:
                menu_driver(my_menu1, REQ_UP_ITEM);
                break;
              case KEY_DOWN:
                menu_driver(my_menu1, REQ_DOWN_ITEM);
                break;
              case 10:
                move(23, 0);
                clrtoeol();
                mvprintw(23, 0, "Item selected is : %s",
                         item_name(current_item(my_menu1)));
                if (!strcmp("Exit 1", item_name(current_item(my_menu1)))) {
                  unpost_menu(my_menu1);
                  for (i = 0; i < 2; ++i) free_item(my_item1[i]);
                  free_menu(my_menu1);
                  post_menu(my_menu);
                  goto lp;
                }
                pos_menu_cursor(my_menu1);
                break;
            }
          }
        } else if (!strcmp("Choice 2", item_name(current_item(my_menu)))) {
          unpost_menu(my_menu);
          MENU* my_menu2 = new_menu(my_item2);
          set_menu_fore(my_menu2, COLOR_PAIR(1) | A_REVERSE);
          set_menu_back(my_menu2, COLOR_PAIR(2));
          set_menu_grey(my_menu2, COLOR_PAIR(3));
          post_menu(my_menu2);
          refresh();
          while (d = getch()) {
            switch (d) {
              case KEY_UP:
                menu_driver(my_menu2, REQ_UP_ITEM);
                break;
              case KEY_DOWN:
                menu_driver(my_menu2, REQ_DOWN_ITEM);
                break;
              case 10:
                move(23, 0);
                clrtoeol();
                mvprintw(23, 0, "Item selected is : %s",
                         item_name(current_item(my_menu2)));
                if (!strcmp("Exit 2", item_name(current_item(my_menu2)))) {
                  unpost_menu(my_menu2);
                  for (i = 0; i < 3; ++i) free_item(my_item2[i]);
                  free_menu(my_menu2);
                  post_menu(my_menu);
                  goto lp;
                }
                pos_menu_cursor(my_menu2);
                break;
            }
          }
        } else if (!strcmp("Choice 3", item_name(current_item(my_menu)))) {
          unpost_menu(my_menu);
          MENU* my_menu3 = new_menu(my_item3);
          set_menu_fore(my_menu3, COLOR_PAIR(1) | A_REVERSE);
          set_menu_back(my_menu3, COLOR_PAIR(2));
          set_menu_grey(my_menu3, COLOR_PAIR(3));
          post_menu(my_menu3);
          refresh();
          while (d = getch()) {
            switch (d) {
              case KEY_UP:
                menu_driver(my_menu3, REQ_UP_ITEM);
                break;
              case KEY_DOWN:
                menu_driver(my_menu3, REQ_DOWN_ITEM);
                break;
              case 10:
                move(23, 0);
                clrtoeol();
                mvprintw(23, 0, "Item selected is : %s",
                         item_name(current_item(my_menu3)));
                if (!strcmp("Exit 3", item_name(current_item(my_menu3)))) {
                  unpost_menu(my_menu3);
                  for (i = 0; i < 4; ++i) free_item(my_item3[i]);
                  free_menu(my_menu3);
                  post_menu(my_menu);
                  goto lp;
                }
                pos_menu_cursor(my_menu3);
                break;
            }
          }
        } else if (!strcmp("Choice 4", item_name(current_item(my_menu)))) {
          unpost_menu(my_menu);
          MENU* my_menu4 = new_menu(my_item4);
          set_menu_fore(my_menu4, COLOR_PAIR(1) | A_REVERSE);
          set_menu_back(my_menu4, COLOR_PAIR(2));
          set_menu_grey(my_menu4, COLOR_PAIR(3));
          post_menu(my_menu4);
          refresh();
          while (d = getch()) {
            switch (d) {
              case KEY_UP:
                menu_driver(my_menu4, REQ_UP_ITEM);
                break;
              case KEY_DOWN:
                menu_driver(my_menu4, REQ_DOWN_ITEM);
                break;
              case 10:
                move(23, 0);
                clrtoeol();
                mvprintw(23, 0, "Item selected is : %s",
                         item_name(current_item(my_menu4)));
                if (!strcmp("Exit 4", item_name(current_item(my_menu4)))) {
                  unpost_menu(my_menu4);
                  for (i = 0; i < 5; ++i) free_item(my_item4[i]);
                  free_menu(my_menu4);
                  post_menu(my_menu);
                  goto lp;
                }
                pos_menu_cursor(my_menu4);
                break;
            }
          }
        } else if (!strcmp("Choice 5", item_name(current_item(my_menu)))) {
          unpost_menu(my_menu);
          MENU* my_menu5 = new_menu(my_item5);
          set_menu_fore(my_menu5, COLOR_PAIR(1) | A_REVERSE);
          set_menu_back(my_menu5, COLOR_PAIR(2));
          set_menu_grey(my_menu5, COLOR_PAIR(3));
          post_menu(my_menu5);
          refresh();
          while (d = getch()) {
            switch (d) {
              case KEY_UP:
                menu_driver(my_menu5, REQ_UP_ITEM);
                break;
              case KEY_DOWN:
                menu_driver(my_menu5, REQ_DOWN_ITEM);
                break;
              case 10:
                move(23, 0);
                clrtoeol();
                mvprintw(23, 0, "Item selected is : %s",
                         item_name(current_item(my_menu5)));
                if (!strcmp("Exit 5", item_name(current_item(my_menu5)))) {
                  unpost_menu(my_menu5);
                  for (i = 0; i < 6; ++i) free_item(my_item5[i]);
                  free_menu(my_menu5);
                  post_menu(my_menu);
                  goto lp;
                }
                pos_menu_cursor(my_menu5);
                break;
            }
          }
        } else if (!strcmp("Choice 6", item_name(current_item(my_menu)))) {
          unpost_menu(my_menu);
          MENU* my_menu6 = new_menu(my_item6);
          set_menu_fore(my_menu6, COLOR_PAIR(1) | A_REVERSE);
          set_menu_back(my_menu6, COLOR_PAIR(2));
          set_menu_grey(my_menu6, COLOR_PAIR(3));
          post_menu(my_menu6);
          refresh();
          while (d = getch()) {
            switch (d) {
              case KEY_UP:
                menu_driver(my_menu6, REQ_UP_ITEM);
                break;
              case KEY_DOWN:
                menu_driver(my_menu6, REQ_DOWN_ITEM);
                break;
              case 10:
                move(23, 0);
                clrtoeol();
                mvprintw(23, 0, "Item selected is : %s",
                         item_name(current_item(my_menu6)));
                if (!strcmp("Exit 6", item_name(current_item(my_menu6)))) {
                  unpost_menu(my_menu6);
                  for (i = 0; i < 7; ++i) free_item(my_item6[i]);
                  free_menu(my_menu6);
                  post_menu(my_menu);
                  goto lp;
                }
                pos_menu_cursor(my_menu6);
                break;
            }
          }
        } else if (!strcmp("Choice 7", item_name(current_item(my_menu)))) {
          unpost_menu(my_menu);
          MENU* my_menu7 = new_menu(my_item7);
          set_menu_fore(my_menu7, COLOR_PAIR(1) | A_REVERSE);
          set_menu_back(my_menu7, COLOR_PAIR(2));
          set_menu_grey(my_menu7, COLOR_PAIR(3));
          post_menu(my_menu7);
          refresh();
          while (d = getch()) {
            switch (d) {
              case KEY_UP:
                menu_driver(my_menu7, REQ_UP_ITEM);
                break;
              case KEY_DOWN:
                menu_driver(my_menu7, REQ_DOWN_ITEM);
                break;
              case 10:
                move(23, 0);
                clrtoeol();
                mvprintw(23, 0, "Item selected is : %s",
                         item_name(current_item(my_menu7)));
                if (!strcmp("Exit 7", item_name(current_item(my_menu7)))) {
                  unpost_menu(my_menu7);
                  for (i = 0; i < 8; ++i) free_item(my_item7[i]);
                  free_menu(my_menu7);
                  post_menu(my_menu);
                  goto lp;
                }
                pos_menu_cursor(my_menu7);
                break;
            }
          }
        }

        break;
    }
  }
ret:
  return 0;
}
