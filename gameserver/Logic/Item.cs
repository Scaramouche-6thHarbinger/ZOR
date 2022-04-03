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

        public struct Data {
            int bag_type;
            int bag_slot_number;
            int stack_num;
            int sub_type;
            int class_type;
            int tid;
            int item_type;
            int iconidx;

            int cur_duration;
            int max_duration;
            int quantity;
            int set_type;
            int non_identity;
            int cur_refine_step;
            int quality;
            int level;

            int[] eff_type = new int[7];
            int[] eff_pos = new int[7];
            int[] eff_value = new int[7];

            int open_upgrade_stone_slot;
            int ability_enhance_rate;
            int max_enhance_step;
            int buy_use;
            int evolve_step;
            int evolve_max;
            int evolve_point;
            int evolve_percent;
            int evolve_value;

            long reg_date;

            public Data() {
                bag_type = 0;
                bag_slot_number = 0;
                stack_num = 0;
                sub_type = 0;
                class_type = 0;
                tid = 0;
                item_type = 0;
                iconidx = 0;

                cur_duration = 0;
                max_duration = 0;
                quantity = 0;
                set_type = 0;
                non_identity = 0;
                cur_refine_step = 0;
                quality = 0;
                level = 0;

                for (int i = 0; i < 7; i++) {
                    eff_type[i] = 0;
                    eff_pos[i] = 0;
                    eff_value[i] = 0;
                }

                open_upgrade_stone_slot = 0;
                ability_enhance_rate = 0;
                max_enhance_step = 0;
                buy_use = 0;
                evolve_step = 0;
                evolve_max = 0;
                evolve_point = 0;
                evolve_percent = 0;
                evolve_value = 0;

                reg_date = 0;
            }

            public void Clear() {
                bag_type = 0;
                bag_slot_number = 0;
                stack_num = 0;
                sub_type = 0;
                class_type = 0;
                tid = 0;
                item_type = 0;
                iconidx = 0;

                cur_duration = 0;
                max_duration = 0;
                quantity = 0;
                set_type = 0;
                non_identity = 0;
                cur_refine_step = 0;
                quality = 0;
                level = 0;

                for (int i = 0; i < 7; i++) {
                    eff_type[i] = 0;
                    eff_pos[i] = 0;
                    eff_value[i] = 0;
                }

                open_upgrade_stone_slot = 0;
                ability_enhance_rate = 0;
                max_enhance_step = 0;
                buy_use = 0;
                evolve_step = 0;
                evolve_max = 0;
                evolve_point = 0;
                evolve_percent = 0;
                evolve_value = 0;

                reg_date = 0;
            }
        }

        public Item() {
            
        }
    }
}