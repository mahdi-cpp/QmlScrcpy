import QtQuick 2.10
import QtQuick.Layouts 1.0

Item {
    id: root
    width: 680
    height: 84
    x: 700
    y: 700
    signal select(string icon)

    Rectangle {
        anchors.fill: parent
        radius: 50
        color: "#fff"
        opacity: 0.6
    }
    GridLayout {
        x: 100
        y: 18
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
    Ring {
        id: user
        user: "parsa"
        x: 2
        y: 2
    }
}
