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
        set("gender", male?"男性":"女性" );
        set("age", age);
        set("combat_exp", exp);
	set("title",sprintf("【天下第七】%s", title));

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
