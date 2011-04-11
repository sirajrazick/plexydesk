/*******************************************************************************
* This file is part of PlexyDesk.
*  Maintained by : Siraj Razick <siraj@kde.org>
*  Authored By  : Sri Lanka Institute of Information Technology
*
*  PlexyDesk is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  PlexyDesk is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with PlexyDesk. If not, see <http://www.gnu.org/licenses/lgpl.html>
*******************************************************************************/



#ifndef WEATHERPLUGIN_H
#define WEATHERPLUGIN_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QByteArray>
#include <QVariantMap>
#include <dataplugin.h>

class WeatherPlugin : public QObject
{
    Q_OBJECT;
private:
    QVariantMap weatherData;
    QString weatherError; //TODO errors are not handled yet
    
    PlexyDesk::DataPlugin *restEngine;
    QUrl WEATHER_IN_COLOMBO;
private slots:
   /**
    * Prepare the data by filtering out the reply XML from google
    * preped QVariantMap can be read by the getWeatherData() method
    **/
    void prepareData();

public:
    WeatherPlugin(QObject *parent=0);
   /**
    * returns the sorted QVariantMap to be read by the widget
    **/
    QVariantMap getWeatherData();

public slots:
   /**
    * Used to request data from the Rest engine.
    **/
    void requestData();

signals:
    void weatherDataReady();
};

#endif
