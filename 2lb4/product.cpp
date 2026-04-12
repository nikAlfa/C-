#include "product.hpp"
#include <QFile>
#include <QTextStream>

Product::Product(const QString& cargo, const QString& country, int weight, double price,
                 const QString& deliveryMethod, const QList<QString>& markers)
    : m_cargo(cargo), m_country(country), m_weight(weight), m_price(price),
    m_deliveryMethod(deliveryMethod), m_markers(markers) {}

bool Product::saveToFile(const QString& filename) const {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << "Груз: " << m_cargo << "\n";
    out << "Страна: " << m_country << "\n";
    out << "Вес: " << m_weight << " кг\n";
    out << "Цена: " << m_price << " руб\n";
    out << "Способ доставки: " << m_deliveryMethod << "\n";
    out << "Маркеры: " << (m_markers.isEmpty() ? "нет" : m_markers.join(", ")) << "\n";
    out << "----------------------------------------\n";
    file.close();
    return true;
}
