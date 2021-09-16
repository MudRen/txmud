// stdnpc_2.c

inherit STD_NPC;
 
void create()
{
	string name,id;

	switch(random(5))
	{
		case 0:
			name = "青年"; id = "yong man";
			break;
		case 1:
			name = "书生"; id = "shu sheng";
			break;
		case 2:
			name = "行人"; id = "xing ren";
			break;
		case 3:
			name = "路人"; id = "lu ren";
			break;
		default:
			name = "举子"; id = "ju zi";
			break;

	}

	set_name(name, ({ id }));
	set("long", sprintf("这是一位%s。\n",name));
	set("gender","男性");

	set("age",22);

	set_npc_level(2);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
