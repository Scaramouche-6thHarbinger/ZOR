using ProjectZ.Common.Protocol.Protobuf;
using Google.Protobuf;

namespace ProjectZ {
    public class API_ZNO_CS_REQ_OPEN_SLOT
    {
        public NetworkPacket ZNO_CS_REQ_OPEN_SLOT(NetworkPacket req, Session session) {
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| API_ZNO_CS_REQ_OPEN_SLOT");
            Console.WriteLine("+-------------------------------------------------------------------");
            byte slot_number = req.U1();
            Console.WriteLine("| slot_number: " + slot_number);
            Console.WriteLine("+-------------------------------------------------------------------");

            NetworkPacket rsp = new NetworkPacket(NetCMDTypes.ZNO_SC_REQ_OPEN_SLOT);
            if (slot_number < 0 || slot_number > 7) {
                Console.WriteLine("| slot_number is invalid");
                Console.WriteLine("+-------------------------------------------------------------------");
                rsp.U2((short)NetACKTypes.ACK_UNKNOWN_ERROR);
                rsp.U1((sbyte)slot_number);
                return rsp;
            }

            if (true == session.user.Slots[slot_number].Open) {
                Console.WriteLine("| slot is already open");
                Console.WriteLine("+-------------------------------------------------------------------");
                rsp.U2((short)NetACKTypes.ACK_UNKNOWN_ERROR);
                rsp.U1((sbyte)slot_number);
                return rsp;
            }

            // get price for new slot from somewhere -> for now just use 100
            // check if user has enough zen
            if (session.user.Zen < 100) {
                Console.WriteLine("| Zen is not enough");
                Console.WriteLine("+-------------------------------------------------------------------");
                rsp.U2((short)NetACKTypes.ACK_NOT_ENOUGH_ZEN);
                rsp.U1((sbyte)slot_number);
                return rsp;
            }
            Slot slot = new Slot();
            slot.Open = true;
            slot.CharacterSeq = 0;
            slot.MakeCharacter = false;
            slot.RemainStatResetCount = 3;

            session.user.SetSlot(slot_number, slot);

            session.user.Zen -= 100;

            rsp.U2((short)NetACKTypes.ACK_OK);
            rsp.U1((sbyte)slot_number);

            // save user
            if (session.user.MainSlotIndex == -1) {
                session.user.MainSlotIndex = (sbyte)slot_number;
                Console.WriteLine("| Set main slot to " + slot_number);
                Console.WriteLine("+-------------------------------------------------------------------");
            }
            session.user.SaveUser();
            return rsp;
        }
    }
}
