// hunhun.c

inherit STD_NPC;
 
void create()
{
	string name,id;

	switch(random(6))
	{
		case 0:
			name = "С���"; id = "xiao hun hun";
			break;
		case 1:
			name = "С��å"; id = "xiao liu mang";
			break;
		case 2:
			name = "����"; id = "boy";
			break;
		case 3:
			name = "��Ů"; id = "girl";
			break;
		default:
			name = "С��Ʀ"; id = "xiao di pi";
			break;

	}

	set_name(name, ({ id }));
	set("long", sprintf("����һλ%s��\n",name));

	if(name == "��Ů")
		set("gender","Ů��");
	else
		set("gender","����");

	set("age",18);

	set_npc_level(1);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
