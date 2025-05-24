#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Open connection to X server
    Display *display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
        return 1;
    }

    int screen = DefaultScreen(display);

    // Create the window
    Window window = XCreateSimpleWindow(
        display, RootWindow(display, screen),
        100, 100,              // x, y position
        960, 540,              // width, height (similar to Casey's)
        1,                     // border width
        BlackPixel(display, screen),  // border color
        WhitePixel(display, screen)   // background color
    );

    // Select input events to listen for (close, expose, keypress)
    XSelectInput(display, window, ExposureMask | KeyPressMask | StructureNotifyMask);

    // Map (show) the window
    XMapWindow(display, window);

    // Main event loop
    int running = 1;
    while (running) {
        XEvent event;
        XNextEvent(display, &event);

        switch (event.type) {
            case Expose:
                // Window needs to be redrawn (do nothing for now)
                break;
            case KeyPress:
                // Exit on any key press (for demo)
                //running = 0;
                break;
            case DestroyNotify:
                running = 0;
                break;
        }
    }

    // Cleanup
    XDestroyWindow(display, window);
    XCloseDisplay(display);

    return 0;
}






































































