// stdnpc_5.c

inherit STD_NPC;
 
void create()
{
	string name,id;

	switch(random(5))
	{
		case 0:
			name = "红脸大汉"; id = "hong da han";
			break;
		case 1:
			name = "青脸大汉"; id = "qing da han";
			break;
		case 2:
			name = "黄脸大汉"; id = "huang da han";
			break;
		default:
			name = "精壮大汉"; id = "jing da han";
			break;

	}

	set_name(name, ({ id }));
	set("long", sprintf("这是一位%s。\n",name));
	set("gender","男性");

	set("age",32);

	set_npc_level(5);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
