// wubt.c

#include <ansi.h>
inherit NPC;
inherit TEACH_NPC;

void create()
{
        set_name("������ͷ", ({ "wu biaotou" , "biaotou" , "wu" }) );
        set("title",HIW"�����ھ�"NOR);
        set("nicknake",HIR"��������"NOR);
        set("gender", "����" );
        set("age", 42);
        set("long", "������ͷһ��Ӳ���������֡�\n");

	set(NO_KILL, 1);

        set("combat_exp", 600000);
        set("str", 30);
        set("int", 30);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 40);

	set("max_kee",1000);
	set("max_gin",1300);
	set("max_sen",1300);

        set_skill("dodge",120);
	set_skill("parry",120);
        set_skill("unarmed",90);
        set_skill("force",200);
	set_skill("sword",90);
	set_skill("spells",200);
	set_skill("magic",200);

	set_valid_skill( ({ "spells","magic" }) );

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int is_apprentice_of(object ob)
{ return 1; }
