#include "test.h"
#include "ui.h"
int main() {
    testAll();
    ui UI;
    UI.service = new_service();
    runUI(&UI);
    destroy_service(UI.service);
    return 0;
}
