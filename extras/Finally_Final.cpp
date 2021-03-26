#include <menu.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

class switch_class;
class colour;

class colour  //: public menu
{
 private:
 protected:
 public:
  void change_clor_scheme(int i) {
    switch (i) {
      case 0:
#define PINK 0
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        mvprintw(29, 0, "inside colour blue is : ");
#define BLUE 1
        break;

      case 1:
#define BLUE 0
        init_pair(1, COLOR_BLUE, COLOR_BLACK);
        mvprintw(29, 0, "inside colour pink is : ");
#define PINK 1
        break;
    }

#ifdef PINK
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    mvprintw(30, 0, "inside colour pink is : ");
#endif
#ifdef BLUE
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    mvprintw(30, 0, "inside colour blue is : ");
#endif
  }
};
/********************-CLASS-**********************/

class switch_class {
 private:
  colour clr_obj;

 protected:
 public:
  void switch_ClassMenu(int i) {
    switch (i) {
      case 0:
        clr_obj.change_clor_scheme(0);
        break;

      case 1:
        clr_obj.change_clor_scheme(1);
        break;
        /*
                      case 1:
                        break;

                      case 1:
                        break;

                      case 1:
                        break;

                      case 1:
                        break;

                      case 1:
                        break;

                      case 1:
                        break;

                      case 1:
                        break;

                      case 1:
                        break;

                      case 1:
                        break;

                      case 1:
                        break;
                        */
    }
  }
};

/******************-FUNCTIONS-*********************/

/*********************-END-************************/

switch_class MenuObj;

ITEM* my_item[] = {new_item("Choice 1", " "), new_item("Choice 2", " "),
                   new_item("Choice 3", " "), new_item("Exit", " "), NULL};
ITEM* my_item1[] = {new_item("Choice 11", " "), new_item("Exit 1", " "), NULL};
ITEM* my_item2[] = {new_item("Choice 21", " "), new_item("Choice 22", " "),
                    new_item("Exit 2", " "), NULL};
ITEM* my_item3[] = {new_item("Choice 31", " "), new_item("Choice 32", " "),
                    new_item("Choice 33", " "), new_item("Exit 3", " "), NULL};

int main() {
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
#ifdef PINK
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
#endif
#ifdef BLUE
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
#endif
  /* Initialize items */
  MENU* my_menu = new_menu(my_item);

  /* Set fore ground and back ground of the menu */
  set_menu_fore(my_menu, COLOR_PAIR(1) | A_REVERSE);
  set_menu_back(my_menu, COLOR_PAIR(2));
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
          for (int i = 0; i < 4; ++i) free_item(my_item[i]);
          free_menu(my_menu);
          endwin();
          goto ret;
        } else if (!strcmp("Choice 1", item_name(current_item(my_menu)))) {
          unpost_menu(my_menu);
          MENU* my_menu1 = new_menu(my_item1);
          set_menu_fore(my_menu1, COLOR_PAIR(1) | A_REVERSE);
          set_menu_back(my_menu1, COLOR_PAIR(2));
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
                /*
                 * TODO
                 */
                /*
                 * TODO
                 */
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
                /*
                 *TODO
                 */
                if (!strcmp("Choice 21", item_name(current_item(my_menu2))))
                  MenuObj.switch_ClassMenu(0);
                else
                  MenuObj.switch_ClassMenu(1);
                /*
                 *TODO
                 */
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
        }
    }
  }
ret:
  return 0;
}
