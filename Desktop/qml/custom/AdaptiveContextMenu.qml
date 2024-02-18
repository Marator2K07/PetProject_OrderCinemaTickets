import QtQuick
import QtQuick.Layouts
// наши подгруженные модули/плагины в папке qml
import Qml.Custom 1.0
import Qml.Constants 1.0

AdaptiveMenu {
    id: root

    property alias menuModel: menuModel
    property alias menuOrientation: menuOrientation
}
