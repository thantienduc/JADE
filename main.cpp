#include "./controller.h"

int main(int argc, char *argv[]) { 
        Gtk::Main kit(argc,argv);
        Store store("h1");
        Controller controller(store);
        controller.cli();
        return 0;
}
