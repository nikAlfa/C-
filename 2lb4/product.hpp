#pragma once

#include <QString>
#include <QList>

class Product {
public:
    Product(const QString& cargo, const QString& country, int weight, double price,
            const QString& deliveryMethod, const QList<QString>& markers);
    bool saveToFile(const QString& filename) const;

private:
    QString m_cargo;
    QString m_country;
    int m_weight;
    double m_price;
    QString m_deliveryMethod;
    QList<QString> m_markers;
};
