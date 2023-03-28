import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Particles 2.0
import QtQuick.Shapes 1.0

import SceneGraphRendering 1.0

Window {
    visible: true
    title: qsTr("QtWs 2022")
    flags: Qt.Dialog
    width: 1500
    height: 950

                   Render{
                       id: renderer
                       width: 400
                       height: 900
                       x: 20
                       y: 500
                   }


    Image {width: 200; height: 400; x: 750; source: "/home/mahdi/photos/3.jpg"}




}
