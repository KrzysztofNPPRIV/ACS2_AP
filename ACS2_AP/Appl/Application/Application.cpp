#include "Application.h"
#include "mainwindow.h"

namespace Appl
{

  Application::Application(QObject *parent) noexcept
    : QObject{parent},
      argument
      {
        { Application::ArgumentType::BmpPathFolder,   new Argument{ .index = static_cast<qint32>(ArgumentType::BmpPathFolder) + 1, .text = "" } }
      }
  {
    appl = nullptr;
  }

  Application::~Application() noexcept
  {

  }

  int Application::start(int argc, char *argv[]) noexcept
  {
    if (appl == nullptr)
    {
      QApplication appl{argc, argv};
      this->appl = &appl;

      if (argc == numberOfArguments)
      {
        for (auto iter = argument.begin(); iter != argument.end(); ++iter)
        {
          iter.value()->text = argv[iter.value()->index];
        }

        // console->init(argument[Application::ArgumentType::LogFilePath]->text, argument[Application::ArgumentType::LogFileStatus]->text);
        // console->print("Start");

        MainWindow w;
        w.show();

        return appl.exec();
      }
      else
      {
        //console->print("Invalid number of arguments.");
        appl.exit(1);
      }
    }
    else
    {
      //console->print("Application has been already started!!!");
    }

    return 1;
  }

}
