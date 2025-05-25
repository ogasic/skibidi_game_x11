#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Display *display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
        return 1;
    }

    int screen = DefaultScreen(display);

    Window window = XCreateSimpleWindow(
        display, RootWindow(display, screen),
        100, 100,              // x, y position
        960, 540,              // width, height (similar to Casey's)
        1,                     // border width
        BlackPixel(display, screen),  // border color
        WhitePixel(display, screen)   // background color
    );

    XSelectInput(display, window, ExposureMask | KeyPressMask | StructureNotifyMask);

    XMapWindow(display, window);

    int running = 1;
    while (running) {
        XEvent event;
        XNextEvent(display, &event);

        switch (event.type) {
            case Expose:
                break;
            case KeyPress:
                running = 0;
                break;
            case DestroyNotify:
                running = 0;
                break;
        }
    }

    XDestroyWindow(display, window);
    XCloseDisplay(display);

    return 0;
}






































































