import QtQuick 2.10

Item {
    id: root
    width: 60
    height: 70


    signal click

    property color backgroun : "#ff9800"

    property string icon : "map.svg"
    property string icon2 : "map.svg"
    property int iconX: 8
    property int iconY: 8
    property int iconWidth : 42
    property int iconHeight: 42

    property int index : 0;

    Rectangle {
    width: 60
    height: 60
    radius: 32
    color: backgroun
    Image {
        id: image
        width: iconWidth
        height: iconHeight
        x: iconX
        y: iconY
        source: "../../icons/" + icon
    }

    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (root.enabled === true) {
                root.enabled = false
                timer.start()
                click()
                if(index == 1){
                index = 2;
                    image.source = "../../icons/" + icon2
                }else if(index == 2){
                index = 1;
                 image.source = "../../icons/" + icon
                }
                //console.log("click")
            }
        }
//        onPressed: {
//            if (root.enabled === true) {
//                root.enabled = false
//                timer.start()
//                press.restart()
//            }
//        }
//        onReleased: {
//            releas.restart()
//        }
    }

    ScaleAnimator {
        id: press
        target: root
        from: 1
        to: 0.9
        duration: 200
        easing.type: Easing.InOutQuad
    }
    ScaleAnimator {
        id: releas
        target: root
        from: 0.9
        to: 1
        duration: 200
        easing.type: Easing.InOutQuad
    }

    Timer {
        id: timer
        interval: 1000
        running: true
        repeat: false
        onTriggered: {
            root.enabled = true
        }
    }
}
