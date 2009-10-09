
#ifndef PLEXY_DATA_PLUGIN_H
#define PLEXY_DATA_PLUGIN_H
#include <plexy.h>
#include <config.h>
#include <baseplugin.h>
#include <QVariantMap>

namespace PlexyDesk
{
    class VISIBLE_SYM DataPlugin : public BasePlugin
    {
        Q_OBJECT
    public :
        DataPlugin(QObject  * object = 0) {}
        virtual ~DataPlugin() {}
    public slots:
        virtual void pushData(QVariantMap&) = 0;
    signals:
        void data(QVariantMap&);
    };
}
#endif
