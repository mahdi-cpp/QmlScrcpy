import QtQuick 2.10
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import QtQuick.Shapes 1.0

import QtMultimedia 5.0

import App 1.0

Item {
    width: 1739
    height: 900
    visible: true

    SceneProvider {}

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
        scale: 0.2
        ScaleAnimator {
            id: animation_show
            target: kitchen
            from: 0.2
            to: 1.0
            duration: 300
        }
        ScaleAnimator {
            id: animation_hide
            target: kitchen
            from: 1.0
            to: 0.2
            duration: 300
        }
        opacity: 1.0
    }
    Image {
        id: logo
        source: "/home/mahdi/photos/6.png"
        width: 324
        height: 93
        x: 20
        y: 20
        visible: false
    }

    Rectangle {
        width: 100
        height: 50
        x: 300
        y: 600
        color: "red"
        opacity: 1
    }

    Button {
        x: 600
        y: 50
        text: "Show"
        onClicked: {
            animation_show.restart()
        }
    }
    Button {
        x: 600
        y: 100
        text: "Hide"
        onClicked: {
            animation_hide.restart()
        }
    }

    Rectangle {
        id: cover
        x: 400
        y: 20
        width: 400
        height: 900
        color: "#444"
        opacity: 1
        scale: 0.2

        ParallelAnimation {
            id: cover_animation_show
            ScaleAnimator {
                target: cover
                from: 0.2
                to: 1.0
                duration: 400
                easing.type: Easing.InOutQuad
            }
            onRunningChanged: {
                if (!running) {
                    mirror.visible = true;
                    resourceService.mirror = true
                    car.visible = false
                    logo.visible = false
                    kitchen.opacity = 0.0
                }
            }
        }

        ParallelAnimation {
            id: cover_animation_hide
            ScaleAnimator {
                target: cover
                from: 1.0
                to: 0.2
                duration: 400
                easing.type: Easing.InOutQuad
            }
            onRunningChanged: {
                if (!running) {
                    car.visible = true
                    logo.visible = true
                }
            }
        }
    }
        Scene {
            id: mirror
            x: 400
            y: 20
            width: 400
            height: 900
        }

    Button {
        text: "Show Mirror"
        x: 100
        y: 50
        onClicked: {
            cover_animation_show.start()
        }
    }
    Button {
        text: "Hide Mirror"
        x: 100
        y: 100
        onClicked: {
            car.visible = true
            logo.visible = true
                        mirror.visible = false;
                        resourceService.mirror = false
            cover_animation_hide.start()
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
