#include "application.h"

int main() {
    const Application *app = new Application();
    app->run();
    delete app;
}
