// stdnpc_6.c

inherit STD_NPC;
 
void create()
{
	string name,id;

	switch(random(5))
	{
		case 0:
			name = "��������"; id = "wu zhe";
			break;
		case 1:
			name = "������ʿ"; id = "wu shi";
			break;
		case 2:
			name = "�н�ɮ"; id = "xing seng";
			break;
		default:
			name = "������ʦ"; id = "biao shi";
			break;

	}

	set_name(name, ({ id }));
	set("long", sprintf("����һλ%s��\n",name));
	set("gender","����");

	set("age",32);

	set_npc_level(6);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
