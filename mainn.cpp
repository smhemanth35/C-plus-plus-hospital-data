#include "Enums.h"
#include "Address.h"
#include "Type.h"
#include "Customer.h"
#include "Console.h"
#include "ApplicationController.h"

int main() {
    ApplicationController* controller = new ApplicationController;
    controller->execute();
    delete controller;

    return 0;
}
