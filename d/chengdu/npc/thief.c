// thief.c

inherit NPC;
void create()
{
        set_name("ҹ��", ({ "thief"}) );

        set("gender", "����" );
        set("age", 39);
	set("kar", 30);

        set("no_exp_gain",1); // ���ɵþ���� npc
	set("no_gain_bellicosity", 1); // ɱ�˲��᳤ɱ���� npc

        set("long","һλ��ü���۵������ˡ�\n");
        set("combat_exp", 100000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
	add_money("silver", 1);
}

void die()
{
	object killer, yu;

	if(objectp(killer = query_temp("last_damage_from")))
	{
		yu = new(__DIR__"obj/baiyu");
		yu->set_master(killer->query("id"));
		yu->move(this_object());
	}

	::die();
}
