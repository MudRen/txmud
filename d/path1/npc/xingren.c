// xingren.c

#include <ansi.h>
inherit NPC;

void do_say();

void create()
{
	set_name("行路人", ({ "man" }) );
	set("gender", "男性" );
	set("age", 20 + random(20));
	set("combat_exp", 18000);

	set("chat_chance", 5);
	set("chat_msg",({
	(: do_say :)
}));

	set("long", "一个普通的路人，像这样的人走在路上一天可以
碰见十几个。\n");
	set_skill("unarmed",20);

	setup();
	add_money("silver", 1);

	carry_object(ARMOR_DIR"cloth")->wear();
}

void do_say()
{
	string *dir = ({"左家村","奉天","鹿马集"});

	say(CYN"行路人左右看看说道：“去"+dir[random(sizeof(dir))]+"不知道该走哪条路。”\n"NOR);
}