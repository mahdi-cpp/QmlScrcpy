import QtQuick 2.0
import OpenGLUnderQML 1.0

Item {
    id:parent
    width: 400
    height: 900

    Rectangle {
        color: "red"
        x: 150
        y: 250
        radius: 10
        border.width: 1
        border.color: "blue"
        width: 200
        height: 50
    }

    Text {
        id: label
        color: "white"
        wrapMode: Text.WordWrap
        text: "12 The background here is a squircle rendered with raw OpenGL using the 'beforeRender()' signal in QQuickWindow.
          This text label and its border is rendered using QML"
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.margins: 20
    }

    Squircle {
        width:420
        height:900
        SequentialAnimation on t {
            NumberAnimation { to: 1; duration: 2500; easing.type: Easing.InQuad }
            NumberAnimation { to: 0; duration: 2500; easing.type: Easing.OutQuad }
            loops: Animation.Infinite
            running: true
        }
    }
}

