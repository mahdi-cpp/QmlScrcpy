import QtQuick 2.10
import QtGraphicalEffects 1.0

Item {
    width: 70
    height: 70

    property string user: "parsa"

    Image {
        anchors.centerIn: parent
        source: "/home/mahdi/photos/icon/ring.svg"
        width: 63 + 5
        height: 63 + 5
        fillMode: Image.PreserveAspectCrop
        layer.enabled: true
        layer.effect: OpacityMask {
            maskSource: mask
        }
    }

    Image {
        anchors.centerIn: parent
        source: "/home/mahdi/photos/icon/" + user + ".jpg"
        width: 55 + 5
        height: 55 + 5
        fillMode: Image.PreserveAspectCrop
        layer.enabled: true
        layer.effect: OpacityMask {
            maskSource: mask
        }
    }

    Rectangle {
        id: mask
        width: 55
        height: 55
        radius: 40
        visible: false
    }
}
