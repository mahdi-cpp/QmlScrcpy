import QtQuick 2.10
import QtQuick.Layouts 1.0

Item {
    id: root
    width: 64
    height: 530
    x: 390
    y: -600
    signal select(string icon)

    function setPortrait(){
        grid.flow = GridLayout.TopToBottom
    }
    function setLandscape(){
        grid.flow = GridLayout.LeftToRight
    }

    Rectangle {
        anchors.fill: parent
        radius: 50
        color: "#fff"
        opacity: 0.8
    }

    GridLayout {
        id: grid
        x: 12
        y: 18
        columns: 20
        rows: 20
        flow: GridLayout.TopToBottom
                Icon {
                    icon: "close"
                    onClick: select(icon)
                }
        Icon {
            icon: "home"
            onClick: select(icon)
        }
        Icon {
            icon: "volume-up"
            onClick: select(icon)
        }
        Icon {
            icon: "volume-down"
            onClick: select(icon)
        }
        Icon {
            icon: "arrow-back"
            onClick: select(icon)
        }
        Icon {
            icon: "screen-on"
            onClick: select(icon)
        }
        Icon {
            icon: "screen-off"
            onClick: select(icon)
        }
        Icon {
            icon: "power"
            onClick: select(icon)
        }
        Icon {
            icon: "expand-menu"
            onClick: select(icon)
        }
        Icon {
            icon: "app-switch"
            onClick: select(icon)
        }
        Icon {
            icon: "touch-show"
            onClick: select(icon)
        }
    }
//    Ring {
//        id: user
//        user: "parsa"
//        x: 2
//        y: 2
//    }
}