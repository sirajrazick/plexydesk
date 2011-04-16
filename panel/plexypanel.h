#ifndef PLEXYPANEL_H
#define PLEXYPANEL_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class PlexyPanel : public QWidget
{
    Q_OBJECT
public:
    PlexyPanel(QWidget *parent = 0, Qt::WindowFlags f = 0);
    virtual ~PlexyPanel();
private slots:
    void switchLayer();
    void addWidget();
    void searchWidget();
private:
    QLineEdit *searchText;
    QPushButton *searchButton;
    QPushButton *addWidgetButton;
    QPushButton *changeLayerButton;
    void setup();
};

#endif // PLEXYPANEL_H
