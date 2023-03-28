import QtQuick 2.10

Item {
    width: size
    height: size

    property string icon:  "eye"
    property int size:  40

    signal click()

    Rectangle {
        anchors.fill: parent
        radius: 12
        color: "#444"
        opacity: 0.8
    }
    Image {
        anchors.centerIn: parent
        source: "../../icons/" + icon + ".svg"
        width: size - 10
        height: size - 10
    }

    MouseArea {
        anchors.fill: parent
        onClicked: { click() }
    }
}
