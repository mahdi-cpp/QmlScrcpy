import QtQuick 2.10

Item {
    width: 140
    height: 180

    property string icon:  "eye"


    signal click()

    Image {
        anchors.centerIn: parent
        source: "../../icons/" + icon + ".png"
        width: 118
        height: 118
    }

    MouseArea {
        anchors.fill: parent
        onClicked: { click() }
    }
}
