import QtQuick 2.0

Rectangle {
    id: root
    width: 800
    height: 600
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#d9dcf4"
        }

        GradientStop {
            position: 1
            color: "#5ad51d"
        }
    }


    Rectangle {
        id: ball
        color: "red"
        width: 50
        height: 50
        radius: 25
        x: 100
        y: 100

        MouseArea {
            anchors.fill: parent
            drag.target: ball
            drag.minimumX: 0
            drag.maximumX: root.width - ball.width
            drag.minimumY: 0
            drag.maximumY: root.height - ball.height
        }

        onXChanged: root.ballMoved(x, y)
        onYChanged: root.ballMoved(x, y)

    }

    signal ballMoved(real x, real y)
}
