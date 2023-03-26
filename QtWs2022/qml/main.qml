import QtQuick 2.9
import QtQuick.Layouts 1
import QtQuick.Controls 2
import QtQuick.Shapes 1.0

import QtMultimedia 5.0

import App 1.0

Item {
    width: 1739
    height: 1050
    visible: true

    Image {
        id: car
        source: "/home/mahdi/photos/car.jpg"
        width: 1700
        height: 800
        x: 20
        y: 20
    }

    Image {
        id: kitchen
        source: "/home/mahdi/photos/3.jpg"
        width: 400
        height: 900
        x: 900
        y: 20
            RotationAnimator {
                id:animation
                target: kitchen;
                from: 0;
                to: 360;
                duration: 5000
                running: true
            }
            opacity:0.8
    }

    SceneProvider {
    }

    Scene {
        x: 400
        y: 20
        width: 400
        height: 900
    }

    Image {
        source: "/home/mahdi/photos/6.png"
        width: 324
        height: 93
        x: 20
        y: 20
    }


    Rectangle {
        width: 0
        height: 0
        x: 300
        y: 600
        color: "red"
        opacity: 1
    }

    Rectangle {
        width: 100
        height:50
        color: "#ff9800"
        radius: 10
        x: 100
        y: 50
        transform: Rotation { origin.x: 25; origin.y: 25; angle: 45}
        MouseArea {
            anchors.fill: parent
            onClicked: {
                resourceService.ali = true
                car.visible = false
                kitchen.opacity = 0.0
                animation.restart()
            }
        }
    }

    Button {
        x: 300
        y: 50
        text: "Hide"
        onClicked: {
            resourceService.ali = false
            car.visible = true
            kitchen.opacity = 1
        }
    }

    MediaPlayer {
        id: mediaplayer
        source: "/home/mahdi/photos/a.mkv"
    }

    VideoOutput {
        width: 600
        height: 400
        source: mediaplayer
    }

}
