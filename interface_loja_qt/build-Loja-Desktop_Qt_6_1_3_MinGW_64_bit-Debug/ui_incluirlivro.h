/********************************************************************************
** Form generated from reading UI file 'incluirlivro.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCLUIRLIVRO_H
#define UI_INCLUIRLIVRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_IncluirLivro
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_nome;
    QLabel *label_preco;
    QLabel *label_autor;
    QLineEdit *line_nome;
    QLineEdit *line_preco;
    QLineEdit *line_autor;
    QLabel *label_livro;

    void setupUi(QDialog *IncluirLivro)
    {
        if (IncluirLivro->objectName().isEmpty())
            IncluirLivro->setObjectName(QString::fromUtf8("IncluirLivro"));
        IncluirLivro->resize(300, 200);
        IncluirLivro->setMinimumSize(QSize(300, 200));
        IncluirLivro->setMaximumSize(QSize(300, 200));
        buttonBox = new QDialogButtonBox(IncluirLivro);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-110, 160, 341, 32));
        buttonBox->setMinimumSize(QSize(341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_nome = new QLabel(IncluirLivro);
        label_nome->setObjectName(QString::fromUtf8("label_nome"));
        label_nome->setGeometry(QRect(30, 40, 47, 13));
        label_preco = new QLabel(IncluirLivro);
        label_preco->setObjectName(QString::fromUtf8("label_preco"));
        label_preco->setGeometry(QRect(30, 70, 47, 13));
        label_autor = new QLabel(IncluirLivro);
        label_autor->setObjectName(QString::fromUtf8("label_autor"));
        label_autor->setGeometry(QRect(30, 100, 47, 13));
        line_nome = new QLineEdit(IncluirLivro);
        line_nome->setObjectName(QString::fromUtf8("line_nome"));
        line_nome->setGeometry(QRect(100, 40, 180, 20));
        line_preco = new QLineEdit(IncluirLivro);
        line_preco->setObjectName(QString::fromUtf8("line_preco"));
        line_preco->setGeometry(QRect(100, 70, 180, 20));
        line_autor = new QLineEdit(IncluirLivro);
        line_autor->setObjectName(QString::fromUtf8("line_autor"));
        line_autor->setGeometry(QRect(100, 100, 180, 20));
        label_livro = new QLabel(IncluirLivro);
        label_livro->setObjectName(QString::fromUtf8("label_livro"));
        label_livro->setGeometry(QRect(100, 10, 121, 16));
        label_livro->setMinimumSize(QSize(121, 16));

        retranslateUi(IncluirLivro);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, IncluirLivro, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, IncluirLivro, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(IncluirLivro);
    } // setupUi

    void retranslateUi(QDialog *IncluirLivro)
    {
        IncluirLivro->setWindowTitle(QCoreApplication::translate("IncluirLivro", "Dialog", nullptr));
        label_nome->setText(QCoreApplication::translate("IncluirLivro", "Nome:", nullptr));
        label_preco->setText(QCoreApplication::translate("IncluirLivro", "Preco:", nullptr));
        label_autor->setText(QCoreApplication::translate("IncluirLivro", "Autor:", nullptr));
        label_livro->setText(QCoreApplication::translate("IncluirLivro", "INCLUIR NOVO LIVRO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IncluirLivro: public Ui_IncluirLivro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCLUIRLIVRO_H
