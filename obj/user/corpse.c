// corpse.c

inherit ITEM;

int decayed;

void create()
{
	set_name("无名尸体", ({ "corpse" }) );
        set("long", "这是一具无名尸体。\n");
	set("unit", "具" );
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
			tell_object(environment(), query("name") + "开始腐烂了，发出一股难闻的恶臭。\n" );
			switch(query("gender"))
			{
				case "男性":
					set_name("腐烂的男尸", ({ "corpse", "尸体" }) );
				case "女性":
					set_name("腐烂的女尸", ({ "corpse", "尸体" }) );
				default:
					set_name("腐烂的尸体", ({ "corpse", "尸体" }) );
			}

			set("long", "这具尸体显然已经躺在这里有一段时间了，正散发著一股腐尸的味道。\n");
			call_out("decay", 120, phase + 1);
			break;
		case 2:
			tell_object(environment(), query("name") + "被风吹乾了，变成一具骸骨。\n" );
			set_name("枯乾的骸骨", ({ "skeleton" }) );
			set("long", "这副骸骨已经躺在这里很久了。\n");
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			tell_object(environment(), "一阵风吹过，把" + query("name") + "化成骨灰吹散了。\n" );
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
	zombie->set_name( (string)query("victim_name") + "的僵尸", ({ "zombie" }) );
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