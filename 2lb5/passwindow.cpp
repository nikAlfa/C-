#include "passwindow.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>

PassWindow::PassWindow(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Пропуск");
    setFixedSize(300, 400);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Статичное изображение пропуска
    photoLabel = new QLabel(this);
    QPixmap pix(":/resources/pass_template.png");
    if (!pix.isNull()) {
        photoLabel->setPixmap(pix.scaled(200, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        photoLabel->setText("[Фото]");
    }
    photoLabel->setAlignment(Qt::AlignCenter);

    nameLabel = new QLabel(this);
    nameLabel->setAlignment(Qt::AlignCenter);
    birthLabel = new QLabel(this);
    birthLabel->setAlignment(Qt::AlignCenter);

    printButton = new QPushButton("Печать", this);
    cancelButton = new QPushButton("Отмена", this);

    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addWidget(printButton);
    btnLayout->addWidget(cancelButton);

    mainLayout->addWidget(photoLabel);
    mainLayout->addWidget(nameLabel);
    mainLayout->addWidget(birthLabel);
    mainLayout->addStretch();
    mainLayout->addLayout(btnLayout);

    connect(printButton, &QPushButton::clicked, this, &PassWindow::onPrint);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

void PassWindow::setInfo(const QString& arg1, const QString& arg2, const QString& arg3, const Date& birth) {
    QString displayName;
    // Для RuP: arg1=Фамилия, arg2=Имя, arg3=Отчество
    // Для AmP: arg1=Имя, arg2=Второе имя, arg3=Фамилия
    // Формируем строку в порядке "Фамилия Имя Отчество" (или "Имя Второе Фамилия" для AmP)
    if (!arg3.isEmpty() && arg3 != "-")
        displayName = arg1 + " " + arg2 + " " + arg3;
    else
        displayName = arg1 + " " + arg2;

    nameLabel->setText(displayName);
    birthLabel->setText("Дата рождения: " + birth.toString());
}

void PassWindow::onPrint() {
    emit personRemoved();
    accept();
}
