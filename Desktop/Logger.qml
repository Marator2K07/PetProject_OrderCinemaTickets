import QtQuick
import QtQuick.Window
import Qml.Custom 1.0 // наш подгруженный модуль/плагин в папке qml

Window {
    WindowLogger {

    }

    width: 640
    height: 480
    visible: true
    title: qsTr("Logger")
}
