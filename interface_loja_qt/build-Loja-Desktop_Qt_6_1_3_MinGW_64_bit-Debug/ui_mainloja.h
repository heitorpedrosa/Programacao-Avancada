/********************************************************************************
** Form generated from reading UI file 'mainloja.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINLOJA_H
#define UI_MAINLOJA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainLoja
{
public:
    QAction *actionLer;
    QAction *actionSalvar;
    QAction *actionSair;
    QAction *actionIncluir_Livro;
    QAction *actionIncluir_CD;
    QAction *actionIncluir_DVD;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_livro;
    QTableWidget *tabela_livro;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_cd;
    QTableWidget *tabela_cd;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_dvd;
    QTableWidget *tabela_dvd;
    QMenuBar *menubar;
    QMenu *menuArquivo;
    QMenu *menuItem;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainLoja)
    {
        if (MainLoja->objectName().isEmpty())
            MainLoja->setObjectName(QString::fromUtf8("MainLoja"));
        MainLoja->resize(1000, 600);
        MainLoja->setMinimumSize(QSize(1000, 600));
        MainLoja->setMaximumSize(QSize(1000, 600));
        actionLer = new QAction(MainLoja);
        actionLer->setObjectName(QString::fromUtf8("actionLer"));
        actionSalvar = new QAction(MainLoja);
        actionSalvar->setObjectName(QString::fromUtf8("actionSalvar"));
        actionSair = new QAction(MainLoja);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        actionIncluir_Livro = new QAction(MainLoja);
        actionIncluir_Livro->setObjectName(QString::fromUtf8("actionIncluir_Livro"));
        actionIncluir_CD = new QAction(MainLoja);
        actionIncluir_CD->setObjectName(QString::fromUtf8("actionIncluir_CD"));
        actionIncluir_DVD = new QAction(MainLoja);
        actionIncluir_DVD->setObjectName(QString::fromUtf8("actionIncluir_DVD"));
        centralwidget = new QWidget(MainLoja);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_livro = new QLabel(centralwidget);
        label_livro->setObjectName(QString::fromUtf8("label_livro"));
        label_livro->setEnabled(true);
        label_livro->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(label_livro);

        tabela_livro = new QTableWidget(centralwidget);
        if (tabela_livro->columnCount() < 3)
            tabela_livro->setColumnCount(3);
        tabela_livro->setObjectName(QString::fromUtf8("tabela_livro"));
        tabela_livro->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tabela_livro->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tabela_livro->setTabKeyNavigation(false);
        tabela_livro->setProperty("showDropIndicator", QVariant(true));
        tabela_livro->setSelectionMode(QAbstractItemView::SingleSelection);
        tabela_livro->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabela_livro->setColumnCount(3);
        tabela_livro->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tabela_livro);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_cd = new QLabel(centralwidget);
        label_cd->setObjectName(QString::fromUtf8("label_cd"));

        verticalLayout_2->addWidget(label_cd);

        tabela_cd = new QTableWidget(centralwidget);
        if (tabela_cd->columnCount() < 3)
            tabela_cd->setColumnCount(3);
        tabela_cd->setObjectName(QString::fromUtf8("tabela_cd"));
        tabela_cd->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tabela_cd->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tabela_cd->setTabKeyNavigation(false);
        tabela_cd->setSelectionMode(QAbstractItemView::SingleSelection);
        tabela_cd->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabela_cd->setColumnCount(3);
        tabela_cd->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tabela_cd);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_dvd = new QLabel(centralwidget);
        label_dvd->setObjectName(QString::fromUtf8("label_dvd"));

        verticalLayout_3->addWidget(label_dvd);

        tabela_dvd = new QTableWidget(centralwidget);
        if (tabela_dvd->columnCount() < 3)
            tabela_dvd->setColumnCount(3);
        tabela_dvd->setObjectName(QString::fromUtf8("tabela_dvd"));
        tabela_dvd->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tabela_dvd->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tabela_dvd->setTabKeyNavigation(false);
        tabela_dvd->setSelectionMode(QAbstractItemView::SingleSelection);
        tabela_dvd->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabela_dvd->setColumnCount(3);
        tabela_dvd->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(tabela_dvd);


        horizontalLayout->addLayout(verticalLayout_3);

        MainLoja->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainLoja);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        menuArquivo = new QMenu(menubar);
        menuArquivo->setObjectName(QString::fromUtf8("menuArquivo"));
        menuItem = new QMenu(menubar);
        menuItem->setObjectName(QString::fromUtf8("menuItem"));
        MainLoja->setMenuBar(menubar);
        statusbar = new QStatusBar(MainLoja);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainLoja->setStatusBar(statusbar);

        menubar->addAction(menuArquivo->menuAction());
        menubar->addAction(menuItem->menuAction());
        menuArquivo->addAction(actionLer);
        menuArquivo->addAction(actionSalvar);
        menuArquivo->addSeparator();
        menuArquivo->addAction(actionSair);
        menuItem->addAction(actionIncluir_Livro);
        menuItem->addAction(actionIncluir_CD);
        menuItem->addAction(actionIncluir_DVD);

        retranslateUi(MainLoja);

        QMetaObject::connectSlotsByName(MainLoja);
    } // setupUi

    void retranslateUi(QMainWindow *MainLoja)
    {
        MainLoja->setWindowTitle(QCoreApplication::translate("MainLoja", "Estoque em loja", nullptr));
        actionLer->setText(QCoreApplication::translate("MainLoja", "Ler...", nullptr));
        actionSalvar->setText(QCoreApplication::translate("MainLoja", "Salvar...", nullptr));
        actionSair->setText(QCoreApplication::translate("MainLoja", "Sair", nullptr));
        actionIncluir_Livro->setText(QCoreApplication::translate("MainLoja", "Incluir Livro...", nullptr));
        actionIncluir_CD->setText(QCoreApplication::translate("MainLoja", "Incluir CD...", nullptr));
        actionIncluir_DVD->setText(QCoreApplication::translate("MainLoja", "Incluir DVD...", nullptr));
        label_livro->setText(QCoreApplication::translate("MainLoja", "LIVROS", nullptr));
        label_cd->setText(QCoreApplication::translate("MainLoja", "CDS", nullptr));
        label_dvd->setText(QCoreApplication::translate("MainLoja", "DVDS", nullptr));
        menuArquivo->setTitle(QCoreApplication::translate("MainLoja", "Arquivo", nullptr));
        menuItem->setTitle(QCoreApplication::translate("MainLoja", "Item", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainLoja: public Ui_MainLoja {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINLOJA_H
