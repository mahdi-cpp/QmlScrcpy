import QtQuick 2.10
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

import App 1.0

import "./components"

Rectangle {
    id: window
    width: 1450
    height: 900
    color: "#000"

    property int enum_WINDOW_HOME: 0
    property int enum_WINDOW_MIRROR_PORTRATE: 1
    property int enum_WINDOW_MIRROR_LANDSCAPE: 2
    property int enum_WINDOW_MIRROR_FULLSCREEN: 3
    property int enum_WINDOW_MIRROR_MUSIC: 4
    property int enum_WINDOW_MIRROR_SMALL: 5

    Component.onCompleted: {
        //resource.scene = resource.WINDOW_HOME;
    }


    ToolBarApps {
        id: toolbarApps
        onSelect: {
            switch (icon) {
            case "mirror.svg":
                resource.qmlRequest("REQUEST_DEVICES_LIST", "")
                mirrorApp.open()
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
                ali = 1
                break
            case "photo":
                ali = 2
                break
            }
        }
    }

    MirrorApp {
        id: mirrorApp
    }

    Music {
        id: music
    }

    Rectangle {
        id: mirror
        //anchors.centerIn: center
        x: -400
        y: 2
        width: 400
        height: 900
        color: "#ff9800"
        opacity: 1
        scale: 1
        radius: 30
        visible: true
        transformOrigin: Item.Center

        states: [
            State {
                name: "hide"
                when: resource.mirror == 0
                PropertyChanges {
                    target: mirror
                    x: -400
                    width: 350
                    height: 720
                }
            },
            State {
                name: "portrait"
                when: resource.scene == enum_WINDOW_MIRROR_PORTRATE
                PropertyChanges {
                    target: mirror
                    x: 82
                    width: 330
                    height: 710 + 4
                }
            },
            State {
                name: "landscape"
                when: resource.orientation == 1
                      && resource.scene == enum_WINDOW_MIRROR_LANDSCAPE
                PropertyChanges {
                    target: mirror
                    x: 30
                    width: 1450 + 200 + 35
                    height: 712
                }
            },
            State {
                name: "share"
                when: resource.orientation == 1
                      && resource.scene == enum_WINDOW_MIRROR_MUSIC
                PropertyChanges {
                    target: mirror
                    x: -355
                    width: 1450 + 200 + 35
                    height: 712
                }
            },
            State {
                name: "alone"
                when: resource.orientation == 1
                      && resource.scene == enum_WINDOW_MIRROR_FULLSCREEN
                PropertyChanges {
                    target: mirror
                    x: 30
                    width: 1450 + 200 +35
                    height: 712
                }
            },
            State {
                name: "small"
                when: resource.orientation == 1
                      && resource.scene == enum_WINDOW_MIRROR_SMALL
                PropertyChanges {
                    target: mirror
                    x: 800
                    width: 1450 +200
                    height: 712
                }
            }
        ]

        transitions: Transition {
            NumberAnimation {
                properties: "x,y,width,height"
                duration: 200
                easing.type: Easing.InOutQuad
            }
        }

        MirrorScene {
            id: video
            width: 300
            height: 600
            anchors.fill: parent
            onCppGenerateEvents: {

                console.log(request)

                switch (request) {
                case "MIRROR_START":
                    mirrorApp.close()
                    resource.mirror = 1
                    resource.scene = enum_WINDOW_MIRROR_PORTRATE
                    break
                case "MIRROR_FINISHED":
                    resource.mirror = 0
                    break
                case "FRAME_SIZE_CHANGED":
                    break
                case "DISPLAY_ORIENTATION_CHANGED":

                    if (resource.orientation == 0) {
                        // Portrait orientation is vertical
                        resource.scene = enum_WINDOW_MIRROR_PORTRATE
                    } else if (resource.orientation == 1) {
                        //Landscape orientation is horizontal
                        console.log("enum_WINDOW_MIRROR_LANDSCAPE")
                        resource.scene = enum_WINDOW_MIRROR_LANDSCAPE
                    }
                    break
                case "USB_DEVICE_NAME":
                    mirrorApp.setUsbDevice(data)
                    break
                }
            }
        }
    }

    ToolBarLeft {
        onSelect: {
            switch (icon) {
            case "map":
                if (resource.orientation == 1) {
                    resource.scene = enum_WINDOW_MIRROR_FULLSCREEN
                }
                break
            case "music":
                if (resource.orientation == 1) {
                    resource.scene = enum_WINDOW_MIRROR_MUSIC
                }
                break
            case "menu":
                if (resource.orientation == 1) {
                    resource.scene = enum_WINDOW_MIRROR_SMALL
                }

                break
            }
        }
    }

    ToolBarMirror {
        id: toolbar
        onSelect: {

            switch (icon) {

            case "close":
                resource.qmlRequest("REQUEST_MIRROR_FINISH", "")
                break
            default:
                resource.qmlToolbarClick(icon)
            }
        }
    }
}
