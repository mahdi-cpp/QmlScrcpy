#include <QPen>
#include <QPainter>

#include "PieChart.h"

PieChart::PieChart(QQuickItem *parent) : QQuickPaintedItem(parent) {
    image.load("/home/mahdi/photos/1.jpg");
}

void PieChart::declareQml() {
    qmlRegisterType<PieChart>("App", 1, 0, "PieChart");
}
void PieChart::setName(const QString &name) {
    m_name = name;
}

void PieChart::setColor(const QColor &color) {
    m_color = color;
}

QString PieChart::name() const {
    return m_name;
}

QColor PieChart::color() const {
    return m_color;
}

void PieChart::paint(QPainter *painter) {
    QPen pen(m_color, 2);

    QRectF target(0.0, 0.0, 400.0, 400.0);
    QRectF source(0.0, 0.0, 400.0, 400.0);

    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 90 * 16, 290 * 16);
    //painter->drawText(target, Qt::AlignCenter, tr("Qt\nProject"));

    //painter->drawPixmap(target, image, source);
}

