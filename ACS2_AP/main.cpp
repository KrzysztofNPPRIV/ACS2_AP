#include "Appl/Application/Application.h"

int main(int argc, char *argv[])
{
  Appl::Application application{nullptr};

  return application.start(argc, argv);
}
