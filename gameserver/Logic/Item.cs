using ProjectZ.Common.Protocol.Protobuf;

namespace ProjectZ.Logic {
    public class Item {
        public enum ItemStatus
        {
            EM_ITEM_STATUS_NORMAL = 0,

            EM_ITEM_STATUS_REG_MARKET	= 10,
            EM_ITEM_STATUS_DESTROY,
            EM_ITEM_STATUS_SELL_STORE,
            EM_ITEM_STATUS_UPSTONE,
            EM_ITEM_STATUS_SEND_MAIL,
            EM_ITEM_STATUS_FAIRY_REBIRTH,
            EM_ITEM_STATUS_FAIRY_SACRIFICE,
            EM_ITEM_STATUS_BATTLEPET_COMBINE,
            EM_ITEM_STATUS_BATTLEPET_EVOLUTION,
            EM_ITEM_STATUS_ITEM_USE,
            EM_ITEM_STATUS_FAIRY_EVOLUTION = 20,
            EM_ITEM_STATUS_UPSTONE_COMBINE,

            EM_ITEM_STATUS_INVALID_ITEM	= 99,
        };

        private ProjectZ.Common.Protocol.Protobuf.Item _item;

        public int Tid {
            get {
                return _item.Tid;
            }
            set {
                _item.Tid = value;
            }
        }

        public int SubType {
            get {
                return _item.SubType;
            }
            set {
                _item.SubType = value;
            }
        }

        public int Quantity {
            get {
                return _item.Quantity;
            }
            set {
                _item.Quantity = value;
            }
        }

        public int ClassType {
            get {
                return _item.ClassType;
            }
            set {
                _item.ClassType = value;
            }
        }

        public int BagType {
            get {
                return _item.BagType;
            }
            set {
                _item.BagType = value;
            }
        }

        public int BagSlotNumber {
            get {
                return _item.BagSlotNumber;
            }
            set {
                _item.BagSlotNumber = value;
            }
        }

        public Item() {
            _item = new ProjectZ.Common.Protocol.Protobuf.Item();
        }
    }
}