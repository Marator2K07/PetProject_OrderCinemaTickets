import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
// наши подгруженные модули/плагины в папке qml
import Qml.Custom 1.0
import Qml.Constants 1.0

Page {
    id: root
    background: Rectangle {
        color: ConstColors.defMainBackground
    }

    AdaptiveContextMenu {
        id: contextMenu
        menuOrientation: ListView.Vertical
    }
}
