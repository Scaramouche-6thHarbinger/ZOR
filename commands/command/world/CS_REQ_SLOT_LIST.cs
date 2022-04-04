namespace ProjectZ {
    public class API_ZNO_CS_REQ_SLOT_LIST
    {
        public NetworkPacket ZNO_CS_REQ_SLOT_LIST(NetworkPacket req, Session session) {
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| API_ZNO_CS_REQ_SLOT_LIST");
            Console.WriteLine("+-------------------------------------------------------------------");

            NetworkPacket rsp = new NetworkPacket(NetCMDTypes.ZNO_SC_REQ_SLOT_LIST);
            rsp.U1(session.user.MainSlotIndex);
            // if (useViewIntroState)
            rsp.U1(session.user.IntroState);
            // else
            // rsp.U1(5);
            int count = 0;
            foreach (var slot in session.user.Slots) {
                if (slot.Open == true) {
                    count++;
                }
            }

            rsp.U2((short)count);
            foreach (var slot in session.user.Slots.Select((value, i) => new { i, value })) {
                if (slot.value.Open == true) {
                    Console.WriteLine("| open slot_number: " + slot.i);
                    Console.WriteLine("+-------------------------------------------------------------------");
                    rsp.U2((short)slot.i);
                    rsp.U2((short)slot.value.RemainStatResetCount);
                }
            }

            int characterMaxCount = 0;
            foreach (var slot in session.user.Slots) {
                if (slot.Open == true && slot.MakeCharacter == true && slot.CharacterSeq != 0) {
                    characterMaxCount++;
                }
            }
            rsp.U2((short)characterMaxCount);

            foreach (var slot in session.user.Slots.Select((value, i) => new { i, value })) {
                if (slot.value.Open == true && slot.value.MakeCharacter == true && slot.value.CharacterSeq != 0) {
                    rsp.U2((short)session.user.Characters[slot.i].Slotindex);
                    rsp.U2((short)session.user.Characters[slot.i].Classtype);
                    rsp.U2((short)session.user.Characters[slot.i].Level);
                    // TODO: convert to "Wed Feb 13 15:46:11 2013" time format
                    String strTime = "Wed Feb 13 15:46:11 2013";
                    rsp.U2((short)strTime.Length);
                    rsp.Set(strTime);
                    rsp.U1((sbyte)session.user.Characters[slot.i].DrillStatus);
                    rsp.U1((sbyte)session.user.Characters[slot.i].DrillTime);
                    rsp.U8((long)(session.user.Characters[slot.i].DrillEnd - session.user.Characters[slot.i].DrillStart));

                    if (session.user.Characters[slot.i].AvartarIconidx == 1000) {
                        rsp.U2((short)session.user.Characters[slot.i].HelmetIconidx);
                        rsp.U2((short)session.user.Characters[slot.i].ArmorIconidx);
                        rsp.U2((short)session.user.Characters[slot.i].WeaponIconidx);
                        rsp.U2((short)session.user.Characters[slot.i].WeaponIconidx);
                        rsp.U2(0);
                    } else {
                        rsp.U2((short)(session.user.Characters[slot.i].AvartarIconidx + 100));
                        rsp.U2((short)(session.user.Characters[slot.i].AvartarIconidx + 100));
                        rsp.U2((short)(session.user.Characters[slot.i].AvartarIconidx + 100));
                        rsp.U2((short)(session.user.Characters[slot.i].AvartarIconidx + 100));
                        rsp.U2(0);
                    }
                }
            }
            sbyte MAX_CLASS_TYPE = 5;
            rsp.U1(MAX_CLASS_TYPE);
            for (int i = 0; i < MAX_CLASS_TYPE; i++) {
                // TODO get real stat data from xls
                rsp.U1(5); //STAT_STR
                rsp.U1(5); //STAT_DEX
                rsp.U1(5); //STAT_CON
                rsp.U1(5); //STAT_SPI
            }
            return rsp;
        }
    }
}
