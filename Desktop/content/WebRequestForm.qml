import QtQuick 2.15
import QtQuick.Controls 2.15
import Desktop 1.0

Rectangle {
    id: rectangle
    width: 600
    height: 550
    color: "#ffffff"

    Column {
        id: column
        anchors.fill: parent
        bottomPadding: 10
        rightPadding: 10
        leftPadding: 10
        topPadding: 10
        spacing: 10

        Text {
            id: urlLabel
            text: qsTr("Url:")
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
        }

        Row {
            id: rowUrl
            height: 40
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            spacing: 10

            LineTextInput {
                id: urlTextInput
                height: requestTypeComboBox.height
                anchors.left: parent.left
                anchors.right: requestTypeComboBox.left
                anchors.rightMargin: 10
                anchors.leftMargin: 0
            }

            CustomComboBox {
                id: requestTypeComboBox
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }

        Row {
            id: rowRequest
            height: 40
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            spacing: 10

            Text {
                id: requestLabel
                text: qsTr("Request:")
                anchors.bottom: parent.bottom
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
                anchors.bottomMargin: 5
            }

            CustomComboBox {
                id: requestDataTypeComboBox
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }

        Rectangle {
            id: mediator
            height: rectangle.height / 2
            color: "#ffffff"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: 10
            anchors.rightMargin: 10

            MultiLineTextInput {
                id: multiLineTextInput
                anchors.fill: parent
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Row {
            id: row
            height: 40
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: 10
            anchors.rightMargin: 10

            Text {
                id: statusLabel
                text: qsTr("Status:")
                anchors.bottom: parent.bottom
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
                anchors.bottomMargin: 5
            }

            Text {
                id: statusText
                text: qsTr("...")
                anchors.left: statusLabel.right
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
                clip: true
                anchors.rightMargin: 10
                anchors.leftMargin: 10
                anchors.bottomMargin: 5
            }
        }

        Button {
            id: sendRequestButton
            text: qsTr("Send request")
            anchors.horizontalCenter: parent.horizontalCenter
        }

    }
}

