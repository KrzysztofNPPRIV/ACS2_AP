#include "Application.h"
#include "mainwindow.h"

namespace Appl
{

  Application::Application(QObject *parent) noexcept
    : QObject{parent},
      argument
      {
        { Application::ArgumentType::BmpPathFolder,   new Argument{ .index = static_cast<qint32>(ArgumentType::BmpPathFolder) + 1, .text = "" } },
        { Application::ArgumentType::LogPathFolder,   new Argument{ .index = static_cast<qint32>(ArgumentType::LogPathFolder) + 1, .text = "" } }
      }
  {
    appl = nullptr;
    console = nullptr;
  }

  Application::~Application() noexcept
  {
    delete console;
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

        console = new Console{nullptr, argument[Application::ArgumentType::LogPathFolder]->text};
        connect(this,
                SIGNAL(print(QString)),
                console,
                SLOT(print(QString)));

        emit print("Application start");

        MainWindow w;
        w.show();

        return appl.exec();
      }
      else
      {
        appl.exit(1);
      }
    }

    return 1;
  }

}
