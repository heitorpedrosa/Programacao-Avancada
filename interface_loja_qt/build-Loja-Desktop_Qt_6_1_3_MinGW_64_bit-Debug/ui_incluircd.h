/********************************************************************************
** Form generated from reading UI file 'incluircd.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCLUIRCD_H
#define UI_INCLUIRCD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_IncluirCD
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_cd;
    QLabel *label_nome;
    QLabel *label_preco;
    QLabel *label_numfaixas;
    QLineEdit *line_nome;
    QLineEdit *line_preco;
    QLineEdit *line_numfaixas;

    void setupUi(QDialog *IncluirCD)
    {
        if (IncluirCD->objectName().isEmpty())
            IncluirCD->setObjectName(QString::fromUtf8("IncluirCD"));
        IncluirCD->resize(300, 200);
        IncluirCD->setMinimumSize(QSize(300, 200));
        IncluirCD->setMaximumSize(QSize(300, 200));
        buttonBox = new QDialogButtonBox(IncluirCD);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-110, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_cd = new QLabel(IncluirCD);
        label_cd->setObjectName(QString::fromUtf8("label_cd"));
        label_cd->setGeometry(QRect(100, 10, 101, 16));
        label_nome = new QLabel(IncluirCD);
        label_nome->setObjectName(QString::fromUtf8("label_nome"));
        label_nome->setGeometry(QRect(30, 40, 47, 13));
        label_preco = new QLabel(IncluirCD);
        label_preco->setObjectName(QString::fromUtf8("label_preco"));
        label_preco->setGeometry(QRect(30, 70, 47, 13));
        label_numfaixas = new QLabel(IncluirCD);
        label_numfaixas->setObjectName(QString::fromUtf8("label_numfaixas"));
        label_numfaixas->setGeometry(QRect(30, 100, 51, 16));
        line_nome = new QLineEdit(IncluirCD);
        line_nome->setObjectName(QString::fromUtf8("line_nome"));
        line_nome->setGeometry(QRect(100, 40, 180, 20));
        line_preco = new QLineEdit(IncluirCD);
        line_preco->setObjectName(QString::fromUtf8("line_preco"));
        line_preco->setGeometry(QRect(100, 70, 180, 20));
        line_numfaixas = new QLineEdit(IncluirCD);
        line_numfaixas->setObjectName(QString::fromUtf8("line_numfaixas"));
        line_numfaixas->setGeometry(QRect(100, 100, 180, 20));

        retranslateUi(IncluirCD);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, IncluirCD, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, IncluirCD, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(IncluirCD);
    } // setupUi

    void retranslateUi(QDialog *IncluirCD)
    {
        IncluirCD->setWindowTitle(QCoreApplication::translate("IncluirCD", "Dialog", nullptr));
        label_cd->setText(QCoreApplication::translate("IncluirCD", "INCLUIR NOVO CD", nullptr));
        label_nome->setText(QCoreApplication::translate("IncluirCD", "Nome:", nullptr));
        label_preco->setText(QCoreApplication::translate("IncluirCD", "Preco:", nullptr));
        label_numfaixas->setText(QCoreApplication::translate("IncluirCD", "N\302\260 faixas:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IncluirCD: public Ui_IncluirCD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCLUIRCD_H
