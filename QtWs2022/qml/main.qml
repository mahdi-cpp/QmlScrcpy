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

    SceneProvider {}

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

    Button {
        text: "Show Mirror"
        x: 100
        y: 50
        onClicked: {
            resourceService.mirror = true
            car.visible = false
            kitchen.opacity = 0.0
            animation.restart()
        }
    }
    Button {
        text: "Hide Mirror"
        x: 100
        y: 100
        onClicked: {
            resourceService.mirror = false
            car.visible = true
            kitchen.opacity = 1
        }
    }

        Button {
            x: 600
            y: 50
            text: "Restart"
            onClicked: {
                animation.restart()
            }
        }
        Button {
            x: 600
            y: 100
            text: "Stop"
            onClicked: {
                animation.stop()
            }
        }

    MediaPlayer {
        id: mediaplayer
        source: "/home/mahdi/photos/a.mkv"
        //--autoPlay: true
    }

    VideoOutput {
        x: 1100
        width: 600
        height: 400
        source: mediaplayer
    }
}
