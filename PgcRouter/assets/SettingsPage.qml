import bb.cascades 1.0

Page {
    id: settingsPage

    signal close()
    
    titleBar: TitleBar {
        id: settingsBar
        title: "Settings"
        visibility: ChromeVisibility.Visible
        dismissAction: ActionItem {
            title: "Close"
            onTriggered: {
                settingsPage.close();
            }
        }
        /*kind: TitleBarKind.Segmented
        options: [
            Option {
                text: "General"
                value: text
            },
            Option {
                text: "Verification"
                value: text
            },
            Option {
                text: "Tracker"
                value: text
            }
        ]*/
    } // titleBar
    RouterContainer {
        layout: DockLayout {
        }

        // A Container for the list is padded at the top and bottom to make room for decorations.
        Container {
            topPadding: 15
            bottomPadding: topPadding
        } // Container
    } // RouterContainer
} // RouterPage
