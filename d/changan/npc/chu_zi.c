// chu_zi.c

#include <ansi.h>

inherit NPC;
 
void create()
{
	set_name("�ฮ���", ({"cooker"}));

	set("long", "�����ة�ฮ�Ĵ������˵��������һ����");
	set("gender","����");

        set("age",15);
        set("con",20);
        set("str",20);

	set("chat_chance", 5);
	set("chat_msg",({
		CYN"�ฮ���˵������������ζ����������\n"NOR,
		CYN"�ฮ���˵�������峴��ը���������ֲ赭������ζ����\n"NOR,
}));

	set_skill("unarmed",40);

        set("combat_exp",5000+random(1000));

        setup();
        carry_object(__DIR__"obj/weiqun")->wear();
}
