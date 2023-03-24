import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import QtQuick.Window 2.0
import QtGraphicalEffects 1.0

import App 1.0

Window {
    width: 1739
    height: 869
    visible: true
    title: qsTr("QtWs 2022")
    flags: Qt.Dialog

    // We need to instantiate a single BackgroundRenderer to every QML window
    SceneProvider {}

    //SeparateWindow {
        //id: separateWindow
    //}

    Item {
        anchors.fill: parent

            Label {
                 Layout.alignment: Qt.AlignHCenter
                 text: "Qt Scrcpy"
                 x: 300
                 y: 200
                 color: "white"
                 font.pointSize: 14
                 }

            Scene {
                x: 200
                y: 180
                width: 650
                height: 500
            }

                        Rectangle{
                            width: 500
                            height: 50
                            color: "white"
                            x: 300
                            y: 600
                            opacity: 0.8

                            Label {
                            Layout.alignment: Qt.AlignHCenter
                            text: "Mirror Android Devices "
                            color: "white"
                            font.pointSize: 30
                            }

                        }


        GroupBox {
            Layout.fillWidth: true
            Layout.fillHeight: true
            x: 1400
            y: 550
            ColumnLayout {
                anchors.fill: parent

                Button {
                    text: "Open separate window"
                    onClicked: separateWindow.showNormal()
                }

                Button {
                    text: animation.running ? "Stop animation" : "Start animation"
                    onClicked: animation.running ? animation.stop() : animation.start()

                    ParallelAnimation {
                        id: animation

                        loops: Animation.Infinite

                        SequentialAnimation {
                            NumberAnimation {
                                target: pitchSlider
                                property: "value"
                                easing.type: Easing.InCubic
                                from: 0
                                to: 360
                                duration: 5000
                            }
                            NumberAnimation {
                                target: pitchSlider
                                property: "value"
                                easing.type: Easing.InCubic
                                from: 360
                                to: 0
                                duration: 5000
                            }
                        }
                        SequentialAnimation {
                            NumberAnimation {
                                target: yawSlider
                                property: "value"
                                easing.type: Easing.InOutQuad
                                from: 0
                                to: 360
                                duration: 3000
                            }
                            NumberAnimation {
                                target: yawSlider
                                property: "value"
                                easing.type: Easing.InOutQuad
                                from: 360
                                to: 0
                                duration: 3000
                            }
                        }

                        SequentialAnimation {
                            NumberAnimation {
                                target: rollSlider
                                property: "value"
                                easing.type: Easing.InOutBack
                                from: 0
                                to: 360
                                duration: 6000
                            }
                            NumberAnimation {
                                target: rollSlider
                                property: "value"
                                easing.type: Easing.InOutBack
                                from: 360
                                to: 0
                                duration: 6000
                            }
                        }
                    }
                }

                Label {
                    text: "Pitch"
                }

                Slider {
                    id: pitchSlider

                    from: 0
                    to: 360

                    onValueChanged: resourceService.pitch = value
                }

                Label {
                    text: "Yaw"
                }

                Slider {
                    id: yawSlider

                    from: 0
                    to: 360

                    onValueChanged: resourceService.yaw = value
                }

                Label {
                    text: "Roll"
                }

                Slider {
                    id: rollSlider

                    from: 0
                    to: 360

                    onValueChanged: resourceService.roll = value
                }
            }
        }
    }
}
