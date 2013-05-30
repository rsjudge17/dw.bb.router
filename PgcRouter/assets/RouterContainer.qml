import bb.cascades 1.0

Container {
    background: backgroundPaint.imagePaint

    attachedObjects: [
        ImagePaintDefinition {
            id: backgroundPaint
            imageSource: "asset:///images/background.amd"
            repeatPattern: RepeatPattern.XY
        }
    ]
    layout: DockLayout {
    }
}
