#include "plexypanel.h"

#include <pluginloader.h>
#include <QDesktopWidget>
#include <QDebug>

//includes needed for testing
#include <QLabel>
//#include <QTextEdit>
//#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVariant>
#include <QList>
#include <QDBusConnection>
#include <QDBusMessage>

#include <X11/Xlib.h>
#include <QX11Info>
#include <netwm.h>


PlexyPanel::PlexyPanel(QWidget *parent, Qt::WindowFlags wl) : QWidget(parent, wl)
{
    setup();
}

PlexyPanel::~PlexyPanel()
{
}

void PlexyPanel::setup()
{
    move(0, 0);
    resize(600, 20);
    NETWinInfo info(QX11Info::display(), winId(), QX11Info::appRootWindow(), NET::Dock);
    info.setWindowType(NET::Dock);
    info.setState(winId(), NET::Sticky | NET::StaysOnTop | NET::KeepAbove);
    info.setDesktop(NETWinInfo::OnAllDesktops);
    setWindowOpacity(0.8);
    searchText = new QLineEdit(this);
    QLabel *lbl = new QLabel("Applications");
    searchButton = new QPushButton("Search");
    addWidgetButton = new QPushButton("Add Widget");
    /*setup test button Only for testing.. :)*/
    changeLayerButton = new QPushButton("ChangeLayer");
    connect(changeLayerButton, SIGNAL(clicked()), this, SLOT(switchLayer()));
    connect(addWidgetButton,SIGNAL(clicked()),this,SLOT(addWidget()));
    connect(searchButton,SIGNAL(clicked()),this,SLOT(searchWidget()));
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(lbl);
    layout->addWidget(searchText);
    layout->addWidget(searchButton);
    layout->addWidget(addWidgetButton);
    layout->addWidget(changeLayerButton);
    this->setLayout(layout);
}

void PlexyPanel::switchLayer()
{
    QDBusMessage busMsg = QDBusMessage::createMethodCall("org.PlexyDesk.Config","/Configuration","local.PlexyDesk.Config","changeLayer");
    QDBusConnection bus = QDBusConnection::connectToBus(QDBusConnection::SessionBus,"PlexyDesk");
    bus.call(busMsg);
}

void PlexyPanel::addWidget()
{
    QDBusMessage busMsg = QDBusMessage::createMethodCall("org.PlexyDesk.Config","/Configuration","local.PlexyDesk.Config","addWidget");
    QDBusConnection bus = QDBusConnection::connectToBus(QDBusConnection::SessionBus,"PlexyDesk");
    QList<QVariant> args;
    args<<QVariant(searchText->text());
    busMsg.setArguments(args);
    bus.call(busMsg);
}

void PlexyPanel::searchWidget()
{
    QStringList availableWidgets = PlexyDesk::PluginLoader::getInstance()->listPlugins("Widget");
    bool found = false;
    foreach(QString plugin,availableWidgets)
    {
	if (plugin == searchText->text()){
	    addWidget();	
	    found = true;
	    return;
	}
    }
    if (!found)
	searchText->setText("Error no such widget found");
}
