// design by ���ֺ�(find) . all right reserved.

// xia.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���Ʒ�", ({ "xia yunfei","yunfei","xia" }) );
        set("gender", "����");
        set("age", 27);
        set("long",     "��һﳤ�ø߸����ݣ�������Ц���������һ�Ѵ�Ƭ������\n");
	set("combat_exp", 1000000);
        set("max_kee", 1500);
        set("max_gin", 1600);
        set("max_sen", 1600);
        set("attitude", "heroism");

	set("max_force",2000);
	set("force",2000);
	set("force_factor",100);

        set_skill("blade", 200);
	set_skill("cibei-blade", 120);
        set_skill("parry", 200);
        set_skill("dodge", 200);
	set_skill("ganchan", 150);

	map_skill("dodge","ganchan");
	map_skill("parry","cibei-blade");
	map_skill("blade","cibei-blade");

        setup();
        carry_object(WEAPON_DIR"blade")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
        add_money("silver", 6);
}

void init()
{
	object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
	{
		this_object()->kill_ob(ob);
        }
}

void die()
{
        object killer;
        if(objectp(killer = query_temp("last_damage_from")))
            killer->set_temp("xia_killer", 1);
        ::die();
}