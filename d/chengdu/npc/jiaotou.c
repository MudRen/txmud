// jiaotou.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ﱦ��", ({"sun bao ren"}));
        set("long", "���Ǵ�����ݵĽ�ͷ����˵��ǰ
�����ڽ�������һ�š�\n");

        set("title",HIG"�������--��ͷ"NOR);
        set("gender","����");
        set("age",32);
	set("str", 55);
	set("force",2000);
        set("max_force",2000);
        set("force_factor",30);

	set("max_kee",1200);
	set("max_gin",1200);
	set("max_sen",1200);

        set("combat_exp",150000);

        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",150);
        set_skill("unarmed",150);
	set_skill("axe",100);

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"axe")->wield();
}
