using ProjectZ.Logic;

namespace ProjectZ {
    public class ItemResource {
        public ItemResource() {
            
        }

        public int GetItemBagType(Item item) {
            switch ((EnumClassItemTableType)item.SubType) {
                case EnumClassItemTableType.CLASS_ITEM_TABLE_NECKLACE:
                    break;
                default:
                    Console.WriteLine("Unknown item type: " + item.SubType);
                    break;
            }
            return 0;
        }
    }
}