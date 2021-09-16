// xingren.c

#include <ansi.h>
inherit NPC;

void do_say();

void create()
{
	set_name("��·��", ({ "man" }) );
	set("gender", "����" );
	set("age", 20 + random(20));
	set("combat_exp", 18000);

	set("chat_chance", 5);
	set("chat_msg",({
	(: do_say :)
}));

	set("long", "һ����ͨ��·�ˣ���������������·��һ�����
����ʮ������\n");
	set_skill("unarmed",20);

	setup();
	add_money("silver", 1);

	carry_object(ARMOR_DIR"cloth")->wear();
}

void do_say()
{
	string *dir = ({"��Ҵ�","����","¹��"});

	say(CYN"��·�����ҿ���˵������ȥ"+dir[random(sizeof(dir))]+"��֪����������·����\n"NOR);
}