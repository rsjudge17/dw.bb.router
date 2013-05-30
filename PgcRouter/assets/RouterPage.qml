import bb.cascades 1.0

Page {
    property alias titleBarText: titleBar.title
    actionBarVisibility: ChromeVisibility.Visible
    actionBarAutoHideBehavior: ActionBarAutoHideBehavior.Default
    titleBar: TitleBar {
        id: titleBar
        visibility: ChromeVisibility.Visible
        scrollBehavior: TitleBarScrollBehavior.Sticky
    }
}
