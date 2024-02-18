import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
 // наши подгруженные модули/плагины в папке qml
import Qml.Custom 1.0
import Qml.Pages 1.0

Window {
    // CustomComboBox - элемент из модуля custom
    CustomComboBox {

    }


    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")    
}
