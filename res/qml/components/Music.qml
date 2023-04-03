import QtQuick 2.10

Item {
    id: root
    width: 400
    height: 400 + 200
    signal select(string icon)

    function message(message) {
        album.text = message
    }

    function setPortrait() {
        grid.flow = GridLayout.TopToBottom
    }
    function setLandscape() {
        grid.flow = GridLayout.LeftToRight
    }

    Image {
        id: car
        source: "../../images/music-cover.jpg"
        width: parent.width
        height: parent.width
    }

    Rectangle {
        width: parent.width
        height: 200
        anchors.bottom: parent.bottom
        color: "#ff9800"
        opacity: 1
        y: 450
        Text {
            id: album
            text: "You Got to listen ..."
            font.family: "Helvetica"
            font.pointSize: 20
            color: "#fff"
            x: 20
            y: 10
        }
        Text {
            text: "Fryan Ay Divone..."
            font.family: "Helvetica"
            font.pointSize: 16
            color: "#fff"
            x: 20
            y: 50
        }
    }

    Rectangle {
        anchors.bottom: buttons.top
        width: parent.width - 80
        height: 4
        x: 40
        radius: 50
        color: "#fff"
        opacity: 0.5
    }
    Rectangle {
        anchors.bottom: buttons.top
        width: 150
        height: 4
        x: 40
        radius: 50
        color: "#fff"
        opacity: 1
    }

    Item {
        id: buttons
        width: parent.width
        height: 100
        anchors.bottom: parent.bottom
        x: 20

        Image {
            source: "../../icons/skip-previous.svg"
            width: 50
            height: 50
            x: 45
            y: 20
        }
        Image {
            source: "../../icons/pause.svg"
            width: 50
            height: 50
            x: 170
            y: 20
        }
        Image {
            source: "../../icons/skip-next.svg"
            width: 50
            height: 50
            x: 300
            y: 20
        }
    }
}
