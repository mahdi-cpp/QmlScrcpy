import QtQuick 2.10
import QtQuick.Layouts 1.0

Rectangle {
    id: root
    x: 80 + 2
    y: 2
    width: 1250 - 2
    height: 712
    visible: false
    radius: 7

    gradient: Gradient {
        GradientStop {
            position: 0.0
            color: "#00695c"
        }
        GradientStop {
            position: 0.23
            color: "#009688"
        }
        GradientStop {
            position: 0.8
            color: "#00796b"
        }
    }

    property string deviceName

    function open() {
        root.visible = true
        timer.start()
    }
    function close() {
        root.visible = false
        timer.stop()
    }

    function setUsbDevice(name) {
        deviceName = name

        if (deviceName.length > 3) {
            //connected
            no_device_view.visible = false
            view_connected.visible = true
        } else {
            no_device_view.visible = true
            view_connected.visible = false
        }
    }

    Timer {
        id: timer
        interval: 2000
        running: false
        repeat: true
        onTriggered: {
            resource.qmlRequest("REQUEST_DEVICES_LIST", "")
        }
    }

    Text {
        width: root.width
        text: "Mirror Application"
        font.pointSize: 18
        color: "#fff"
        horizontalAlignment: Text.AlignHCenter
        y: 25
    }

    Rectangle {
        //back button
        x: 15
        y: 15
        width: 45
        height: 45
        color: "#80d8ff"
        radius: 30
        Image {
            x: 8
            y: 8
            source: "../../icons/arrow-back.svg"
            width: 28
            height: 28
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.close()
            }
        }
    }

    Image {
        x: -100
        y: 150
        source: "../../images/android.svg"
        width: 400 * 1.777
        height: 400
    }
    Image {
        x: 220
        y: 300
        source: "../../icons/android.svg"
        width: 70
        height: 70
    }

    Rectangle {
        id: no_device_view
        visible: false
        width: 600
        x: 410
        y: 200
        height: 200
        color: "transparent"
        radius: 10
        Image {
            x: -10
            y: 15
            source: "../../icons/usb_plug.svg"
            width: 42
            height: 42
        }
        Text {
            width: parent.width
            text: "Cell phone not connected"
            font.pointSize: 20
            color: "#fff"
            x: 40
            y: 20
        }
        Text {
            width: 200
            text: "1. Enable adb debugging on your android phone."
            font.pointSize: 14
            color: "#fff"
            y: 100
        }
        Text {
            width: parent.width
            text: "2. Connect android phone by USB cable"
            font.pointSize: 14
            color: "#fff"
            y: 140
        }
    }

    Item {
        //connected
        id: view_connected
        x: 410
        y: 200
        width: 500
        height: 500
        visible: true

        Image {
            x: -10
            y: 15
            source: "../../icons/usb_plug.svg"
            width: 42
            height: 42
        }
        Text {
            width: parent.width
            text: "Connected ..."
            font.pointSize: 20
            color: "#fff"
            x: 40
            y: 20
        }
        Rectangle {
            id: button_start
            x: 0
            y: 100
            width: 200
            height: 60
            color: "#004d40"
            radius: 10
            Text {
                width: 150
                text: "Start Mirror"
                font.pointSize: 16
                color: "#fff"
                x: 27
                y: 15
                horizontalAlignment: Text.AlignHCenter
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    resource.qmlRequest("REQUEST_MIRROR_START", deviceName)
                }
                onPressed: {
                    button_start.color = "#00695c"
                }
                onReleased: {
                    button_start.color = "#004d40"
                }
            }
        }
    }
}
