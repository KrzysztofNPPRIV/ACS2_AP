#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QProcess>

namespace Appl
{
  class Console : public QObject
  {
      Q_OBJECT

    private:
      Q_DISABLE_COPY(Console)

    public:
      explicit Console(QObject *parent, QString filePath) noexcept;
      virtual ~Console() noexcept;

    private:
      void init() noexcept;
      void createFile() noexcept;

      static constexpr quint32 maxFileSize = 10000000;

      QString filePath;
      QFile *file;
      quint32 fileCounter;

    public slots:
      void print(QString text) noexcept;
  };
}
#endif // CONSOLE_H
