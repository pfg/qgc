#include "Waypoint2DIcon.h"
#include <QPainter>

Waypoint2DIcon::Waypoint2DIcon(qreal x, qreal y, int radius, QString name, Alignment alignment, QPen* pen)
    : Point(x, y, name, alignment),
    yaw(0.0f),
    radius(radius)
{
    waypoint = NULL;
    size = QSize(radius, radius);
    drawIcon(pen);
}

Waypoint2DIcon::Waypoint2DIcon(Waypoint* wp, int listIndex, int radius, Alignment alignment, QPen* pen)
    : Point(wp->getX(), wp->getY(), QString("%1").arg(listIndex), alignment)
{
    waypoint = wp;
    this->yaw = wp->getYaw();
    size = QSize(radius, radius);
    drawIcon(pen);
}

Waypoint2DIcon::Waypoint2DIcon(qreal x, qreal y, QString name, Alignment alignment, QPen* pen)
    : Point(x, y, name, alignment)
{
    waypoint = NULL;
    int radius = 20;
    size = QSize(radius, radius);
    drawIcon(pen);
}

Waypoint2DIcon::~Waypoint2DIcon()
{
    delete mypixmap;
}

void Waypoint2DIcon::setPen(QPen* pen)
{
    mypen = pen;
    drawIcon(pen);
}

/**
 * @param yaw in radians, 0 = north, positive = clockwise
 */
void Waypoint2DIcon::setYaw(float yaw)
{
    this->yaw = yaw;
    drawIcon(mypen);
}

void Waypoint2DIcon::updateWaypoint()
{
    if (waypoint)
    {
        if (waypoint->getYaw() != yaw)
        {
            yaw = waypoint->getYaw();
            drawIcon(mypen);
        }
    }
}

void Waypoint2DIcon::drawIcon(QPen* pen)
{
    mypixmap = new QPixmap(radius+1, radius+1);
    mypixmap->fill(Qt::transparent);
    QPainter painter(mypixmap);

    // DRAW WAYPOINT
    QPointF p(radius/2, radius/2);

    float waypointSize = radius;
    QPolygonF poly(4);
    // Top point
    poly.replace(0, QPointF(p.x(), p.y()-waypointSize/2.0f));
    // Right point
    poly.replace(1, QPointF(p.x()+waypointSize/2.0f, p.y()));
    // Bottom point
    poly.replace(2, QPointF(p.x(), p.y() + waypointSize/2.0f));
    poly.replace(3, QPointF(p.x() - waypointSize/2.0f, p.y()));

//    // Select color based on if this is the current waypoint
//    if (list.at(i)->getCurrent())
//    {
//        color = QGC::colorCyan;//uas->getColor();
//        pen.setWidthF(refLineWidthToPen(0.8f));
//    }
//    else
//    {
//        color = uas->getColor();
//        pen.setWidthF(refLineWidthToPen(0.4f));
//    }

    //pen.setColor(color);
    if (pen)
    {
        pen->setWidthF(2);
        painter.setPen(*pen);
    }
    else
    {
        QPen pen2(Qt::red);
        pen2.setWidth(2);
        painter.setPen(pen2);
    }
    painter.setBrush(Qt::NoBrush);

    float rad = (waypointSize/2.0f) * 0.8 * (1/sqrt(2.0f));
    painter.drawLine(p.x(), p.y(), p.x()+sin(yaw) * radius, p.y()-cos(yaw) * rad);
    painter.drawPolygon(poly);
}
