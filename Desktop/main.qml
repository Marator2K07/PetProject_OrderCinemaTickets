import QtQuick
import QtQuick.Window
import Custom // наш подгруженный модуль/плагин в папке qml

Window {
    // LineTextInput - элемент из модуля custom
    LineTextInput {

    }

    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
}

