import bb.cascades 1.0
import bb.cascades.customcomponents 1.0

Page {
    content: Container {
        Button {
            text: "FilePicker from QML"
            onClicked: {
                filePicker.open()
            }
        }
    }
    attachedObjects: [
        FilePicker {
            id: filePicker
            type: FileType.Picture
            title: "Select Picture"
            directories: [ "/accounts/1000/shared/misc" ]
            onFileSelected: {
                console.log("FileSelected signal received : " + selectedFiles);
            }
        }
    ]
}