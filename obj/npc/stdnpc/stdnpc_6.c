// stdnpc_6.c

inherit STD_NPC;
 
void create()
{
	string name,id;

	switch(random(5))
	{
		case 0:
			name = "中年武者"; id = "wu zhe";
			break;
		case 1:
			name = "中轻武士"; id = "wu shi";
			break;
		case 2:
			name = "行脚僧"; id = "xing seng";
			break;
		default:
			name = "中年镖师"; id = "biao shi";
			break;

	}

	set_name(name, ({ id }));
	set("long", sprintf("这是一位%s。\n",name));
	set("gender","男性");

	set("age",32);

	set_npc_level(6);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
