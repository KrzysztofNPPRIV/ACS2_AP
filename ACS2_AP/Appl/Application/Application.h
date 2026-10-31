#ifndef APPLICATION_H
#define APPLICATION_H

#include "Appl/Application/Console.h"
#include "Appl/HMI/HMIManager/HMIManager.h"

#include <QObject>
#include <QApplication>
#include <QString>
#include <QMap>

namespace Appl
{
  class Application : public QObject
  {
      Q_OBJECT

    private:
      Q_DISABLE_COPY(Application)

    public:
      explicit Application(QObject *parent) noexcept;
      virtual ~Application() noexcept;

      int start(int argc, char *argv[]) noexcept;

    private:
      enum class ArgumentType { BmpPathFolder, LogPathFolder, End };

      struct Argument
      {
        const qint32 index;
        QString text;
      };

      static constexpr qint32 numberOfArguments = static_cast<qint32>(ArgumentType::End) + 1;

      QApplication *appl;
      QMap<ArgumentType, Argument *> argument;
      Console *console;
      HMI::HMIManager *hmiManager;

    signals:
      void print(QString text);
  };
}
#endif // APPLICATION_H
