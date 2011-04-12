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


#include <QXmlQuery>
#include "weatherplugin.h"
#include <QBuffer>
#include <QTest>
#include <QDebug>

#include <pluginloader.h>

WeatherPlugin::WeatherPlugin(QObject * parent)
{
    WEATHER_IN_COLOMBO = QUrl("http://www.google.com/ig/api?weather=colombo");
    restEngine = (PlexyDesk::DataPlugin*)PlexyDesk::PluginLoader::getInstance()->instance("restengine");
    connect(restEngine, SIGNAL(dataReady()), this, SLOT(prepareData()));
}

void WeatherPlugin::prepareData()
{
    QVariant restData = restEngine->readAll()["data"];
    QByteArray weatherXml = restData.toByteArray();
    
    if (weatherXml.size() == 0)
    {
	weatherData["Error"] = QVariant("Network Error");
        return;
    }
    QBuffer buffer;
    buffer.setBuffer(&weatherXml);
    buffer.open(QIODevice::ReadOnly);

    QXmlQuery query;
    query.setFocus(&buffer);

    QStringList temp,humidity,windspeed,current,forecastDate,forecastDay,forecastLowTemp,forecastHighTemp,forecastCondition,image,f_image,c_date;

    query.setQuery("for $x in //xml_api_reply/weather/current_conditions  return string($x /temp_c/@data)");
    query.evaluateTo(&temp);

    query.setQuery("for $x in //xml_api_reply/weather/current_conditions  return string($x /humidity/@data)");
    query.evaluateTo(&humidity);

    query.setQuery("for $x in //xml_api_reply/weather/current_conditions  return string($x /wind_condition/@data)");
    query.evaluateTo(&windspeed);

    query.setQuery("for $x in //xml_api_reply/weather/current_conditions  return string($x /condition/@data)");
    query.evaluateTo(&current);

    query.setQuery("for $x in //xml_api_reply/weather/forecast_information  return string($x /forecast_date/@data)");
    query.evaluateTo(&forecastDate);

    query.setQuery("for $x in //xml_api_reply/weather/forecast_conditions  return string($x /day_of_week/@data)");
    query.evaluateTo(&forecastDay);

    query.setQuery("for $x in //xml_api_reply/weather/forecast_conditions  return string($x /low/@data)");
    query.evaluateTo(&forecastLowTemp);

    query.setQuery("for $x in //xml_api_reply/weather/forecast_conditions  return string($x /high/@data)");
    query.evaluateTo(&forecastHighTemp);

    query.setQuery("for $x in //xml_api_reply/weather/forecast_conditions  return string($x /condition/@data)");
    query.evaluateTo(&forecastCondition);

    query.setQuery("for $x in //xml_api_reply/weather/current_conditions  return string($x /icon/@data)");
    query.evaluateTo(&image);

    query.setQuery("for $x in //xml_api_reply/weather/forecast_conditions  return string($x /icon/@data)");
    query.evaluateTo(&f_image);

    query.setQuery("for $x in //xml_api_reply/weather/forecast_information  return string($x /current_date_time/@data)");
    query.evaluateTo(&c_date);

    weatherXml.clear();

    QString imgName = image.at(0);
    image.clear();
    imgName = imgName.remove(0,imgName.lastIndexOf("/")+1);
    imgName.truncate(imgName.lastIndexOf("."));
    image<<imgName;
    QStringList tmp;
    for (int i=0;i<f_image.length();i++)
    {
        imgName = f_image.at(i);
        imgName = imgName.remove(0,imgName.lastIndexOf("/")+1);
        imgName.truncate(imgName.lastIndexOf("."));
        tmp<<imgName;
    }
    f_image.clear();
    f_image = tmp;

    imgName = c_date.at(0);
    imgName.truncate(imgName.indexOf(" "));
    c_date.clear();
    c_date<<imgName;

    weatherData.clear();
    weatherData["z1f_Day"] = QVariant(forecastDay);
    weatherData["z3f_LowTemp"] = QVariant(forecastLowTemp);
    weatherData["z4f_HighTemp"] = QVariant(forecastHighTemp);
    weatherData["z2f_Condition"] = QVariant(forecastCondition);
    weatherData["temp"] = QVariant(temp);
    weatherData["humidity"] = QVariant(humidity);
    weatherData["wind"] = QVariant(windspeed);
    weatherData["current"] = QVariant(current);
    weatherData["z5curr_image"] = QVariant(image);
    weatherData["z6fore_image"] = QVariant(f_image);
    weatherData["z7curr_date"] = QVariant(c_date);
    emit weatherDataReady();
}

QVariantMap WeatherPlugin::getWeatherData()
{
   if (!weatherData.empty())
       return weatherData;
   else
   {
       weatherData["Error"] = QVariant("Network failure");
       return weatherData;
   }
}

void WeatherPlugin::requestData()
{	
   QVariantMap request;
   request["url"] = WEATHER_IN_COLOMBO;
   request["type"] = 1;
   request["params"] = 0;
   request["user"] = "";
   request["pass"] = "";
   QVariant args = QVariant(request);
   restEngine->pushData(args);
}
