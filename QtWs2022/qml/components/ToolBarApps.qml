import QtQuick 2.10
import QtQuick.Layouts 1.0

Item {
    id: root
    width: 600
    height: 74
    x: 300
    y: 350
    signal select(string icon)

    GridLayout {
        id: grid
        x: 100
        y: 18
        columns: 4

            CustomAppIcon{
                onClick: select("mirror")
            }
        IconApp {
            icon: "app"
            onClick: select(icon)
        }
        IconApp {
            icon: "calculator"
            onClick: select(icon)
        }
        IconApp {
            icon: "call"
            onClick: select(icon)
        }
        IconApp {
            icon: "compass"
            onClick: select(icon)
        }
        IconApp {
            icon: "music"
            onClick: select(icon)
        }
        IconApp {
            icon: "movies"
            onClick: select(icon)
        }
        IconApp {
            icon: "note"
            onClick: select(icon)
        }
        IconApp {
            icon: "photo"
            onClick: select(icon)
        }
    }
}
