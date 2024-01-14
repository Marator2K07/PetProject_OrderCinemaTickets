import QtQuick
import QtQuick.Controls

Rectangle {
    id: mainRect
    anchors.fill: parent
    opacity: 0.9
    color: "lightgray"

    property alias spinnerColor: loadingSpinner.color;
    property alias backgroundColor: mainRect.color;
    property bool isLoading: true;

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
            id: rotateSpinnerAnimation
            from: 0; to: 360
            alwaysRunToEnd: true
            loops: -1
            duration: 550
        }
    }
}
