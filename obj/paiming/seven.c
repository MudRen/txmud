// seven.c

inherit NPC;

void create()
{
	string name, id, title;
	int exp, age, male;

	if(!PAIMING_D->query_player_data(7, ref name, ref id, ref title, ref exp, ref male, ref age))
	{
		destruct(this_object());
		return;
	}

        set_name(name, ({ sprintf("hero %s", id) }) );
        set("gender", male?"����":"Ů��" );
        set("age", age);
        set("combat_exp", exp);
	set("title",sprintf("�����µ��ߡ�%s", title));

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
