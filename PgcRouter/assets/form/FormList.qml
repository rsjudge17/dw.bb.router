import bb.cascades 1.0

ListView {
    id: formList
    
    listItemComponents: [
        ListItemComponent {
            type: "header"
            Header {
                title: ListItemData.title

                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
            }
        },
        ListItemComponent {
            type: "formItem"

            StandardListItem {
                id: formItem
                title: ListItemData.title
                description: ListItemData.desc
                status: ListItemData.time
                imageSource: "asset:///images/" + ListItemData.status + ".png"
            }
        }
    ]

    function itemType(data, indexPath) {
        return data.type;
    }
}
