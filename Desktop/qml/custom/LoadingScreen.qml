import QtQuick
import QtQuick.Controls

Rectangle {
    anchors.fill: parent
    opacity: 0.8
    color: "lightgray"

    Label
    {
        id: loadingSpinner
        width: 33
        height: 39
        font.pixelSize: 75
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        bottomPadding: height/5
        color: "#cc00f8"
        text: "◡"
        anchors.centerIn: parent

        NumberAnimation on rotation {
            from: 0; to: 360;
            loops: Animation.Infinite;
            duration: 550;
        }
    }
}
