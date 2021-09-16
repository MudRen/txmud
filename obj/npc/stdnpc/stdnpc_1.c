// hunhun.c

inherit STD_NPC;
 
void create()
{
	string name,id;

	switch(random(6))
	{
		case 0:
			name = "小混混"; id = "xiao hun hun";
			break;
		case 1:
			name = "小流氓"; id = "xiao liu mang";
			break;
		case 2:
			name = "少年"; id = "boy";
			break;
		case 3:
			name = "少女"; id = "girl";
			break;
		default:
			name = "小地痞"; id = "xiao di pi";
			break;

	}

	set_name(name, ({ id }));
	set("long", sprintf("这是一位%s。\n",name));

	if(name == "少女")
		set("gender","女性");
	else
		set("gender","男性");

	set("age",18);

	set_npc_level(1);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
