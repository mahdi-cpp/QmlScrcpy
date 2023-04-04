import QtQuick 2.10
import QtQuick.Layouts 1.0

Item {
    id: root
    width: 600
    height: 74
    x: 700
    y: 670
    signal select(string icon)

    GridLayout {
        id: grid
        columns: 2

            CustomAppIcon{
                onClick: select("mirror")
            }
//        IconApp {
//            icon: "app"
//            onClick: select(icon)
//        }
//        IconApp {
//            icon: "calculator"
//            onClick: select(icon)
//        }
//        IconApp {
//            icon: "call"
//            onClick: select(icon)
//        }
//        IconApp {
//            icon: "compass"
//            onClick: select(icon)
//        }
//        IconApp {
//            icon: "music"
//            onClick: select(icon)
//        }
//        IconApp {
//            icon: "movies"
//            onClick: select(icon)
//        }
//        IconApp {
//            icon: "note"
//            onClick: select(icon)
//        }
//        IconApp {
//            icon: "photo"
//            onClick: select(icon)
//        }
    }
}
