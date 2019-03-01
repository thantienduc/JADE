#include "./controller.h"

int main() { 
        Store store("h1");
        Controller controller(store);
        controller.cli();
        return 0;
}
