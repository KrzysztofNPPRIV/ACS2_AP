#ifndef APPLICATION_H
#define APPLICATION_H

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
      enum class ArgumentType { BmpPathFolder, End };

      struct Argument
      {
        const qint32 index;
        QString text;
      };

      static constexpr qint32 numberOfArguments = static_cast<qint32>(ArgumentType::End) + 1;

      QApplication *appl;
      QMap<ArgumentType, Argument *> argument;
  };
}
#endif // APPLICATION_H
