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

    // состояния элемента
    states: [
        State {
            name: "Loading"
            when: mainRect.isLoading
            PropertyChanges {
                target: loadingSpinner
                font.pixelSize: 75
                text: "◡"
            }
            PropertyChanges {
                target: mainRect
                opacity: 0.9
            }
        },
        State {
            name: "Loaded"
            when: !mainRect.isLoading
            PropertyChanges {
                target: loadingSpinner
                font.pixelSize: 22
                text: "Uploaded successfully"
            }
            PropertyChanges {
                target: mainRect
                opacity: 0.0
            }
        }
    ]

    // переходы между состояниями
    transitions: [
        Transition {
            from: "*"
            to: "Loading"
            NumberAnimation {
                properties: "font.pixelSize, opacity"
                easing.type: Easing.Linear
                duration: 550
            }
        },
        Transition {
            from: "*"
            to: "Loaded"
            NumberAnimation {
                properties: "font.pixelSize, opacity"
                easing.type: Easing.Linear
                duration: 550
            }
        }
    ]
}
