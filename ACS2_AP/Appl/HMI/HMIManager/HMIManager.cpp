#include "HMIManager.h"

namespace HMI
{

  HMIManager::HMIManager(QObject *parent) noexcept
    : QObject{parent}
  {

  }

  HMI::HMIManager::~HMIManager() noexcept
  {

  }

  void HMIManager::start() noexcept
  {
    emit print("HMIManager start");
  }

}
