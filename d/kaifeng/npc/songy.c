#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�����", ({ "song yufei" , "song" , "yufei" }) );
        set("title",MAG"����--����һ��"NOR);
        set("gender", "Ů��" );
        set("age", 22);
        set("long", "�����������ĵĵڶ������֡�\n");

	set("combat_exp", 800000);
	set("per", 30);
	set("force", 2500);
	set("max_force", 2500);
	set("force_factor", 40);

        set_skill("dodge",100);
        set_skill("parry",120);
        set_skill("unarmed",120);
        set_skill("force",220);
        set_skill("sword",120);

        setup();
	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}
