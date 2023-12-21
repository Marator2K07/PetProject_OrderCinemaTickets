import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import Custom

Rectangle {
    id: rectangle
    width: 600
    height: 550
    color: "#ffffff"

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        spacing: 10

        Text {
            id: urlLabel
            text: qsTr("Url:")
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            Layout.leftMargin: 10
            Layout.topMargin: 5
        }

        RowLayout {
            id: rowUrlLayout
            width: mainLayout.width
            height: 40
            spacing: 10

            LineTextInput {
                id: urlTextInput
                height: rowUrlLayout.height
                Layout.fillWidth: true
                Layout.leftMargin: 10
                Layout.rightMargin: 0
            }

            CustomComboBox {
                id: requestTypeComboBox
                Layout.fillWidth: false
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.rightMargin: 10
            }
        }

        RowLayout {
            id: rowRequestLayout
            width: rectangle.width
            height: 40
            spacing: 10

            Text {
                id: requestLabel
                text: qsTr("Request:")
                font.pixelSize: 20
                Layout.fillWidth: true
                Layout.leftMargin: 10
            }

            CustomComboBox {
                id: requestDataTypeComboBox
                Layout.rightMargin: 10
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            }
        }

        Rectangle {
            id: mediator
            height: mainLayout.height * (4/5)
            color: "#ffffff"
            Layout.fillHeight: true
            Layout.rightMargin: 10
            Layout.leftMargin: 10
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            MultiLineTextInput {
                id: requestDataTextInput
                anchors.fill: parent
            }
        }

        RowLayout {
            id: rowStatusLayout
            width: mainLayout.widths
            height: 40
            Layout.rightMargin: 10
            Layout.leftMargin: 10
            spacing: 10
            Layout.fillWidth: false

            Text {
                id: statusLabel
                width: contentWidth
                text: qsTr("Status:")
                font.pixelSize: 20
            }

            Text {
                id: statusText
                width: mainLayout.width - statusLabel.width - 30
                text: qsTr("...")
                font.pixelSize: 20
                clip: true
            }
        }

        Button {
            id: sendRequestButton
            text: qsTr("Send request")
            Layout.bottomMargin: 10
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }
}

