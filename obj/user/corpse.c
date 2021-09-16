// corpse.c

inherit ITEM;

int decayed;

void create()
{
	set_name("����ʬ��", ({ "corpse" }) );
        set("long", "����һ������ʬ�塣\n");
	set("unit", "��" );
	decayed = 0;
	if( clonep(this_object()) )
		call_out("decay", 120, 1);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
	decayed = phase;

	if(!environment())
	{
		destruct(this_object());
		return;
	}

	switch(phase)
	{
		case 1:
			tell_object(environment(), query("name") + "��ʼ�����ˣ�����һ�����ŵĶ����\n" );
			switch(query("gender"))
			{
				case "����":
					set_name("���õ���ʬ", ({ "corpse", "ʬ��" }) );
				case "Ů��":
					set_name("���õ�Ůʬ", ({ "corpse", "ʬ��" }) );
				default:
					set_name("���õ�ʬ��", ({ "corpse", "ʬ��" }) );
			}

			set("long", "���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n");
			call_out("decay", 120, phase + 1);
			break;
		case 2:
			tell_object(environment(), query("name") + "���紵Ǭ�ˣ����һ�ߺ��ǡ�\n" );
			set_name("��Ǭ�ĺ���", ({ "skeleton" }) );
			set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			tell_object(environment(), "һ��紵������" + query("name") + "���ɹǻҴ�ɢ�ˡ�\n" );
			if( environment() )
			{
				object *inv;
				int i;

				inv = all_inventory(this_object());
				for(i=0; i<sizeof(inv); i++)
					if(inv[i]->query("value") || inv[i]->value() || userp(inv[i]))
					/* by Find. for combined ob's value. && user ob */
						inv[i]->move(environment());
			}
			destruct(this_object());
			break;
	}
}

object animate(object who, int level)
{
	object zombie;
	int zskill;

        if( !environment() )
		return 0;
	seteuid(getuid());
	zombie = new("/obj/npc/zombie");
	zombie->set_name( (string)query("victim_name") + "�Ľ�ʬ", ({ "zombie" }) );
	zombie->move(environment());
	zombie->animate(who);

	zskill = level/2 - 25;
        if(zskill < 1)
		zskill = 1;
	zombie->set_skill("unarmed", zskill);
	zombie->set_skill("dodge", zskill);
	zombie->set("combat_exp", zskill*zskill*zskill);
	destruct(this_object());
	return zombie;
}