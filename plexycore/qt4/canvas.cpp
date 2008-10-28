/*******************************************************************************
* This file is part of PlexyDesk.
*  Maintained by : Siraj Razick <siraj@kde.org>
*  Authored By  :
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

#include <canvas.h>


namespace PlexyDesk
{

class Canvas::Private
{
public:
    Private() {}
    ~Private() {}
    AbstractPluginInterface * bIface ;
    BackdropPlugin * bgPlugin;
};

Canvas::Canvas (QObject * parent): QGraphicsScene(parent), d(new Private)
{
} 

Canvas::~Canvas()
{
  
}  

void Canvas::drawBackground ( QPainter * painter, const QRectF & rect )
{
 // painter->setOpacity(0.0);
 // painter->setCompositionMode(QPainter::CompositionMode_Source);
//  painter->fillRect(rect,QColor(Qt::transparent));
}

} /* PlexyDesk */

#include "canvas.moc"