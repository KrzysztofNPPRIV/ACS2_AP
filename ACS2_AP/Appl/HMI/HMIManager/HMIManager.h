#ifndef HMIMANAGER_H
#define HMIMANAGER_H

#include <QObject>

namespace HMI
{
  class HMIManager : public QObject
  {
      Q_OBJECT

    private:
      Q_DISABLE_COPY(HMIManager)

    public:
      explicit HMIManager(QObject *parent) noexcept;
      virtual ~HMIManager() noexcept;

      void start() noexcept;

    signals:
      void print(QString text);
  };
}
#endif // HMIMANAGER_H
