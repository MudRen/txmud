// xiazi.c
// by dicky

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("̤ѩ��Զ", ({ "taxue jingyuan","jingyuan","master"}) );
	set_auto_recover(1);
	set("gender", "����" );
	set("title",HIY"̤ѩׯ������ׯ��"NOR);
	set("age", 53);
	set("long", "���³��ۣ���Ŀ���㣬һ��������硣������̤ѩׯ������ׯ����\n");
	set("attitude","heroism");
	set("combat_exp", 100000);
	set("per",30);
	set("str", 30);

	set("max_kee",4000);
	set("max_gin",4000);
	set("gin",1000);
	set("max_sen",4000);
	set("max_force", 4000);
	set("max_mana", 2000);
	set("force_factor", 100);
	set("chat_chance_combat",25);
//	set("chat_msg_combat",({
//		(: perform_action, "stick.xiangmo" :),
//	}));

	set_skill("unarmed",300);
	set_skill("dodge",300);
	set_skill("parry",300);
	set_skill("literate",300);
	set_skill("force",300);
	set_skill("sword",300);
	set_skill("taxue-force",300);

	map_skill("force","taxue-force");

	setup();
	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}
