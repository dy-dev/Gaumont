/********************************************************************************
** Form generated from reading UI file 'GaumontMediaDisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUMONTMEDIADISPLAY_H
#define UI_GAUMONTMEDIADISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvideowidget.h"

QT_BEGIN_NAMESPACE

class Ui_QTMediaPlayerClass
{
public:
    QVideoWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *DisplayLayout;
    QWidget *waitingWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *Go;
    QPushButton *Go2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *InfosLabel;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *QTMediaPlayerClass)
    {
        if (QTMediaPlayerClass->objectName().isEmpty())
            QTMediaPlayerClass->setObjectName(QStringLiteral("QTMediaPlayerClass"));
        QTMediaPlayerClass->setWindowModality(Qt::WindowModal);
        QTMediaPlayerClass->resize(1920, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QTMediaPlayerClass->sizePolicy().hasHeightForWidth());
        QTMediaPlayerClass->setSizePolicy(sizePolicy);
        QTMediaPlayerClass->setContextMenuPolicy(Qt::NoContextMenu);
        QTMediaPlayerClass->setWindowTitle(QStringLiteral(""));
        QTMediaPlayerClass->setStyleSheet(QStringLiteral("background-image: url(:/QTWebServer/Medias/GaumontWelcome.png);"));
        QTMediaPlayerClass->setIconSize(QSize(0, 0));
        QTMediaPlayerClass->setAnimated(false);
        centralWidget = new QVideoWidget(QTMediaPlayerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        DisplayLayout = new QVBoxLayout();
        DisplayLayout->setSpacing(6);
        DisplayLayout->setObjectName(QStringLiteral("DisplayLayout"));
        DisplayLayout->setContentsMargins(10, 10, -1, -1);
        waitingWidget = new QWidget(centralWidget);
        waitingWidget->setObjectName(QStringLiteral("waitingWidget"));
        waitingWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(waitingWidget->sizePolicy().hasHeightForWidth());
        waitingWidget->setSizePolicy(sizePolicy);
        waitingWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(waitingWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 10, 10);
        Go = new QPushButton(waitingWidget);
        Go->setObjectName(QStringLiteral("Go"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Go->sizePolicy().hasHeightForWidth());
        Go->setSizePolicy(sizePolicy1);
        Go->setMinimumSize(QSize(0, 50));
        Go->setAutoFillBackground(false);
        Go->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        Go->setFlat(false);

        verticalLayout->addWidget(Go);

        Go2 = new QPushButton(waitingWidget);
        Go2->setObjectName(QStringLiteral("Go2"));
        Go2->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(Go2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, -1, -1, 0);
        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        InfosLabel = new QLabel(waitingWidget);
        InfosLabel->setObjectName(QStringLiteral("InfosLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri Light"));
        font.setPointSize(25);
        InfosLabel->setFont(font);
        InfosLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(InfosLabel);

        horizontalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        DisplayLayout->addWidget(waitingWidget);


        horizontalLayout->addLayout(DisplayLayout);

        QTMediaPlayerClass->setCentralWidget(centralWidget);

        retranslateUi(QTMediaPlayerClass);
        QObject::connect(Go, SIGNAL(clicked()), QTMediaPlayerClass, SLOT(plastronGo()));
        QObject::connect(Go2, SIGNAL(clicked()), QTMediaPlayerClass, SLOT(go2()));

        Go->setDefault(false);


        QMetaObject::connectSlotsByName(QTMediaPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTMediaPlayerClass)
    {
        Go->setText(QApplication::translate("QTMediaPlayerClass", "PushButton", Q_NULLPTR));
        Go2->setText(QApplication::translate("QTMediaPlayerClass", "PushButton", Q_NULLPTR));
        InfosLabel->setText(QApplication::translate("QTMediaPlayerClass", "No Signal Received Yet", Q_NULLPTR));
        Q_UNUSED(QTMediaPlayerClass);
    } // retranslateUi

};

namespace Ui {
    class QTMediaPlayerClass: public Ui_QTMediaPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUMONTMEDIADISPLAY_H
