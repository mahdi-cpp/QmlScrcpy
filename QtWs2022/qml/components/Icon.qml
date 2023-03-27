import QtQuick 2.10

Item {
    width: 50
    height: 50

    property string icon:  "eye"
    signal click()

    Rectangle {
        anchors.fill: parent
        radius: 12
        color: "#444"
        opacity: 0.8
    }
    Image {
        anchors.centerIn: parent
        source: "/home/mahdi/photos/icon/" + icon + ".svg"
        width: 35
        height: 35
    }

    MouseArea {
        anchors.fill: parent
        onClicked: { click() }
    }
}
