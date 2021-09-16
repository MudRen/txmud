// dizi6
// by dicky

#include <ansi.h>

inherit NPC;

string ask_name();
string ask_caishen();
string ask_password();
string ask_greatwall();

int password_try = 0;


void create()
{
	set_name("̤ѩ���", ({ "taxue qiuchan","qiuchan","girl"}) );
        set("class","taxue");
        create_family("̤ѩɽׯ", 1, "����");

	set("age", 16);
	set("long", "������̤ѩɽׯׯ��������Ѿ����\n");
	set("attitude","heroism");
	set("gender", "Ů��" );
	set("per",100);
	set("str", 100);

        set("combat_exp", 4000000);
        set("max_kee",4000);
        set("kee",4000);
        set("max_gin",4000);
        set("gin",4000);
        set("max_sen",4000);
        set("sen",4000);
        set("force", 4000);
        set("max_force", 4000);
        set("atman", 4000);
        set("max_atman", 4000);
        set("mana", 4000);
        set("max_mana", 4000);
        set("force_factor", 200);

        set_skill("taxue-force",250);
        set_skill("fenghui-sword",250);
        set_skill("xueli-steps",250);
        set_skill("chuanyun-zhang",250);
        set_skill("unarmed",250);
        set_skill("literate",200);
        set_skill("dodge",250);
        set_skill("parry",250);
        set_skill("force",250);
        set_skill("sword",250);

        map_skill("force","taxue-force");
        map_skill("sword","fenghui-sword");
        map_skill("dodge","xueli-steps");
        map_skill("unarmed","chuanyun-zhang");
        map_skill("parry","fenghui-sword");		

	set("inquiry", ([
		"name": (: ask_name :),
		"here": "���ֲ����ˣ���ô֪������",
		"̤ѩ�޺�": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"dicky": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"����" : "�ⶼ��֪����ȥ����������š���",
		"�ʻ�" : "�ȶ��ϰ����ٸ������룡",
		"����" : (: ask_caishen :),
		"���ﳤ�����ﳤ": (: ask_greatwall :),
		"����": (: ask_password :),
	]));

        set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: force_me, "!!!" :),
	}));
	set("chat_chance", 5);
	set("chat_msg", ({
		(: force_me, "chicken" :),
	}));

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
}

void relay_emote(object me, string arg)
{
	switch (arg) {
		case "die":
		case "idle":
		case "sure":
		case "lazy":
		case "xbc97":
		case "smell":
		case "bored":
		case "escape":
		case "chicken":
		case "laughproud":
		case "nonsense":
			command(arg);
			break;
		case "waggle":
		case "willbe":
		case "pain":
		case "push":
		case "puke":
		case "poke":
		case "stare":
		case "admit":
		case "rascal":
		case "story":
		case "crazy":
		case "thank":
		case "name1":
		case "disapp":
		case "disapp1":
		case "accuse":
		case "homework":
		case "papaya":
		case "benger":
		case "sue":
		case "regard":
		case "courage":
		case "meeting":
		case "pat":
		case "pig":
		case "piggy":
		case "flower":
		case "joke":
		case "sigh":
		case "poor":
		case "ugly":
		case "rabbit":
		case "pretty":
		case "knife1":
		case "grpfight":
		case "points":
		case "congra":
		case "sing3":
		case "lover":
		case "nocry":
		case "flatter":
		case "rabbit2":
		case "goodkid":
		case "fire":
		case "boat":
			command(arg + " girl");
			break;
		case "interest":
			command("liar");
			break;
		case "slow":
			command("lover");
			break;
		case "shout":
			command("peace");
			break;
		case "bug":
		case "cook":
			command("taste");
			break;
		case "hero":
		case "hehe":
			command("fear");
			break;
		case "cold":
		case "sing2":
		case "magic":
		case "taste":
			command("escape");
			break;
		case "inn":
		case "sorry":
		case "careful":
			command("sneer");
			break;
		case "kick":
		case "slap":
		case "trip":
			command("pain");
			break;
		case "fire1":
		case "swear":
			command("shake");
			break;
		case ":)":
		case "haha":
		case "xixi":
		case "laugh":
		case "hehehe":
		case "giggle":
			command("nosmile");
			break;
		case "claw":
			command("cry");
			break;
		case "!!!":
		case "gun":
		case "club":
		case "hug":
		case "drug":
		case "doubt":
		case "makeup":
			command("corpse girl");
			break;
		case "shameless":
			command("hate girl");
			break;
		case "admire":
			command("humble girl");
			break;
		case "joythank":
			command("thank girl");
			break;
		case "rhero":
			command("shout girl");
			break;
		case "poem":
			command("raise girl");
			break;
		case "slogan":
			command("slogan2 girl");
			break;
		case "angry":
			command("stare girl");
			break;
		case "happy":
			command("rich girl");
			break;
		case "dare":
			command("points girl");
			break;
		case "lick":
			command("smell girl");
			break;
		case ":(":
		case "cry":
			command("nocry " + me->query("id"));
			break;
		case "xigua":
			command("xigua2 " + me->query("id"));
			break;
		case "nod":
			command("shake " + me->query("id"));
			break;
		case "shake":
			command("nod " + me->query("id"));
			break;
		case "blush":
			command("lover " + me->query("id"));
			break;
		case "monk":
			command("buddhi " + me->query("id"));
			break;
		case "hungry":
			command("rich " + me->query("id"));
			break;
		case "slapsb":
			command("inn " + me->query("id"));
			break;
		case "wait":
			command("nomatch " + me->query("id"));
			break;
		case "lean":
			command("hug " + me->query("id"));
			break;
		case "god":
			command("comfort " + me->query("id"));
			break;
		case "faint":
			command("nofear " + me->query("id"));
			break;
		case "wanfu":
			command("bow " + me->query("id"));
			break;
		case "innocent":
			command("goodman " + me->query("id"));
			break;
		case "yawn":
			command("zzz " + me->query("id"));
			break;
		case "visit":
			command("welcome " + me->query("id"));
			break;
		case "welcome":
			command("visit " + me->query("id"));
			break;
		case "brag":
			command("gun " + me->query("id"));
			break;
		case "dunno":
			command("disapp " + me->query("id"));
			break;
		case "hmm":
			command("? " + me->query("id"));
			break;
		case "poem3":
			command("willbe " + me->query("id"));
			break;
		case "zzz":
			command("shutup " + me->query("id"));
			break;
		case "nomatch":
			command("mother " + me->query("id"));
			break;
		case "nofear":
			command("chicken " + me->query("id"));
			break;
		case "meet":
		case "smell1":
			command("seduce " + me->query("id"));
			break;
		case "rose":
		case "kiss1":
			command("kiss " + me->query("id"));
			break;
		case "rich":
		case "protect":
			command("joythank " + me->query("id"));
			break;
		case "hammer":
		case "killair":
			command("peace " + me->query("id"));
			break;
		case "uncle":
		case "anniversary":
			command("sure " + me->query("id"));
			break;
		case "cut":
		case "corpse":
		case "soup":
		case "smash":
		case "slash":
		case "knife":
			command("peace1 " + me->query("id"));
			break;
		case "thumb":
		case "mother":
		case "praise":
		case "goodman":
		case "applaud":
		case "handsome":
			command("noshame " + me->query("id"));
			break;
		case "bf":
		case "gf":
		case "chitchat":
			command("nonsense " + me->query("id"));
			break;
		case "wave":
		case "bye":
		case "byebye":
		case "goodbye":
			command("slow " + me->query("id"));
			break;
		case "rob":
		case "fat":
		case "dumb":
		case "uncle":
		case "u&me5":
		case "congra1":
		case "marriage":
			command("faint " + me->query("id"));
			break;
		case "love":
		case "lovelook":
		case "loveshoe":
		case "deadlove":
		case "ghostlove":
		case "joycup":
		case "touch1":
		case "wink":
		case "u&me2":
		case "xigua2":
		case "sex":
		case "seduce":
		case "doufu":
		case "oath":
		case "flirt":
			command("puke " + me->query("id"));
			break;
		case "nosmile":
		case "brother":
		case "massage":
			command("goodkid " + me->query("id"));
			break;
		case "ysis":
		case "sister":
		case "aunt":
		case "18mo":
		case "beauty1":
		case "shajiabang1":
			command("uncle " + me->query("id"));
			break;
		case "bite":
		case "grin":
		case "hate":
		case "consider":
			command("fear " + me->query("id"));
			break;
		case "flush":
		case "u&me1":
		case "kill1":
		case "callname":
			command("shout " + me->query("id"));
			break;
		case "agree":
		case "u&me":
		case "raise":
			command("u&me5 " + me->query("id"));
			break;
		default:
			command(arg + " " + me->query("id"));
			break;
	}
}


string ask_name()
{
	if (this_player()->query_temp("girl"))
		return "�Ҿ��ǲ���";
	else
		return "̤ѩ���������ֺ�����";
}

string ask_password()
{
	if (this_player()->query_temp("girl"))
		return "������Ȼ�������Ǻܺüǣ�43420 024 420 ��˱顣";
	else {
		if (password_try < 16012345) password_try += random(10) + 1;
		return "ʲô���룿dicky�ĵ�¼������������" + chinese_number(password_try) + "���ˣ���û�Գ���....";
	}
}

string ask_caishen()
{
	if (this_player()->query_temp("girl"))
		return "��������ҡ�";
	else
		return "�뷢������ˣ���";
}

string ask_greatwall()
{
	this_player()->set_temp("girl", 1);
	return "���ĺ��������硣";
}

int accept_kill(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N�����̤ѩ����¶��֣���Ȼ�������˸���ͷ��Զ������̤ѩ�޺۵�������\n�����ҵ�����Ѿ��Ҳɱ���㲻����ˣ���\n", ob);
	return 0;
}

int accept_fight(object ob)
{
	message_vision("̤ѩ�������$N��У���" + RANK_D->query_rude(ob) + "���б���ɱ��ѽ����\n", ob);
	return 0;
}

