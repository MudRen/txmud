// iron_stone.c

inherit ITEM;

string master;

int is_huashan_tiekuang() { return 1; }
void set_master(string arg)
{
	if(stringp(arg) && (arg != ""))
		master = arg;
}

string query_master() { return master; }

void create()
{
	int weight;

	weight = (random(3) + 1)*5000;

	switch (weight)
	{
		case 5000:
			set_name("Сʯͷ", ({ "iron stone","stone" }) );
			break;
		case 10000:
			set_name("ʯͷ", ({ "iron stone","stone" }) );
			break;
		case 15000:
			set_name("��ʯͷ", ({ "iron stone","stone" }) );
	}

	set_weight(weight);
	set("unit", "��");
	set("long", "һ���ںڵ�����ʯ��\n");
	set("material", "stone");
	setup();

	if(clonep())
		call_out("do_dest",360);
}

private void do_dest()
{
	if(environment())
		tell_object(environment(),sprintf("%s�ŵ�ʱ���������ʧ�ˡ�\n",name()));
	destruct(this_object());
}
