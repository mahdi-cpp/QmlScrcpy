/********************************************************************************
** Form generated from reading UI file 'toolform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLFORM_H
#define UI_TOOLFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolForm
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *groupControlBtn;
    QPushButton *fullScreenBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *expandNotifyBtn;
    QPushButton *touchBtn;
    QPushButton *openScreenBtn;
    QPushButton *closeScreenBtn;
    QPushButton *powerBtn;
    QPushButton *volumeUpBtn;
    QPushButton *volumeDownBtn;
    QPushButton *appSwitchBtn;
    QPushButton *menuBtn;
    QPushButton *homeBtn;
    QPushButton *returnBtn;
    QPushButton *screenShotBtn;

    void setupUi(QWidget *ToolForm)
    {
        if (ToolForm->objectName().isEmpty())
            ToolForm->setObjectName(QStringLiteral("ToolForm"));
        ToolForm->resize(63, 537);
        ToolForm->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(ToolForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 30, -1, -1);
        groupControlBtn = new QPushButton(ToolForm);
        groupControlBtn->setObjectName(QStringLiteral("groupControlBtn"));

        verticalLayout->addWidget(groupControlBtn);

        fullScreenBtn = new QPushButton(ToolForm);
        fullScreenBtn->setObjectName(QStringLiteral("fullScreenBtn"));

        verticalLayout->addWidget(fullScreenBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        expandNotifyBtn = new QPushButton(ToolForm);
        expandNotifyBtn->setObjectName(QStringLiteral("expandNotifyBtn"));

        verticalLayout->addWidget(expandNotifyBtn);

        touchBtn = new QPushButton(ToolForm);
        touchBtn->setObjectName(QStringLiteral("touchBtn"));

        verticalLayout->addWidget(touchBtn);

        openScreenBtn = new QPushButton(ToolForm);
        openScreenBtn->setObjectName(QStringLiteral("openScreenBtn"));

        verticalLayout->addWidget(openScreenBtn);

        closeScreenBtn = new QPushButton(ToolForm);
        closeScreenBtn->setObjectName(QStringLiteral("closeScreenBtn"));

        verticalLayout->addWidget(closeScreenBtn);

        powerBtn = new QPushButton(ToolForm);
        powerBtn->setObjectName(QStringLiteral("powerBtn"));

        verticalLayout->addWidget(powerBtn);

        volumeUpBtn = new QPushButton(ToolForm);
        volumeUpBtn->setObjectName(QStringLiteral("volumeUpBtn"));

        verticalLayout->addWidget(volumeUpBtn);

        volumeDownBtn = new QPushButton(ToolForm);
        volumeDownBtn->setObjectName(QStringLiteral("volumeDownBtn"));

        verticalLayout->addWidget(volumeDownBtn);

        appSwitchBtn = new QPushButton(ToolForm);
        appSwitchBtn->setObjectName(QStringLiteral("appSwitchBtn"));

        verticalLayout->addWidget(appSwitchBtn);

        menuBtn = new QPushButton(ToolForm);
        menuBtn->setObjectName(QStringLiteral("menuBtn"));

        verticalLayout->addWidget(menuBtn);

        homeBtn = new QPushButton(ToolForm);
        homeBtn->setObjectName(QStringLiteral("homeBtn"));

        verticalLayout->addWidget(homeBtn);

        returnBtn = new QPushButton(ToolForm);
        returnBtn->setObjectName(QStringLiteral("returnBtn"));

        verticalLayout->addWidget(returnBtn);

        screenShotBtn = new QPushButton(ToolForm);
        screenShotBtn->setObjectName(QStringLiteral("screenShotBtn"));

        verticalLayout->addWidget(screenShotBtn);


        retranslateUi(ToolForm);

        QMetaObject::connectSlotsByName(ToolForm);
    } // setupUi

    void retranslateUi(QWidget *ToolForm)
    {
        ToolForm->setWindowTitle(QApplication::translate("ToolForm", "Tool", nullptr));
#ifndef QT_NO_TOOLTIP
        groupControlBtn->setToolTip(QApplication::translate("ToolForm", "group control", nullptr));
#endif // QT_NO_TOOLTIP
        groupControlBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        fullScreenBtn->setToolTip(QApplication::translate("ToolForm", "full screen", nullptr));
#endif // QT_NO_TOOLTIP
        fullScreenBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        expandNotifyBtn->setToolTip(QApplication::translate("ToolForm", "expand notify", nullptr));
#endif // QT_NO_TOOLTIP
        expandNotifyBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        touchBtn->setToolTip(QApplication::translate("ToolForm", "touch switch", nullptr));
#endif // QT_NO_TOOLTIP
        touchBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        openScreenBtn->setToolTip(QApplication::translate("ToolForm", "open screen", nullptr));
#endif // QT_NO_TOOLTIP
        openScreenBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        closeScreenBtn->setToolTip(QApplication::translate("ToolForm", "close screen", nullptr));
#endif // QT_NO_TOOLTIP
        closeScreenBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        powerBtn->setToolTip(QApplication::translate("ToolForm", "power", nullptr));
#endif // QT_NO_TOOLTIP
        powerBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        volumeUpBtn->setToolTip(QApplication::translate("ToolForm", "volume up", nullptr));
#endif // QT_NO_TOOLTIP
        volumeUpBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        volumeDownBtn->setToolTip(QApplication::translate("ToolForm", "volume down", nullptr));
#endif // QT_NO_TOOLTIP
        volumeDownBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        appSwitchBtn->setToolTip(QApplication::translate("ToolForm", "app switch", nullptr));
#endif // QT_NO_TOOLTIP
        appSwitchBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        menuBtn->setToolTip(QApplication::translate("ToolForm", "menu", nullptr));
#endif // QT_NO_TOOLTIP
        menuBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        homeBtn->setToolTip(QApplication::translate("ToolForm", "home", nullptr));
#endif // QT_NO_TOOLTIP
        homeBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        returnBtn->setToolTip(QApplication::translate("ToolForm", "return", nullptr));
#endif // QT_NO_TOOLTIP
        returnBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        screenShotBtn->setToolTip(QApplication::translate("ToolForm", "screen shot", nullptr));
#endif // QT_NO_TOOLTIP
        screenShotBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ToolForm: public Ui_ToolForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLFORM_H
