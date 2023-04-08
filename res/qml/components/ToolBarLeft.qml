import QtQuick 2.10
import QtQuick.Layouts 1.0

Item {
    id: root
    width: 80
    height: 900
    x: 0
    y: 0

    signal select(string icon)

    function setPortrait() {
        grid.flow = GridLayout.TopToBottom
    }
    function setLandscape() {
        grid.flow = GridLayout.LeftToRight
    }

    Rectangle {
        anchors.fill: parent
        radius: 0
        color: "#333"
        opacity: 1
    }
    Image {
        id: image
        width: 30
        height: 30
        x: 25
        y: 10
        source: "../../icons/wifi_30.svg"
    }
    Text {
        width: 80
        text: "05:37"
        font.pointSize: 16
        color: "#fff"
        y: 40
        horizontalAlignment: Text.AlignHCenter
    }

    GridLayout {
        id: grid
        x: 12
        y: 200
        flow: GridLayout.TopToBottom
        rows: 20
        CustomAppIcon {
            onClick: select("map")
            backgroun: "#fff"
            icon: "aa.svg"
            iconWidth: 30
            iconHeight: 30 * 1.43
            iconX: 15
            iconY: 10
        }
        CustomAppIcon {
            onClick: select("music")
            backgroun: "#ff7700"
            icon: "soundcloud.svg"
        }
                CustomAppIcon {
                    onClick: select("call")
                    backgroun: "#00e676"
                    icon: "phone.svg"
                }
    }

    CustomAppIcon {
        x: 11
        y: 650
        onClick: select("menu")
        backgroun: "transparent"
        icon: "dot_grid.svg"
        icon2: "window_grid.svg"
        index : 1;
    }
}
