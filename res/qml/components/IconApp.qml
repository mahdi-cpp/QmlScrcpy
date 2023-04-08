import QtQuick 2.10

Item {
    id: root
    width: 140
    height: 180

    property string icon:  "eye"
    property string title:  "Music"
    property string name:  "music"

    signal click()

    Image {
        anchors.centerIn: parent
        source: "../../icons/" + icon
        width: 90
        height: 90
    }
            Text {
                id: album
                text: title
                font.family: "Helvetica"
                font.pointSize: 14
                color: "#fff"
                width: root.width
                horizontalAlignment: Text.AlignHCenter
                y: root.height - 40
            }
    MouseArea {
        anchors.fill: parent
        onClicked: { click() }
    }
}
