import bb.cascades 1.0


Page {
    id: supportPage

    signal close()

    actionBarVisibility: ChromeVisibility.Visible
    actionBarAutoHideBehavior: ActionBarAutoHideBehavior.Default
    titleBar: TitleBar {
        id: supportBar
        title: "Support"
        visibility: ChromeVisibility.Visible
        dismissAction: ActionItem {
            title: "Close"
            onTriggered: {
                supportPage.close();
            }
        }
    } // titleBar
    actions: [
        ActionItem {
            title: "Call"
            imageSource: "asset:///images/ic_show_dialpad.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
            }
        },
        ActionItem {
            title: "Email"
            imageSource: "asset:///images/ic_email.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
            }
        }
    ]
    RouterContainer {
        layout: DockLayout {
        }

        // A Container for the list is padded at the top and bottom to make room for decorations.
        Container {
        } // Container
    } // RouterContainer
} // RouterPage
