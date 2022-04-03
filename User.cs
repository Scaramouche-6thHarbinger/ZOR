using ProjectZ.Common.Protocol.Protobuf;
using ProjectZ.Common.Protocol;
using ProjectZ;
using Google.Protobuf;

namespace ProjectZ {
    public class User {
        private ProjectZUser mUser;
        public string encryption_key { get; set; }
        public bool isAuth { get; set; }
        public uint gid { get; set; }

        public User() {
            mUser = new ProjectZUser();
            mUser.Info = new UserInfo();
            mUser.Social = new SocialInfo();
            for (int i = 0; i < 8; i++) {
                mUser.Character.Add(new CharacterInfo());
            }
        }

        public string Nickname {
            get {
                return mUser.Info.Nickname;
            }
            set {
                mUser.Info.Nickname = value;
            }
        }

        public string SocialID {
            get {
                return mUser.SocialId;
            }
            set {
                mUser.SocialId = value;
            }
        }

        public string ProfileUrl {
            get {
                return mUser.Info.ProfileUrl;
            }
            set {
                mUser.Info.ProfileUrl = value;
            }
        }

        public string Uuid {
            get {
                return mUser.Info.Uuid;
            }
            set {
                mUser.Info.Uuid = value;
            }
        }

        public uint Company {
            get {
                return mUser.Info.Company;
            }
            set {
                mUser.Info.Company = value;
            }
        }

        public uint SaleCode {
            get {
                return mUser.Info.SaleCode;
            }
            set {
                mUser.Info.SaleCode = value;
            }
        }

        public uint WpCurWeek {
            get {
                return mUser.Info.WpCurWeek;
            }
            set {
                mUser.Info.WpCurWeek = value;
            }
        }

        public uint HeartBlocked {
            get {
                return mUser.Info.HeartBlocked;
            }
            set {
                mUser.Info.HeartBlocked = value;
            }
        }

        public uint ProfileOpened {
            get {
                return mUser.Info.ProfileOpened;
            }
            set {
                mUser.Info.ProfileOpened = value;
            }
        }

        public int InviteBlocked {
            get {
                return mUser.Social.InviteBlocked;
            }
            set {
                mUser.Social.InviteBlocked = value;
            }
        }

        public int Gender {
            get {
                return mUser.Social.Gender;
            }
            set {
                mUser.Social.Gender = value;
            }
        }

        public int IsGenderOpen {
            get {
                return mUser.Social.IsGenderOpen;
            }
            set {
                mUser.Social.IsGenderOpen = value;
            }
        }

        public string Birthday {
            get {
                return mUser.Social.Birthday;
            }
            set {
                mUser.Social.Birthday = value;
            }
        }

        public int IsBirthdayOpen {
            get {
                return mUser.Social.IsBirthdayOpen;
            }
            set {
                mUser.Social.IsBirthdayOpen = value;
            }
        }
        public User CreateUser(string social_id) {
            mUser = new ProjectZUser();
            mUser.Info = new UserInfo();
            mUser.Social = new SocialInfo();
            for (int i = 0; i < 8; i++) {
                mUser.Character.Add(new CharacterInfo());
            }
            mUser.SocialId = social_id;
            mUser.Info.Userseq = 0;
            for (int i = 0; i < 8; i++) {
                Slot slot = new Slot();
                slot.Open = false;
                slot.CharacterSeq = 0;
                slot.MakeCharacter = false;
                slot.RemainStatResetCount = 0;
                slot.Classtype = 0;
                slot.Level = 0;
                slot.RegDate = 0;
                mUser.Info.ArraySlot.Add(slot);
            }
            mUser.Info.MainSlotIndex = -1;
            mUser.Info.Nickname = "";
            mUser.Info.ProfileUrl = "";
            mUser.Info.Score = 0;
            mUser.Info.HeartBlocked = 0;
            mUser.Info.InviteBlocked = 0;
            mUser.Info.ProfileOpened = 0;
            mUser.Info.Company = 0;
            mUser.Info.SaleCode = 0;
            mUser.Info.U8IntroState = 0;
            mUser.Info.WpLastWeek = 0;
            mUser.Info.WpCurWeek = 0;
            mUser.Info.WpRegDate = 0;
            for (int i = 0; i < 4; i++) {
                mUser.Info.ArrayTutorial.Add(0);
            }
            mUser.Info.Uuid = "";
            mUser.Info.BattleAftereffectTime = 0;
            mUser.Info.Reward = "";
            mUser.Info.ShardItemDbType = 0;
            mUser.Info.WpLastRegDate = 0;
            mUser.Info.Reserve1 = 0;
            mUser.Info.Reserve2 = 0;
            mUser.Info.Reserve3 = 0;
            mUser.Info.Reserve4 = 0;
            mUser.Info.Reserve5 = 0;
            mUser.Info.WorldbossHit = 0;
            mUser.Info.WorldbossPoint = 0;

            mUser.Social.HeartCount = 0;
            mUser.Social.HeartBlocked = 0;
            mUser.Social.InviteBlocked = 0;
            mUser.Social.ProfileOpened = 0;
            mUser.Social.Gender = 0;
            mUser.Social.IsGenderOpen = 0;
            // current date to string in format 20220101
            mUser.Social.Birthday = "20220101";
            mUser.Social.IsBirthdayOpen = 0;
            return this;
        }

        public bool Exists() {
            return mUser.SocialId != "";
        }

        public bool Exists(string social_id) {
            return LoadUser(social_id) == null ? false : true;
        }

        public User LoadUser(string social_id) {
            mUser = new ProjectZUser();
            mUser.SocialId = social_id;
            if (File.Exists(social_id + ".mbn")) {
                mUser = ProjectZUser.Parser.ParseFrom(File.ReadAllBytes(social_id + ".mbn"));
                return this;
            } else {
                return CreateUser(social_id);
            }
        }

        public void SaveUser() {
            File.WriteAllBytes(mUser.SocialId + ".mbn", mUser.ToByteArray());
        }
    }
}