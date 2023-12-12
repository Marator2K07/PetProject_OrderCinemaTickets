import QtQuick 2.15

Image {
    id: root
    source: "Pictures/LoadingPicture.png"
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    Behavior on rotation {
        NumberAnimation {
            duration: 250
        }
    }
}
