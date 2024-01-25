import QtQuick
import QtQuick.Controls

Rectangle {
    id: mainRect
    anchors.fill: parent
    opacity: loadingStateOpacity
    color: defBackgroundColor

    property color defBackgroundColor: "lightgray"
    property double loadingStateOpacity: 0.95
    property double loadedStateOpacity: 0.00
    property int loadingStateFontSize: 75
    property int loadedStateFontSize: 22
    property string loadingStateStr: "◡"
    property string loadedStateStr: ""

    property alias loadingSpinLabel: loadingSpinner;
    property alias rotateAnim: rotateSpinnerAnimation;
    property int changeStateDuration: 750
    property bool isLoading: true;

    Label
    {
        id: loadingSpinner
        font.pixelSize: loadedStateFontSize
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        bottomPadding: height/5
        text: loadingStateStr
        anchors.centerIn: parent

        NumberAnimation on rotation {
            id: rotateSpinnerAnimation
            from: 0; to: 360
            alwaysRunToEnd: true
            loops: -1
        }
    }

    // состояния элемента
    states: [
        State {
            name: "Loading"
            when: mainRect.isLoading
            PropertyChanges {
                target: loadingSpinner
                font.pixelSize: loadingStateFontSize
                text: loadingStateStr
            }
            PropertyChanges {
                target: mainRect
                opacity: loadingStateOpacity
            }
        },
        State {
            name: "Loaded"
            when: !mainRect.isLoading
            PropertyChanges {
                target: loadingSpinner
                font.pixelSize: loadedStateFontSize
                text: loadedStateStr
            }
            PropertyChanges {
                target: mainRect
                opacity: loadedStateOpacity
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
                duration: changeStateDuration
            }
        },
        Transition {
            from: "*"
            to: "Loaded"
            NumberAnimation {
                properties: "font.pixelSize, opacity"
                easing.type: Easing.Linear
                duration: changeStateDuration
            }
        }
    ]

    onIsLoadingChanged: {
        if (isLoading) {
            rotateSpinnerAnimation.start();
        } else {
            rotateSpinnerAnimation.stop();
        }
    }

    // чтобы нельзя было сквозь экран загрузки взаимодействовать
    MouseArea {
        anchors.fill: parent
    }
}
