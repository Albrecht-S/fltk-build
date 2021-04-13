//
// Hello, World! program for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2021 by Bill Spitzak and others.
// Modified by Albrecht Schlosser 2021.
//
// This program uses FLTK:
//
//     https://www.fltk.org
//

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <stdio.h>

int main(int argc, char **argv) {
  char label[40];
  sprintf(label, "Hello, FLTK %d.%d.%d !", 
          FL_MAJOR_VERSION, FL_MINOR_VERSION, FL_PATCH_VERSION);
  printf("%s\n", label); fflush(stdout);
  Fl_Window *window = new Fl_Window(340, 120);
  Fl_Box *box = new Fl_Box(20, 20, 300, 80, label);
  box->box(FL_FLAT_BOX);
  box->labelfont(FL_BOLD + FL_ITALIC);
  box->labelsize(24);
  window->end();
  window->show(argc, argv);
  return Fl::run();
}
