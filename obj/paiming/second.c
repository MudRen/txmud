// second.c

inherit NPC;
inherit F_SAVE;

void create()
{
	if(!restore())
	{
        set_name("�ڶ�", ({ "second player" }) );
        set("gender", "����" );
        set("age", 10);
        set("combat_exp", 100);
        set("str", 30);
        set("force",2000);
        set("max_force",2000);
        set("force_factor", 20);
	set("max_kee",2000);
	set("kee",2000);
	set("max_gin",2000);
	set("gin",2000);
	set("max_sen",2000);
	set("sen",2000);
	}
	else
		set_name(query("name"),({ query("id")}) );
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

string query_save_file()
{
	return DATA_DIR+"paiming/second";
}