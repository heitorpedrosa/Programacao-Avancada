/********************************************************************************
** Form generated from reading UI file 'incluirdvd.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCLUIRDVD_H
#define UI_INCLUIRDVD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_IncluirDVD
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_dvd;
    QLabel *label_nome;
    QLabel *label_preco;
    QLabel *label_duracao;
    QLineEdit *line_nome;
    QLineEdit *line_preco;
    QLineEdit *line_duracao;

    void setupUi(QDialog *IncluirDVD)
    {
        if (IncluirDVD->objectName().isEmpty())
            IncluirDVD->setObjectName(QString::fromUtf8("IncluirDVD"));
        IncluirDVD->resize(300, 200);
        IncluirDVD->setMinimumSize(QSize(300, 200));
        IncluirDVD->setMaximumSize(QSize(300, 200));
        buttonBox = new QDialogButtonBox(IncluirDVD);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-110, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_dvd = new QLabel(IncluirDVD);
        label_dvd->setObjectName(QString::fromUtf8("label_dvd"));
        label_dvd->setGeometry(QRect(100, 10, 111, 16));
        label_nome = new QLabel(IncluirDVD);
        label_nome->setObjectName(QString::fromUtf8("label_nome"));
        label_nome->setGeometry(QRect(30, 40, 47, 13));
        label_preco = new QLabel(IncluirDVD);
        label_preco->setObjectName(QString::fromUtf8("label_preco"));
        label_preco->setGeometry(QRect(30, 70, 47, 13));
        label_duracao = new QLabel(IncluirDVD);
        label_duracao->setObjectName(QString::fromUtf8("label_duracao"));
        label_duracao->setGeometry(QRect(30, 100, 47, 13));
        line_nome = new QLineEdit(IncluirDVD);
        line_nome->setObjectName(QString::fromUtf8("line_nome"));
        line_nome->setGeometry(QRect(100, 40, 180, 20));
        line_preco = new QLineEdit(IncluirDVD);
        line_preco->setObjectName(QString::fromUtf8("line_preco"));
        line_preco->setGeometry(QRect(100, 70, 180, 20));
        line_duracao = new QLineEdit(IncluirDVD);
        line_duracao->setObjectName(QString::fromUtf8("line_duracao"));
        line_duracao->setGeometry(QRect(100, 100, 180, 20));

        retranslateUi(IncluirDVD);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, IncluirDVD, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, IncluirDVD, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(IncluirDVD);
    } // setupUi

    void retranslateUi(QDialog *IncluirDVD)
    {
        IncluirDVD->setWindowTitle(QCoreApplication::translate("IncluirDVD", "Dialog", nullptr));
        label_dvd->setText(QCoreApplication::translate("IncluirDVD", "INCLUIR NOVO DVD", nullptr));
        label_nome->setText(QCoreApplication::translate("IncluirDVD", "Nome:", nullptr));
        label_preco->setText(QCoreApplication::translate("IncluirDVD", "Preco:", nullptr));
        label_duracao->setText(QCoreApplication::translate("IncluirDVD", "Duracao:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IncluirDVD: public Ui_IncluirDVD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCLUIRDVD_H
