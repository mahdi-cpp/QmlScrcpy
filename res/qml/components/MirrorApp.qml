import QtQuick 2.10
import QtQuick.Layouts 1.0

Rectangle {
    id: root
    x: 80
    y: 200
    width: 800
    height: 400
    color: "#fff"
    visible: false
    radius: 7

    property string deviceName

    function show() {
        root.visible = true
        timer.start()
    }
    function hide() {
        root.visible = false
        timer.stop()
    }

    function setUsbDevice(name) {
        deviceName = name

        if (deviceName.length > 3) {
            //connected
            no_device_view.visible = false
            button_start_mirror.visible = true
        } else {
            no_device_view.visible = true
            button_start_mirror.visible = false
        }
    }

    Timer {
        id: timer
        interval: 2000
        running: false
        repeat: true
        onTriggered: {
            resourceService.qmlCommands("REQUEST_DEVICES_LIST" , "")
        }
    }

    Text {
        width: 200
        text: "Mirror Application"
        font.pointSize: 12
        color: "#444"
        x: 20
        y: 15
    }

    Image {
        x: parent.width - 40
        y: 10
        source: "../../icons/close_black.svg"
        width: 30
        height: 30
        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.hide()
            }
        }
    }

    Rectangle {
        //toolbar line
        x: 0
        y: 50
        width: parent.width
        height: 2
        color: "#eee"
    }

    Rectangle {
        //no device view
        id: no_device_view
        width: 400
        x: 200
        y: 100
        height: 100
        color: "#eee"
        radius: 10
        Text {
            width: parent.width
            text: "Cell phone not connected"
            font.pointSize: 14
            color: "#000"
            y: 20
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            width: parent.width
            text: "Please connect android phone by USB cable"
            font.pointSize: 12
            color: "#000"
            y: 60
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        //button
        id: button_start_mirror
        x: 325
        y: 100
        width: 150
        height: 200
        color: "#29b6f6"
        radius: 20
        visible: false
        Image {
            x: 50
            y: 30
            source: "../../icons/usb_plug.svg"
            width: 50
            height: 50
        }
        Text {
            width: 150
            text: "Start Mirror"
            font.pointSize: 14
            color: "#fff"
            y: 100
            horizontalAlignment: Text.AlignHCenter
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                resourceService.qmlCommands("REQUEST_MIRROR_START" , deviceName)
            }
            onPressed: {
                button_start_mirror.color = "#0288d1"
            }
            onReleased: {
                button_start_mirror.color = "#29b6f6"
            }
        }
    }
}
