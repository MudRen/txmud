// stdnpc_5.c

inherit STD_NPC;
 
void create()
{
	string name,id;

	switch(random(5))
	{
		case 0:
			name = "������"; id = "hong da han";
			break;
		case 1:
			name = "������"; id = "qing da han";
			break;
		case 2:
			name = "������"; id = "huang da han";
			break;
		default:
			name = "��׳��"; id = "jing da han";
			break;

	}

	set_name(name, ({ id }));
	set("long", sprintf("����һλ%s��\n",name));
	set("gender","����");

	set("age",32);

	set_npc_level(5);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
