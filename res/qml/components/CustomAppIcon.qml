import QtQuick 2.10

Rectangle {
    id: root
    width: 118
    height: 118
    radius: 20

    signal click

    gradient: Gradient {
        GradientStop {
            position: 0.0
            color: "#64ffda"
        }
        GradientStop {
            position: 1.0
            color: "#26a69a"
        }
    }

    Image {
        anchors.centerIn: parent
        source: "../../icons/baseline-cast.svg"
        width: 80
        height: 80
    }
    Text {
        width: 118
        text: "USB Mirror"
        font.pointSize: 16
        color: "#fff"
        y: 125
        horizontalAlignment: Text.AlignHCenter
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (root.enabled === true) {
                root.enabled = false
                timer.start()
                click()
                //console.log("click")
            }
        }
//        onPressed: {
//            if (root.enabled === true) {
//                root.enabled = false
//                timer.start()
//                press.restart()
//            }
//        }
//        onReleased: {
//            releas.restart()
//        }
    }

    ScaleAnimator {
        id: press
        target: root
        from: 1
        to: 0.9
        duration: 200
        easing.type: Easing.InOutQuad
    }
    ScaleAnimator {
        id: releas
        target: root
        from: 0.9
        to: 1
        duration: 200
        easing.type: Easing.InOutQuad
    }

    Timer {
        id: timer
        interval: 1000
        running: true
        repeat: false
        onTriggered: {
            root.enabled = true
        }
    }
}
