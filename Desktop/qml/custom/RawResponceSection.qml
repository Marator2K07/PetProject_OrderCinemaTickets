import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    anchors.fill: parent

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        MyMultiLineText {
            id: requestDataTextInput
            textItem.text: loggerModel.messages
            textItem.readOnly: true
            textItem.font.pixelSize: 22
            textItem.leftPadding: 8
            hoverEnabled: false
            vBarWidth: 10
            isActive: false
            border.width: 1
            radius: 4
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }

    LoadingScreen {
        rotateAnim.duration: 650
        loadingSpinLabel.height: 39
    }
}
