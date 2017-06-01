#include "miracastdevicemodel.h"

using namespace dcc;
using namespace dcc::display;

MiracastDeviceModel::MiracastDeviceModel(QObject *parent) : QObject(parent)
{

}

const QList<MiracastItem*> MiracastDeviceModel::sinkList() const
{
    return m_sinkList;
}

MiracastItem *MiracastDeviceModel::itemByPath(const QString &path)
{
    for (MiracastItem *item : m_sinkList)
        if(item->info().m_linkPath.path() == path)
            return item;

    return nullptr;
}

void dcc::display::MiracastDeviceModel::onSinkAdded(const SinkInfo &sinkinfo)
{
    MiracastItem *item = new MiracastItem(sinkinfo);
    m_sinkList.append(item);

    emit addItem(item);
}

void dcc::display::MiracastDeviceModel::onSinkRemoved(const SinkInfo &sinkinfo)
{
    MiracastItem *item = itemByPath(sinkinfo.m_linkPath.path());
    if (item)
        emit removeItem(item);
}

void MiracastDeviceModel::onSinkConnect(const QDBusObjectPath &sinkPath, bool connected)
{
    MiracastItem *item = itemByPath(sinkPath.path());
    if (item)
        item->onConnectState(connected);
}