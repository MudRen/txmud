// stdnpc_3.c

inherit STD_NPC;
 
void create()
{
	string name,id;

	switch(random(5))
	{
		case 0:
			name = "׳��"; id = "zhuang han";
			break;
		case 1:
			name = "��"; id = "da han";
			break;
		case 2:
			name = "�к�"; id = "xian han";
			break;
		case 3:
			name = "����"; id = "tiao fu";
			break;
		default:
			name = "����"; id = "ku li";
			break;

	}

	set_name(name, ({ id }));
	set("long", sprintf("����һλ%s��\n",name));
	set("gender","����");

	set("age",32);

	set_npc_level(3);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
