import QtQuick 2.10
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

import App 1.0

import "./components"

Item {
    id: root
    width: 1450
    height: 850

    SceneProvider {
        onCppGenerateEvents: {

            console.log(name)

            switch (name) {
            case "MIRROR_START":
                cover_animation_show.start()
                break
            case "MIRROR_FINISHED":
                prepareHideAndroidScreen()
                cover_animation_hide.start()
                break
            case "FRAME_SIZE_CHANGED":
                break
            case "DISPLAY_ORIENTATION_CHANGED":
                // Portrait orientation is vertical
                if (resourceService.orientation == 0) {
                    center.x = 185 + 5
                    center.y = 413 + 5
                    prepareHideAndroidScreen()
                    cover_animation_portrait.start()
                } else {
                    //Landscape orientation is horizontal
                    center.x = 430 + 120 + 165
                    center.y = 200 + 50 + 75
                    prepareHideAndroidScreen()
                    cover_animation_landscape.start()
                }
                break
            }
        }
    }

    function prepareShowAndroidScreen() {
        resourceService.mirror = true
        mirror.visible = true

        car.opacity = 0
        toolbar.opacity = 0
        toolbarApps.opacity = 0
        music.opacity = 0
    }

    function prepareHideAndroidScreen() {
        car.opacity = 1
        toolbar.opacity = 1
        toolbarApps.opacity = 1
        music.opacity = 1

        resourceService.mirror = false
        mirror.visible = false
    }

    Image {
        id: car
        source: "../images/wall2.png"
        anchors.fill: parent
        x: 20
        y: 20
    }
    Image {
        source: "../images/parsa.jpg"
        width: 118
        height: 118
        x: 200
        y: 200
    }

    Music {
        id: music
        x: 950
        y: 10
        ScaleAnimator {
            id: animation_show
            target: music
            from: 0.2
            to: 1.0
            duration: 300
        }
        ScaleAnimator {
            id: animation_hide
            target: music
            from: 1.0
            to: 0.2
            duration: 300
        }
    }

    Rectangle {
        id: cover
        anchors.centerIn: center
        width: resourceService.portraitSize.width
        height: resourceService.portraitSize.height
        color: "#2979ff"
        opacity: 0.8
        scale: 0.2
        radius: 25
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
                    prepareShowAndroidScreen()
                }
            }
        }
        ParallelAnimation {
            id: cover_animation_hide
            ScaleAnimator {
                target: cover
                from: 1.0
                to: 0.0
                duration: 400
                easing.type: Easing.InOutQuad
            }
            onRunningChanged: {
                if (!running) {

                }
            }
        }
        ParallelAnimation {
            id: cover_animation_portrait
            ScaleAnimator {
                target: cover
                from: 1.0
                to: 0.4
                duration: 400
                easing.type: Easing.InOutQuad
            }
            onRunningChanged: {
                if (!running) {
                    mirror.width = resourceService.portraitSize.width
                    mirror.height = resourceService.portraitSize.height

                    cover.width = resourceService.portraitSize.width
                    cover.height = resourceService.portraitSize.height
                    cover_animation_show.start()
                }
            }
        }
        ParallelAnimation {
            id: cover_animation_landscape
            ScaleAnimator {
                target: cover
                from: 1.0
                to: 0.4
                duration: 400
                easing.type: Easing.InOutQuad
            }
            onRunningChanged: {
                if (!running) {
                    mirror.width = resourceService.landscapeSize.width
                    mirror.height = resourceService.landscapeSize.height

                    cover.width = resourceService.landscapeSize.width
                    cover.height = resourceService.landscapeSize.height
                    cover_animation_show.start()
                }
            }
        }
    }
    Scene {
        id: mirror
        anchors.centerIn: center
        width: resourceService.portraitSize.width
        height: resourceService.portraitSize.height
    }
    Rectangle {
        id: center
        x: 185
        y: 413
        width: 0
        height: 0
        color: "#ff9800"
    }

    ToolBar {
        id: toolbar
        x: 320
        onSelect: resourceService.processClick(icon)
    }

    ToolBarApps {
        id: toolbarApps
        onSelect: {
            switch (icon) {
            case "mirror":
                resourceService.qmlCommands("REQUEST_MIRROR_START")
                break
            case "calculator":
                break
            case "music":
                animation_show.restart()
                break
            case "movies":
                animation_hide.restart()
                break
            case "compass":

                break
            case "photo":
                resourceService.qmlCommands("REQUEST_MIRROR_FINISH")
                break
            }
        }
    }
}
