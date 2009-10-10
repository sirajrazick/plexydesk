/*******************************************************************************
* This file is part of PlexyDesk.
*  Maintained by : Siraj Razick <siraj@kde.org>
*  Authored By  : Lahiru Lakmal <llahiru@gmail.com>
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

#include <plexy.h>
#include "twitwidget.h"
#include <math.h>

#include <QMatrix>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>
#include <QBitmap>
#include <QGraphicsSceneWheelEvent>
#include <QStyleOptionGraphicsItem>

namespace PlexyDesk
{

TwitWidget::TwitWidget (const QRectF &rect, QWidget *widget):
ListView(rect,widget)
{
  PlexyDesk::AbstractPluginInterface * utubeEngine = (PlexyDesk::AbstractPluginInterface*)
  PlexyDesk::PluginLoader::getInstance()->instance("restengine");
  mMap.insert("url", QUrl("http://twitter.com/statuses/update.xml"));
  mMap.insert("type", 0);//post
  mMap.insert("user", "sirajrazick");
  mMap.insert("pass", "ijs3792");
  //utubeEngine->instance()->pushData(map);

  if (utubeEngine) {
      connect(utubeEngine,SIGNAL(data(QVariantMap&)),this,SLOT(data(QVariantMap&)));
      //connect(this ,SIGNAL(newData(QVariantMap&)), utubeEngine->instance(),SLOT(pushData(QVariantMap&)));
      if (utubeEngine->instance()) {
        qDebug() << Q_FUNC_INFO << utubeEngine;
      }
      //utubeEngine->inst;pushData(mMap);
  }else {
      qDebug("DataSource Was Null");
  }
}

TwitWidget::~TwitWidget ()
{}

void TwitWidget::data(QVariantMap& data)
{
    qDebug() << Q_FUNC_INFO << data["data"];
/*
    mVariantMap = data.toMap();

    VideoEntity videoentity;
    videoentity.title = (mVariantMap["title"]).toString();
    videoentity.link = (mVariantMap["link"]).toString();
    videoentity.desc = (mVariantMap["description"]).toString();
    videoentity.thumb = (mVariantMap["thumb"]).toString();

    mVideos.append(videoentity);
    view.setHeight(mVideos.size()*mItem_bg.height());

    ListItem * item = new ListItem();
    item->title = videoentity.title;
    item->link = videoentity.link;
    item->desc = videoentity.desc;
    item->thumb = videoentity.thumb;

    insert(item);

    emit dataChanged();
    */
}
} // namespace PlexyDesk
