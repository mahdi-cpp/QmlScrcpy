import QtQuick 2.10
import QtMultimedia 5.9

Item {
    id: root
    x: 1450
    y: 2
    width: 350
    height: 740
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

    Audio {
        id: audio
    }

    Image {
        source: "../../images/peaceful_blur.jpg"
        width: parent.width
        height: parent.height
    }
    Text {
        text: "Music Player"
        font.family: "Helvetica"
        font.pointSize: 16
        color: "#fff"
        width: root.width
        horizontalAlignment: Text.AlignHCenter
        y: 40
    }
    Image {
        x: 50
        y: 110
        source: "../../images/music_cover.jpg"
        width: 250
        height: 250
    }
    Rectangle {
        width: root.width
        height: 27
        color: "#000"
        anchors.bottom: parent.bottom
    }

    Item {
        width: parent.width
        height: 300
        anchors.bottom: parent.bottom
        opacity: 1
        y: 400
        Text {
            id: album
            text: "Nafas haye Bi hadaf"
            font.family: "Helvetica"
            font.pointSize: 18
            color: "#fff"
            width: root.width
            horizontalAlignment: Text.AlignHCenter
            y: 10
        }
        Text {
            text: "Mohsen Yeganeh"
            font.family: "Helvetica"
            font.pointSize: 16
            color: "#fff"
            width: root.width
            horizontalAlignment: Text.AlignHCenter
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
        height: 150
        anchors.bottom: parent.bottom
        x: 20

        Image {
            source: "../../icons/skip-previous.svg"
            width: 50
            height: 50
            x: 30
            y: 40
        }
        Image {
            source: "../../icons/pause.svg"
            width: 50
            height: 50
            x: 130
            y: 40
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    audio.pause()
                }
            }
        }
        Image {
            source: "../../icons/skip-next.svg"
            width: 50
            height: 50
            x: 240
            y: 40
        }
    }

    states: [
        State {
            name: "hide"
            when: !resource.scene == enum_WINDOW_MIRROR_MUSIC
            PropertyChanges {
                target: music
                x: parent.width + 350
            }
        },
        State {
            name: "show"
            when: resource.scene == enum_WINDOW_MIRROR_MUSIC
                  || resource.scene == enum_WINDOW_MIRROR_PORTRATE
            PropertyChanges {
                target: music
                x: parent.width - music.width - 2
            }
        }
    ]
    transitions: Transition {
        NumberAnimation {
            properties: "x"
            duration: 200
            easing.type: Easing.InOutQuad
        }
    }
}
