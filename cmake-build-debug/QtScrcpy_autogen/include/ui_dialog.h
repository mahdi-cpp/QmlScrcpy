/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_11;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *useSingleModeCheck;
    QGroupBox *simpleGroupBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *wifiConnectBtn;
    QPushButton *usbConnectBtn;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_10;
    QCheckBox *autoUpdatecheckBox;
    QListWidget *connectedPhoneList;
    QGroupBox *adbGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLineEdit *adbCommandEdt;
    QPushButton *adbCommandBtn;
    QPushButton *stopAdbBtn;
    QPushButton *clearOut;
    QTextEdit *outEdit;
    QWidget *rightWidget;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *configGroupBox;
    QVBoxLayout *verticalLayout_3;
    QWidget *configWidget1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *bitRateEdit;
    QComboBox *bitRateBox;
    QLabel *label_4;
    QComboBox *maxSizeBox;
    QWidget *configWidget5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QComboBox *formatBox;
    QLabel *label_8;
    QComboBox *lockOrientationBox;
    QWidget *configWidget2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *recordPathEdt;
    QPushButton *selectRecordPathBtn;
    QWidget *configWidget4;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *gameBox;
    QPushButton *refreshGameScriptBtn;
    QPushButton *applyScriptBtn;
    QWidget *configWidget3;
    QGridLayout *gridLayout;
    QCheckBox *closeScreenCheck;
    QCheckBox *framelessCheck;
    QCheckBox *alwaysTopCheck;
    QCheckBox *notDisplayCheck;
    QCheckBox *useReverseCheck;
    QCheckBox *recordScreenCheck;
    QCheckBox *fpsCheck;
    QCheckBox *stayAwakeCheck;
    QGroupBox *usbGroupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *userNameEdt;
    QPushButton *updateNameBtn;
    QWidget *usbWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *serialBox;
    QPushButton *startServerBtn;
    QPushButton *stopServerBtn;
    QWidget *usbWidget2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *stopAllServerBtn;
    QPushButton *updateDevice;
    QPushButton *getIPBtn;
    QPushButton *startAdbdBtn;
    QWidget *usbWidget3;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *installSndcpyBtn;
    QPushButton *startAudioBtn;
    QPushButton *stopAudioBtn;
    QGroupBox *wirelessGroupBox;
    QHBoxLayout *horizontalLayout;
    QLineEdit *deviceIpEdt;
    QLabel *label;
    QLineEdit *devicePortEdt;
    QPushButton *wirelessConnectBtn;
    QPushButton *wirelessDisConnectBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1293, 454);
        Widget->setWindowTitle(QStringLiteral("QtScrcpy"));
        horizontalLayout_11 = new QHBoxLayout(Widget);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        leftWidget = new QWidget(Widget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftWidget->sizePolicy().hasHeightForWidth());
        leftWidget->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(leftWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        useSingleModeCheck = new QCheckBox(leftWidget);
        useSingleModeCheck->setObjectName(QStringLiteral("useSingleModeCheck"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(useSingleModeCheck->sizePolicy().hasHeightForWidth());
        useSingleModeCheck->setSizePolicy(sizePolicy1);
        useSingleModeCheck->setStyleSheet(QStringLiteral(""));
        useSingleModeCheck->setChecked(false);

        verticalLayout_5->addWidget(useSingleModeCheck);

        simpleGroupBox = new QGroupBox(leftWidget);
        simpleGroupBox->setObjectName(QStringLiteral("simpleGroupBox"));
        sizePolicy.setHeightForWidth(simpleGroupBox->sizePolicy().hasHeightForWidth());
        simpleGroupBox->setSizePolicy(sizePolicy);
        simpleGroupBox->setCheckable(false);
        verticalLayout_4 = new QVBoxLayout(simpleGroupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        wifiConnectBtn = new QPushButton(simpleGroupBox);
        wifiConnectBtn->setObjectName(QStringLiteral("wifiConnectBtn"));
        sizePolicy1.setHeightForWidth(wifiConnectBtn->sizePolicy().hasHeightForWidth());
        wifiConnectBtn->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(wifiConnectBtn);

        usbConnectBtn = new QPushButton(simpleGroupBox);
        usbConnectBtn->setObjectName(QStringLiteral("usbConnectBtn"));
        sizePolicy1.setHeightForWidth(usbConnectBtn->sizePolicy().hasHeightForWidth());
        usbConnectBtn->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(usbConnectBtn);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, 0, -1, -1);
        label_10 = new QLabel(simpleGroupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(label_10);

        autoUpdatecheckBox = new QCheckBox(simpleGroupBox);
        autoUpdatecheckBox->setObjectName(QStringLiteral("autoUpdatecheckBox"));
        sizePolicy.setHeightForWidth(autoUpdatecheckBox->sizePolicy().hasHeightForWidth());
        autoUpdatecheckBox->setSizePolicy(sizePolicy);
        autoUpdatecheckBox->setChecked(true);

        horizontalLayout_13->addWidget(autoUpdatecheckBox);


        verticalLayout_4->addLayout(horizontalLayout_13);

        connectedPhoneList = new QListWidget(simpleGroupBox);
        connectedPhoneList->setObjectName(QStringLiteral("connectedPhoneList"));
        sizePolicy.setHeightForWidth(connectedPhoneList->sizePolicy().hasHeightForWidth());
        connectedPhoneList->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(connectedPhoneList);


        verticalLayout_5->addWidget(simpleGroupBox);

        adbGroupBox = new QGroupBox(leftWidget);
        adbGroupBox->setObjectName(QStringLiteral("adbGroupBox"));
        sizePolicy1.setHeightForWidth(adbGroupBox->sizePolicy().hasHeightForWidth());
        adbGroupBox->setSizePolicy(sizePolicy1);
        adbGroupBox->setTitle(QStringLiteral("adb"));
        horizontalLayout_2 = new QHBoxLayout(adbGroupBox);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        label_7 = new QLabel(adbGroupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(label_7);

        adbCommandEdt = new QLineEdit(adbGroupBox);
        adbCommandEdt->setObjectName(QStringLiteral("adbCommandEdt"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(adbCommandEdt->sizePolicy().hasHeightForWidth());
        adbCommandEdt->setSizePolicy(sizePolicy3);
        adbCommandEdt->setText(QStringLiteral("devices"));

        horizontalLayout_2->addWidget(adbCommandEdt);

        adbCommandBtn = new QPushButton(adbGroupBox);
        adbCommandBtn->setObjectName(QStringLiteral("adbCommandBtn"));
        sizePolicy2.setHeightForWidth(adbCommandBtn->sizePolicy().hasHeightForWidth());
        adbCommandBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(adbCommandBtn);

        stopAdbBtn = new QPushButton(adbGroupBox);
        stopAdbBtn->setObjectName(QStringLiteral("stopAdbBtn"));
        sizePolicy2.setHeightForWidth(stopAdbBtn->sizePolicy().hasHeightForWidth());
        stopAdbBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(stopAdbBtn);

        clearOut = new QPushButton(adbGroupBox);
        clearOut->setObjectName(QStringLiteral("clearOut"));
        sizePolicy2.setHeightForWidth(clearOut->sizePolicy().hasHeightForWidth());
        clearOut->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(clearOut);


        verticalLayout_5->addWidget(adbGroupBox);

        outEdit = new QTextEdit(leftWidget);
        outEdit->setObjectName(QStringLiteral("outEdit"));
        sizePolicy.setHeightForWidth(outEdit->sizePolicy().hasHeightForWidth());
        outEdit->setSizePolicy(sizePolicy);
        outEdit->setFocusPolicy(Qt::ClickFocus);
        outEdit->setReadOnly(true);

        verticalLayout_5->addWidget(outEdit);


        horizontalLayout_11->addWidget(leftWidget);

        rightWidget = new QWidget(Widget);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        sizePolicy3.setHeightForWidth(rightWidget->sizePolicy().hasHeightForWidth());
        rightWidget->setSizePolicy(sizePolicy3);
        verticalLayout_6 = new QVBoxLayout(rightWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        configGroupBox = new QGroupBox(rightWidget);
        configGroupBox->setObjectName(QStringLiteral("configGroupBox"));
        sizePolicy.setHeightForWidth(configGroupBox->sizePolicy().hasHeightForWidth());
        configGroupBox->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(configGroupBox);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        configWidget1 = new QWidget(configGroupBox);
        configWidget1->setObjectName(QStringLiteral("configWidget1"));
        sizePolicy.setHeightForWidth(configWidget1->sizePolicy().hasHeightForWidth());
        configWidget1->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(configWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(configWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label_3);

        bitRateEdit = new QLineEdit(configWidget1);
        bitRateEdit->setObjectName(QStringLiteral("bitRateEdit"));
        sizePolicy.setHeightForWidth(bitRateEdit->sizePolicy().hasHeightForWidth());
        bitRateEdit->setSizePolicy(sizePolicy);
        bitRateEdit->setText(QStringLiteral("2"));

        horizontalLayout_5->addWidget(bitRateEdit);

        bitRateBox = new QComboBox(configWidget1);
        bitRateBox->addItem(QStringLiteral("Mbps"));
        bitRateBox->addItem(QStringLiteral("Kbps"));
        bitRateBox->setObjectName(QStringLiteral("bitRateBox"));
        sizePolicy2.setHeightForWidth(bitRateBox->sizePolicy().hasHeightForWidth());
        bitRateBox->setSizePolicy(sizePolicy2);
        bitRateBox->setCurrentText(QStringLiteral("Mbps"));

        horizontalLayout_5->addWidget(bitRateBox);

        label_4 = new QLabel(configWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label_4);

        maxSizeBox = new QComboBox(configWidget1);
        maxSizeBox->setObjectName(QStringLiteral("maxSizeBox"));
        sizePolicy.setHeightForWidth(maxSizeBox->sizePolicy().hasHeightForWidth());
        maxSizeBox->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(maxSizeBox);


        verticalLayout_3->addWidget(configWidget1);

        configWidget5 = new QWidget(configGroupBox);
        configWidget5->setObjectName(QStringLiteral("configWidget5"));
        sizePolicy.setHeightForWidth(configWidget5->sizePolicy().hasHeightForWidth());
        configWidget5->setSizePolicy(sizePolicy);
        horizontalLayout_7 = new QHBoxLayout(configWidget5);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(configWidget5);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(label_6);

        formatBox = new QComboBox(configWidget5);
        formatBox->setObjectName(QStringLiteral("formatBox"));
        sizePolicy.setHeightForWidth(formatBox->sizePolicy().hasHeightForWidth());
        formatBox->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(formatBox);

        label_8 = new QLabel(configWidget5);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(label_8);

        lockOrientationBox = new QComboBox(configWidget5);
        lockOrientationBox->setObjectName(QStringLiteral("lockOrientationBox"));
        sizePolicy.setHeightForWidth(lockOrientationBox->sizePolicy().hasHeightForWidth());
        lockOrientationBox->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(lockOrientationBox);


        verticalLayout_3->addWidget(configWidget5);

        configWidget2 = new QWidget(configGroupBox);
        configWidget2->setObjectName(QStringLiteral("configWidget2"));
        sizePolicy.setHeightForWidth(configWidget2->sizePolicy().hasHeightForWidth());
        configWidget2->setSizePolicy(sizePolicy);
        horizontalLayout_6 = new QHBoxLayout(configWidget2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(configWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_5);

        recordPathEdt = new QLineEdit(configWidget2);
        recordPathEdt->setObjectName(QStringLiteral("recordPathEdt"));
        sizePolicy3.setHeightForWidth(recordPathEdt->sizePolicy().hasHeightForWidth());
        recordPathEdt->setSizePolicy(sizePolicy3);
        recordPathEdt->setReadOnly(true);

        horizontalLayout_6->addWidget(recordPathEdt);

        selectRecordPathBtn = new QPushButton(configWidget2);
        selectRecordPathBtn->setObjectName(QStringLiteral("selectRecordPathBtn"));
        sizePolicy.setHeightForWidth(selectRecordPathBtn->sizePolicy().hasHeightForWidth());
        selectRecordPathBtn->setSizePolicy(sizePolicy);
        selectRecordPathBtn->setAutoDefault(false);

        horizontalLayout_6->addWidget(selectRecordPathBtn);


        verticalLayout_3->addWidget(configWidget2);

        configWidget4 = new QWidget(configGroupBox);
        configWidget4->setObjectName(QStringLiteral("configWidget4"));
        sizePolicy.setHeightForWidth(configWidget4->sizePolicy().hasHeightForWidth());
        configWidget4->setSizePolicy(sizePolicy);
        horizontalLayout_8 = new QHBoxLayout(configWidget4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        gameBox = new QComboBox(configWidget4);
        gameBox->setObjectName(QStringLiteral("gameBox"));
        sizePolicy3.setHeightForWidth(gameBox->sizePolicy().hasHeightForWidth());
        gameBox->setSizePolicy(sizePolicy3);

        horizontalLayout_8->addWidget(gameBox);

        refreshGameScriptBtn = new QPushButton(configWidget4);
        refreshGameScriptBtn->setObjectName(QStringLiteral("refreshGameScriptBtn"));
        sizePolicy.setHeightForWidth(refreshGameScriptBtn->sizePolicy().hasHeightForWidth());
        refreshGameScriptBtn->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(refreshGameScriptBtn);

        applyScriptBtn = new QPushButton(configWidget4);
        applyScriptBtn->setObjectName(QStringLiteral("applyScriptBtn"));
        sizePolicy.setHeightForWidth(applyScriptBtn->sizePolicy().hasHeightForWidth());
        applyScriptBtn->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(applyScriptBtn);


        verticalLayout_3->addWidget(configWidget4);

        configWidget3 = new QWidget(configGroupBox);
        configWidget3->setObjectName(QStringLiteral("configWidget3"));
        sizePolicy.setHeightForWidth(configWidget3->sizePolicy().hasHeightForWidth());
        configWidget3->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(configWidget3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        closeScreenCheck = new QCheckBox(configWidget3);
        closeScreenCheck->setObjectName(QStringLiteral("closeScreenCheck"));
        sizePolicy.setHeightForWidth(closeScreenCheck->sizePolicy().hasHeightForWidth());
        closeScreenCheck->setSizePolicy(sizePolicy);

        gridLayout->addWidget(closeScreenCheck, 1, 1, 1, 1);

        framelessCheck = new QCheckBox(configWidget3);
        framelessCheck->setObjectName(QStringLiteral("framelessCheck"));
        sizePolicy.setHeightForWidth(framelessCheck->sizePolicy().hasHeightForWidth());
        framelessCheck->setSizePolicy(sizePolicy);

        gridLayout->addWidget(framelessCheck, 1, 3, 1, 1);

        alwaysTopCheck = new QCheckBox(configWidget3);
        alwaysTopCheck->setObjectName(QStringLiteral("alwaysTopCheck"));
        sizePolicy.setHeightForWidth(alwaysTopCheck->sizePolicy().hasHeightForWidth());
        alwaysTopCheck->setSizePolicy(sizePolicy);
        alwaysTopCheck->setChecked(false);

        gridLayout->addWidget(alwaysTopCheck, 1, 0, 1, 1);

        notDisplayCheck = new QCheckBox(configWidget3);
        notDisplayCheck->setObjectName(QStringLiteral("notDisplayCheck"));
        sizePolicy.setHeightForWidth(notDisplayCheck->sizePolicy().hasHeightForWidth());
        notDisplayCheck->setSizePolicy(sizePolicy);
        notDisplayCheck->setCheckable(false);

        gridLayout->addWidget(notDisplayCheck, 0, 1, 1, 1);

        useReverseCheck = new QCheckBox(configWidget3);
        useReverseCheck->setObjectName(QStringLiteral("useReverseCheck"));
        sizePolicy.setHeightForWidth(useReverseCheck->sizePolicy().hasHeightForWidth());
        useReverseCheck->setSizePolicy(sizePolicy);
        useReverseCheck->setChecked(true);

        gridLayout->addWidget(useReverseCheck, 0, 3, 1, 1);

        recordScreenCheck = new QCheckBox(configWidget3);
        recordScreenCheck->setObjectName(QStringLiteral("recordScreenCheck"));
        sizePolicy.setHeightForWidth(recordScreenCheck->sizePolicy().hasHeightForWidth());
        recordScreenCheck->setSizePolicy(sizePolicy);

        gridLayout->addWidget(recordScreenCheck, 0, 0, 1, 1);

        fpsCheck = new QCheckBox(configWidget3);
        fpsCheck->setObjectName(QStringLiteral("fpsCheck"));
        sizePolicy.setHeightForWidth(fpsCheck->sizePolicy().hasHeightForWidth());
        fpsCheck->setSizePolicy(sizePolicy);

        gridLayout->addWidget(fpsCheck, 0, 4, 1, 1);

        stayAwakeCheck = new QCheckBox(configWidget3);
        stayAwakeCheck->setObjectName(QStringLiteral("stayAwakeCheck"));
        sizePolicy.setHeightForWidth(stayAwakeCheck->sizePolicy().hasHeightForWidth());
        stayAwakeCheck->setSizePolicy(sizePolicy);

        gridLayout->addWidget(stayAwakeCheck, 1, 4, 1, 1);


        verticalLayout_3->addWidget(configWidget3);


        verticalLayout_6->addWidget(configGroupBox);

        usbGroupBox = new QGroupBox(rightWidget);
        usbGroupBox->setObjectName(QStringLiteral("usbGroupBox"));
        sizePolicy.setHeightForWidth(usbGroupBox->sizePolicy().hasHeightForWidth());
        usbGroupBox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(usbGroupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(usbGroupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(label_9);

        userNameEdt = new QLineEdit(usbGroupBox);
        userNameEdt->setObjectName(QStringLiteral("userNameEdt"));
        sizePolicy3.setHeightForWidth(userNameEdt->sizePolicy().hasHeightForWidth());
        userNameEdt->setSizePolicy(sizePolicy3);

        horizontalLayout_10->addWidget(userNameEdt);

        updateNameBtn = new QPushButton(usbGroupBox);
        updateNameBtn->setObjectName(QStringLiteral("updateNameBtn"));
        sizePolicy.setHeightForWidth(updateNameBtn->sizePolicy().hasHeightForWidth());
        updateNameBtn->setSizePolicy(sizePolicy);
        updateNameBtn->setAutoDefault(false);

        horizontalLayout_10->addWidget(updateNameBtn);


        verticalLayout->addLayout(horizontalLayout_10);

        usbWidget1 = new QWidget(usbGroupBox);
        usbWidget1->setObjectName(QStringLiteral("usbWidget1"));
        sizePolicy.setHeightForWidth(usbWidget1->sizePolicy().hasHeightForWidth());
        usbWidget1->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(usbWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(usbWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_2);

        serialBox = new QComboBox(usbWidget1);
        serialBox->setObjectName(QStringLiteral("serialBox"));
        sizePolicy.setHeightForWidth(serialBox->sizePolicy().hasHeightForWidth());
        serialBox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(serialBox);

        startServerBtn = new QPushButton(usbWidget1);
        startServerBtn->setObjectName(QStringLiteral("startServerBtn"));
        sizePolicy.setHeightForWidth(startServerBtn->sizePolicy().hasHeightForWidth());
        startServerBtn->setSizePolicy(sizePolicy);
        startServerBtn->setAutoDefault(false);

        horizontalLayout_3->addWidget(startServerBtn);

        stopServerBtn = new QPushButton(usbWidget1);
        stopServerBtn->setObjectName(QStringLiteral("stopServerBtn"));
        sizePolicy.setHeightForWidth(stopServerBtn->sizePolicy().hasHeightForWidth());
        stopServerBtn->setSizePolicy(sizePolicy);
        stopServerBtn->setAutoDefault(false);

        horizontalLayout_3->addWidget(stopServerBtn);


        verticalLayout->addWidget(usbWidget1);

        usbWidget2 = new QWidget(usbGroupBox);
        usbWidget2->setObjectName(QStringLiteral("usbWidget2"));
        sizePolicy.setHeightForWidth(usbWidget2->sizePolicy().hasHeightForWidth());
        usbWidget2->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(usbWidget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        stopAllServerBtn = new QPushButton(usbWidget2);
        stopAllServerBtn->setObjectName(QStringLiteral("stopAllServerBtn"));
        sizePolicy.setHeightForWidth(stopAllServerBtn->sizePolicy().hasHeightForWidth());
        stopAllServerBtn->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(stopAllServerBtn);

        updateDevice = new QPushButton(usbWidget2);
        updateDevice->setObjectName(QStringLiteral("updateDevice"));
        sizePolicy.setHeightForWidth(updateDevice->sizePolicy().hasHeightForWidth());
        updateDevice->setSizePolicy(sizePolicy);
        updateDevice->setAutoDefault(false);

        horizontalLayout_4->addWidget(updateDevice);

        getIPBtn = new QPushButton(usbWidget2);
        getIPBtn->setObjectName(QStringLiteral("getIPBtn"));
        sizePolicy.setHeightForWidth(getIPBtn->sizePolicy().hasHeightForWidth());
        getIPBtn->setSizePolicy(sizePolicy);
        getIPBtn->setAutoDefault(false);

        horizontalLayout_4->addWidget(getIPBtn);

        startAdbdBtn = new QPushButton(usbWidget2);
        startAdbdBtn->setObjectName(QStringLiteral("startAdbdBtn"));
        sizePolicy.setHeightForWidth(startAdbdBtn->sizePolicy().hasHeightForWidth());
        startAdbdBtn->setSizePolicy(sizePolicy);
        startAdbdBtn->setAutoDefault(false);

        horizontalLayout_4->addWidget(startAdbdBtn);


        verticalLayout->addWidget(usbWidget2);

        usbWidget3 = new QWidget(usbGroupBox);
        usbWidget3->setObjectName(QStringLiteral("usbWidget3"));
        horizontalLayout_12 = new QHBoxLayout(usbWidget3);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        installSndcpyBtn = new QPushButton(usbWidget3);
        installSndcpyBtn->setObjectName(QStringLiteral("installSndcpyBtn"));
        sizePolicy.setHeightForWidth(installSndcpyBtn->sizePolicy().hasHeightForWidth());
        installSndcpyBtn->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(installSndcpyBtn);

        startAudioBtn = new QPushButton(usbWidget3);
        startAudioBtn->setObjectName(QStringLiteral("startAudioBtn"));
        sizePolicy.setHeightForWidth(startAudioBtn->sizePolicy().hasHeightForWidth());
        startAudioBtn->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(startAudioBtn);

        stopAudioBtn = new QPushButton(usbWidget3);
        stopAudioBtn->setObjectName(QStringLiteral("stopAudioBtn"));
        sizePolicy.setHeightForWidth(stopAudioBtn->sizePolicy().hasHeightForWidth());
        stopAudioBtn->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(stopAudioBtn);


        verticalLayout->addWidget(usbWidget3);


        verticalLayout_6->addWidget(usbGroupBox);

        wirelessGroupBox = new QGroupBox(rightWidget);
        wirelessGroupBox->setObjectName(QStringLiteral("wirelessGroupBox"));
        sizePolicy.setHeightForWidth(wirelessGroupBox->sizePolicy().hasHeightForWidth());
        wirelessGroupBox->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(wirelessGroupBox);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        deviceIpEdt = new QLineEdit(wirelessGroupBox);
        deviceIpEdt->setObjectName(QStringLiteral("deviceIpEdt"));
        sizePolicy3.setHeightForWidth(deviceIpEdt->sizePolicy().hasHeightForWidth());
        deviceIpEdt->setSizePolicy(sizePolicy3);
        deviceIpEdt->setMaxLength(128);
        deviceIpEdt->setPlaceholderText(QStringLiteral("192.168.0.1"));

        horizontalLayout->addWidget(deviceIpEdt);

        label = new QLabel(wirelessGroupBox);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setText(QStringLiteral(":"));

        horizontalLayout->addWidget(label);

        devicePortEdt = new QLineEdit(wirelessGroupBox);
        devicePortEdt->setObjectName(QStringLiteral("devicePortEdt"));
        sizePolicy2.setHeightForWidth(devicePortEdt->sizePolicy().hasHeightForWidth());
        devicePortEdt->setSizePolicy(sizePolicy2);
        devicePortEdt->setMaxLength(6);
        devicePortEdt->setPlaceholderText(QStringLiteral("5555"));

        horizontalLayout->addWidget(devicePortEdt);

        wirelessConnectBtn = new QPushButton(wirelessGroupBox);
        wirelessConnectBtn->setObjectName(QStringLiteral("wirelessConnectBtn"));
        sizePolicy.setHeightForWidth(wirelessConnectBtn->sizePolicy().hasHeightForWidth());
        wirelessConnectBtn->setSizePolicy(sizePolicy);
        wirelessConnectBtn->setAutoDefault(false);

        horizontalLayout->addWidget(wirelessConnectBtn);

        wirelessDisConnectBtn = new QPushButton(wirelessGroupBox);
        wirelessDisConnectBtn->setObjectName(QStringLiteral("wirelessDisConnectBtn"));
        sizePolicy.setHeightForWidth(wirelessDisConnectBtn->sizePolicy().hasHeightForWidth());
        wirelessDisConnectBtn->setSizePolicy(sizePolicy);
        wirelessDisConnectBtn->setAutoDefault(false);

        horizontalLayout->addWidget(wirelessDisConnectBtn);


        verticalLayout_6->addWidget(wirelessGroupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        horizontalLayout_11->addWidget(rightWidget);

#ifndef QT_NO_SHORTCUT
        label_7->setBuddy(adbCommandEdt);
        label_5->setBuddy(recordPathEdt);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(deviceIpEdt, devicePortEdt);
        QWidget::setTabOrder(devicePortEdt, wirelessConnectBtn);
        QWidget::setTabOrder(wirelessConnectBtn, wirelessDisConnectBtn);
        QWidget::setTabOrder(wirelessDisConnectBtn, adbCommandEdt);
        QWidget::setTabOrder(adbCommandEdt, adbCommandBtn);
        QWidget::setTabOrder(adbCommandBtn, stopAdbBtn);
        QWidget::setTabOrder(stopAdbBtn, clearOut);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        useSingleModeCheck->setText(QApplication::translate("Widget", "Use Simple Mode", nullptr));
        simpleGroupBox->setTitle(QApplication::translate("Widget", "Simple Mode", nullptr));
        wifiConnectBtn->setText(QApplication::translate("Widget", "WIFI Connect", nullptr));
        usbConnectBtn->setText(QApplication::translate("Widget", "USB Connect", nullptr));
        label_10->setText(QApplication::translate("Widget", "Double click to connect:", nullptr));
        autoUpdatecheckBox->setText(QApplication::translate("Widget", "auto update", nullptr));
        label_7->setText(QApplication::translate("Widget", "adb command:", nullptr));
        adbCommandBtn->setText(QApplication::translate("Widget", "execute", nullptr));
        stopAdbBtn->setText(QApplication::translate("Widget", "terminate", nullptr));
        clearOut->setText(QApplication::translate("Widget", "clear", nullptr));
        outEdit->setDocumentTitle(QString());
        configGroupBox->setTitle(QApplication::translate("Widget", "Start Config", nullptr));
        label_3->setText(QApplication::translate("Widget", "bit rate:", nullptr));

#ifndef QT_NO_TOOLTIP
        bitRateBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("Widget", "max size:", nullptr));
#ifndef QT_NO_TOOLTIP
        maxSizeBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("Widget", "record format\357\274\232", nullptr));
        label_8->setText(QApplication::translate("Widget", "lock orientation:", nullptr));
        label_5->setText(QApplication::translate("Widget", "record save path:", nullptr));
        selectRecordPathBtn->setText(QApplication::translate("Widget", "select path", nullptr));
        refreshGameScriptBtn->setText(QApplication::translate("Widget", "refresh script", nullptr));
        applyScriptBtn->setText(QApplication::translate("Widget", "apply", nullptr));
        closeScreenCheck->setText(QApplication::translate("Widget", "screen-off", nullptr));
        framelessCheck->setText(QApplication::translate("Widget", "frameless", nullptr));
        alwaysTopCheck->setText(QApplication::translate("Widget", "always on top", nullptr));
        notDisplayCheck->setText(QApplication::translate("Widget", "background record", nullptr));
        useReverseCheck->setText(QApplication::translate("Widget", "reverse connection", nullptr));
        recordScreenCheck->setText(QApplication::translate("Widget", "record screen", nullptr));
        fpsCheck->setText(QApplication::translate("Widget", "show fps", nullptr));
        stayAwakeCheck->setText(QApplication::translate("Widget", "stay awake", nullptr));
        usbGroupBox->setTitle(QApplication::translate("Widget", "USB line", nullptr));
        label_9->setText(QApplication::translate("Widget", "device name:", nullptr));
        updateNameBtn->setText(QApplication::translate("Widget", "update name", nullptr));
        label_2->setText(QApplication::translate("Widget", "device serial:", nullptr));
        startServerBtn->setText(QApplication::translate("Widget", "start server", nullptr));
        stopServerBtn->setText(QApplication::translate("Widget", "stop server", nullptr));
        stopAllServerBtn->setText(QApplication::translate("Widget", "stop all server", nullptr));
        updateDevice->setText(QApplication::translate("Widget", "refresh devices", nullptr));
        getIPBtn->setText(QApplication::translate("Widget", "get device IP", nullptr));
        startAdbdBtn->setText(QApplication::translate("Widget", "start adbd", nullptr));
        installSndcpyBtn->setText(QApplication::translate("Widget", "install sndcpy", nullptr));
        startAudioBtn->setText(QApplication::translate("Widget", "start audio", nullptr));
        stopAudioBtn->setText(QApplication::translate("Widget", "stop audio", nullptr));
        wirelessGroupBox->setTitle(QApplication::translate("Widget", "Wireless", nullptr));
        deviceIpEdt->setText(QString());
        devicePortEdt->setText(QString());
        wirelessConnectBtn->setText(QApplication::translate("Widget", "wireless connect", nullptr));
        wirelessDisConnectBtn->setText(QApplication::translate("Widget", "wireless disconnect", nullptr));
        Q_UNUSED(Widget);
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
