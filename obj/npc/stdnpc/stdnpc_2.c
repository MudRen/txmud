// stdnpc_2.c

inherit STD_NPC;
 
void create()
{
	string name,id;

	switch(random(5))
	{
		case 0:
			name = "����"; id = "yong man";
			break;
		case 1:
			name = "����"; id = "shu sheng";
			break;
		case 2:
			name = "����"; id = "xing ren";
			break;
		case 3:
			name = "·��"; id = "lu ren";
			break;
		default:
			name = "����"; id = "ju zi";
			break;

	}

	set_name(name, ({ id }));
	set("long", sprintf("����һλ%s��\n",name));
	set("gender","����");

	set("age",22);

	set_npc_level(2);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
