// file: globals.h
//
// Modified by Find.

// for v22.1.b22 driver.
#ifdef __SENSIBLE_MODIFIERS__
#define private protected
#define static nosave
#endif

// This is for encode.If you undef this lable,
// do not forget to disable "convertd" in preload,
// that can free about 900k RAM.
// by Find.
#undef GB_AND_BIG5
// end.

// ͳһ busy �ķ�����Ϣ��
#define BUSY_MESSAGE		"������æ�úܣ��޷����κ����顣\n"

// if defined user can input ansi ESC.
#undef USER_INPUT_ANSI

// if defined this,wizard's object can be under control.
#define WIZARD_FLAG

// �˵�ַΪ��Ϸ��������Ĺ�����ַ��
#define PUBLIC_MUD_MAIL		"admin@mudtx.com"

// �ܱ���������
#define PROTECT_AGE		16

// ��ȫ����
#define SAFE_ENV		"Safe_Environment"
#define NO_KILL			"Cant_Fight_NPC"

// Directories
#define BACKUP_DIR		"/backup/"
#define BANGHUI_DIR		"/banghui/"
#define COMMAND_DIR             "/cmds/"
#define CONFIG_DIR              "/adm/etc/"
#define DATA_DIR                "/data/"
#define FUR_DIR			"/obj/furniture/"	// find.
#define HELP_DIR                "/doc/"
#define LOG_DIR                 "/log/"
#define ARMOR_DIR		"/obj/armor/"
#define BOOK_DIR		"/obj/book/"
#define DRUG_DIR		"/obj/drug/"
#define MISC_DIR		"/obj/misc/"
#define FOOD_DIR		"/obj/food/"
#define LIQUID_DIR		"/obj/liquid/"
#define MONEY_DIR		"/obj/money/"
#define NEWS_DIR		"/data/news/"
#define NPC_DIR			"/obj/npc/"
#define PHOME_DIR		"/d/phome/"	// playerhome dir. Find.
#define QUEST_DIR		"/quest/"	// Find
#define RIDE_DIR		"/obj/ride/"
#define WEAPON_DIR		"/obj/weapon/"
#define WIZ_DIR			"/wiz/"

// Cmds	by Find.
#define UPDATE_CMD              "/cmds/wiz/update"
#define UNRIDE_CMD              "/cmds/std/unride"
#define GUARD_CMD               "/cmds/std/guard"
#define BAN_CMD			"/cmds/arch/ban"
#define CLONE_CMD		"/cmds/wiz/clone"

// Daemons
#define ALIAS_D                 "/adm/daemons/aliasd"
#define AHACK_D			"/adm/daemons/avoid_hacker_d" // Find.
#define BAN_D	 	        "/adm/daemons/ban_d"   // find.
#define BANGHUI_D		"/adm/daemons/banghui_d"	// ����漰�Ĺ���ģ��
#define BASE64_D		"/adm/daemons/base64_d"	// Find.
#define BUSINESS_D		"/adm/daemons/business_d"	// Find
#define CHANNEL_D               "/adm/daemons/channeld"
#define CHAR_D                  "/adm/daemons/chard"
#define CHINESE_D               "/adm/daemons/chinesed"
#define CONVERT_D               "/adm/daemons/convertd" // added for encode
#define COMBAT_D                "/adm/daemons/combatd"
#define COMMAND_D               "/adm/daemons/cmd_d"
#define CRIME_D			"/adm/daemons/crime_d.c" // Find. �����¼.
#define CRON_D			"/adm/daemons/cron_d"	// Find
#define CTLOB_D			"/adm/daemons/ctlob_d.c"	//by Find. �����ܿ�
#define DATABASE_D		"/adm/daemons/databased"	// by Find
#define EMOTE_D                 "/adm/daemons/emoted"
#define FINANCE_D		"/adm/daemons/finance_d" // by Find.
#define FINGER_D                "/adm/daemons/fingerd"
#define INQUIRY_D               "/adm/daemons/inquiryd"
#define IP_D			"/adm/daemons/ip_d"	// by Find.
#define LOGIN_D                 "/adm/daemons/logind"
#define MINE_D			"/adm/daemons/mine_d"	// Find
#define NAME_D			"/adm/daemons/named"  // added by Find.
#define NATURE_D                "/adm/daemons/natured"
#define NEWS_D			"/adm/daemons/news_d"	// by Find.
#define PAIMING_D		"/adm/daemons/paiming_d"  //added by Find.
#define PAWN_D			"/adm/daemons/pawn_d"	// by Find.
#define PLAYERHOME_D		"/adm/daemons/playerhomed" // added by Find.
#define PROFILE_D               "/adm/daemons/profiled"
#define RANK_D                  "/adm/daemons/rankd"
#define RENYI_D			"/adm/daemons/renyi_d"	// by Find.
#define SECURITY_D              "/adm/daemons/securityd"
#define SMTP_D			"/adm/daemons/smtp_d"	// by Find.
#define UPDATE_D                "/adm/daemons/updated"
#define VIRTUAL_D               "/adm/daemons/virtuald"
#define WEAPON_D                "/adm/daemons/weapond"
#define CLASS_D(x)              ("/daemon/class/" + x)

// modified by Find. �����书��Ŀ¼����.
#define SKILL_D(x)		search_skill(x)

#define CONDITION_D(x)  ("/daemon/condition/" + x)

// Clonable/Non-inheritable Standard Objects
#define COIN_OB                 "/obj/money/coin"
#define CORPSE_OB               "/obj/user/corpse"
#define LOGIN_OB                "/obj/user/login"
#define LIGHT_OB		"/std/item/light_ob"	// Find.
#define MASTER_OB               "/adm/obj/master"
#define MAILBOX_OB              "/obj/user/mailbox"
#define MARRYCARD_OB		"/obj/user/marry_card"
#define SILVER_OB               "/obj/money/silver"
#define GOLD_OB                 "/obj/money/gold"
#define THCASH_OB               "/obj/money/thousand-cash"
#define SIMUL_EFUN_OB   	"/adm/obj/simul_efun"
#define USER_OB                 "/obj/user/user"
#define VOID_OB                 "/d/wiz/void"
#define PRISON_OB		"/d/wiz/prison" // ����.

// Inheritable Standard Objects
#define BANK                    "/std/room/bank"
#define BOARD			"/std/nboard"
#define CHARACTER               "/std/char"
#define CLASS_GUILD             "/std/room/class_guild"
#define COMBINED_ITEM   	"/std/item/combined"
#define DANGER_ROAD             "/std/room/danger_road"        // added by find.
#define DOCTOR			"/std/char/doctor"	// Find.
#define DUCHANG			"/std/room/duchang"	// find.
#define EQUIP                   "/std/equip"
#define FORCE                   "/std/force"
#define FURNITURE_SELLER	"/std/char/furniture_seller"	// Find
#define DRUGGER			"/std/char/drugger"	// Find.
#define HOCKSHOP                "/std/room/hockshop"
#define ITEM                    "/std/item"
#define LIQUID                  "/std/liquid"
#define LIGHT_ROOM		"/std/room/lightroom"	// Find.
#define MONEY                   "/std/money"
#define NPC                     "/std/char/npc"
#define POISON			"/std/medicine/poison"	//Find.
#define POWDER                  "/std/medicine/powder"
#define QUESTER			"/std/char/quest_npc"	// Find
#define RIDE_SELLER		"/std/char/ride_seller" // Find
#define ROOM                    "/std/room"
#define SHOP			"/std/room/shop"
#define SHOW_MSG		"/std/room/openclose_msg" // Find
#define SKI_ZHEN		"/std/array"		// Find
#define SKILL                   "/std/skill"
#define SMITH			"/std/char/smith"	// Find.
#define STD_NPC			"/std/char/std_npc"	// Find.
#define SSERVER                 "/std/sserver"
#define TEACH_NPC		"/std/char/teach_npc"	// Find
#define VRM_SERVER		"/adm/daemons/vrm_server"	// Find.
#define WILD			"/std/char/wild"		// Find
#define WAREHOUSE		"/std/room/warehouse"		// Find
#define WILDCARD		"@@WildCard@@"	// just for special ask, by Find.

// User IDs
#define ROOT_UID                "Root"
#define BACKBONE_UID    	"Backbone"

// Features

#define F_ACTION                "/feature/action.c"
#define F_ALIAS                 "/feature/alias.c"
#define F_APPRENTICE    	"/feature/apprentice.c"
#define F_ATTACK                "/feature/attack.c"
#define F_ATTRIBUTE             "/feature/attribute.c"
#define F_AUTOLOAD              "/feature/autoload.c"
#define F_BANGHUI		"/feature/banghui.c"
#define F_BUSINESS		"/feature/business"	// Find
#define F_CLEAN_UP              "/feature/clean_up.c"
#define F_COMMAND               "/feature/command.c"
#define F_CONDITION             "/feature/condition.c"
#define F_CONTROL		"/feature/control.c"	// Find
#define F_DAMAGE                "/feature/damage.c"
#define F_DBASE                 "/feature/dbase.c"
#define F_DEALER		"/std/char/dealer"	//shany
#define F_DTIME			"/feature/dtime.c"	// Find
#define F_ENCODING              "/feature/encoding.c"   // added for encode
#define F_EDIT                  "/feature/edit.c"
#define F_EQUIP                 "/feature/equip.c"
//#define F_FINANCE               "/feature/finance.c"
#define F_FLAG                  "/feature/flag_ob.c"  // add by Find.
#define F_FOOD                  "/feature/food.c"
#define F_LIQUID                "/feature/liquid.c"
#define F_MASTER		"/feature/master"
#define F_MESSAGE               "/feature/message.c"
#define F_MORE                  "/feature/more.c"
#define F_MOVE                  "/feature/move.c"
#define F_NAME                  "/feature/name.c"
#define F_NATURE                "/feature/nature.c" // added by Find.
#define F_SAVE                  "/feature/save.c"
#define F_SELF			"/feature/self.c" // by Find.
#define F_SKILL                 "/feature/skill.c"
#define F_TEAM                  "/feature/team.c"
//#define F_TREEMAP               "/feature/treemap.c"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS
