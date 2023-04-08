import QtQuick 2.10
import QtQuick.Layouts 1.0

Item {
    id: root
    width: 600
    height: 74
    x: 120
    y: 50
    signal select(string icon)

    GridLayout {
        id: grid
        columns: 4
        IconApp {
            icon: "mirror.svg"
            title: "Android Mirror"
            name: "mirror"
            onClick: select(icon)
        }
        IconApp {
            icon: "call.png"
            title: "Call"
            name: "call"
            onClick: select(icon)
        }
        IconApp {
            icon: "podcast.svg"
            title: "Podcast"
            name: "podcast"
            onClick: select(icon)
        }
        IconApp {
            icon: "music.png"
            title: "Music"
            name: "music"
            onClick: select(icon)
        }
        IconApp {
            icon: "message.png"
            title: "Message"
            name: "message"
            onClick: select(icon)
        }
        IconApp {
            icon: "app.png"
            title: "App"
            name: "app"
            onClick: select(icon)
        }
        IconApp {
            icon: "calculator.png"
            title: "Calculator"
            name: "calculator"
            onClick: select(icon)
        }
        IconApp {
            icon: "note.png"
            title: "Note"
            name: "note"
            onClick: select(icon)
        }
        IconApp {
            icon: "movies.png"
            title: "Movie"
            name: "movies"
            onClick: select(icon)
        }
        IconApp {
            icon: "photo.png"
            title: "photo"
            name: "photo"
            onClick: select(icon)
        }
    }
}
