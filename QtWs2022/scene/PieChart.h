
#ifndef QTSCRCPY_PIECHART_H
#define QTSCRCPY_PIECHART_H

#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QPixmap>

class PieChart : public QQuickPaintedItem
{
Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName FINAL)
    Q_PROPERTY(QColor color READ color WRITE setColor FINAL)

public:

    PieChart(QQuickItem *parent = nullptr);
    static void declareQml();


    QString name() const;
    void setName(const QString &name);

    QColor color() const;
    void setColor(const QColor &color);

    void paint(QPainter *painter) override;

private:
    QString m_name;
    QColor m_color;
    QPixmap image;

};

#endif //QTSCRCPY_PIECHART_H
