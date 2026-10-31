#include "Console.h"

#include <QDateTime>
#include <QDir>
#include <iostream>

namespace Appl
{

  Console::Console(QObject *parent, QString filePath) noexcept
    : QObject{parent}, filePath{filePath}
  {
    file = nullptr;
    fileCounter = 0;
    init();
  }

  Console::~Console() noexcept
  {

  }

  void Console::init() noexcept
  {
    if (file == nullptr)
    {
      filePath += "/" + QDateTime::currentDateTime().toString("yy.MM.dd") + "/" + QDateTime::currentDateTime().toString("hh.mm.ss");
      QDir folder{filePath};
      folder.mkpath(".");
      createFile();
    }
  }

  void Console::createFile() noexcept
  {
    if (file == nullptr)
    {
      QDir pathDir(filePath);
      if (pathDir.exists())
      {
        ++fileCounter;
        file = new QFile(filePath + "/ACS2_" + QString::number(fileCounter) + ".log");
      }
    }
  }

  void Console::print(QString text) noexcept
  {
    QDateTime currentDateTime = QDateTime::currentDateTime();
    std::string dateTime = currentDateTime.toString("yyyy.MM.dd hh:mm:ss").toUtf8().constData();
    std::string srcUtf8 = text.toUtf8().constData();
    std::cout << dateTime + " " + srcUtf8 + "\r\n";

    if (file != nullptr)
    {
      QString log = currentDateTime.toString("yyyy.MM.dd hh:mm:ss") + " " + text + "\r\n";
      if (file->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
      {
        file->write(log.toUtf8());
        file->close();

        if (file->size() > maxFileSize)
        {
          delete file;
          file = nullptr;
          createFile();
        }
      }
    }
  }

}
