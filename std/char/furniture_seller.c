// furniture_seller.c

#include <dbase.h>

inherit NPC;

class furnitures {
	string short;
	string file;
	int value;
}

private class  furnitures *all_furnitures = ({});
private void init_goods();

void setup()
{
	all_furnitures = ({});
	init_goods();
	::setup();
}

private void init_goods()
{
	string *all;
	int i,n;
	class furnitures item;
	object f;

	all = query("furnitures");
	if(!all || !(n = sizeof(all)))
		return;

	for(i=0;i<n;i++)
	{
		item = new(class furnitures);
		f = find_object(all[i]);
		if(!f)
			f = load_object(all[i]);
		if(f)
		{
			item->short = f->short();
			item->file = all[i];
			item->value = f->query("value");
			all_furnitures += ({ item });
		}
	}
}

void init()
{
	add_action("do_buy", ({ "mai","buy" }) );
	add_action("do_list", "list");
	add_action("do_look", "chakan");
}

int do_list()
{
	object env;
	string out;
	int i,n;

	if(!(env = environment())
	|| base_name(env) != query("startroom") )
		return 0;

	if( !(n=sizeof(all_furnitures)) )
		return notify_fail("Ŀǰû�п����ļҾ��ˡ�\n");

	out = "Ŀǰ�����¼Ҿ��ֻ���\n";
	for(i=0;i<n;i++)
		out += sprintf("%-40s%s\n",all_furnitures[i]->short,
			chinese_value(all_furnitures[i]->value));

	write(out);
	return 1;
}

int do_buy(string arg)
{
	object env;
	object me = this_player();
	int i,n,value;

	if(!(env = environment())
	|| base_name(env) != query("startroom") )
		return 0;

	if( ! PLAYERHOME_D->user_have_home(me->query("id")) )
		return notify_fail("�㻹û���Լ���˽լ��Ҿ����ķ�ѽ���Ժ���˵�ɡ�\n");

	if(me->query_temp("furniture"))
		return notify_fail("�㲻���Ѿ����˼Ҿߣ��Ȼ�ȥ���úðɣ�\nС��Ļ��һ��Ҳ�Ͳ�����ô��Ҿߡ�\n");

	if(!stringp(arg))
		return notify_fail("��Ҫ���ļ��Ҿߣ�\n");

	if( !(n=sizeof(all_furnitures)) )
		return notify_fail("Ŀǰû�п����ļҾ��ˡ�\n");

	for(i=0;i<n;i++)
		if(all_furnitures[i]->file->id(arg))
			break;

	if(i>=n)
		return notify_fail("��Ҫ���ļ��Ҿߣ�\n");

	value = all_furnitures[i]->value;

	switch ( player_pay(me,value) )
	{
		case 0:
			return notify_fail("�����ϴ���Ǯ������\n");
        	case 2:
			return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
		default:
			me->set_temp("furniture",all_furnitures[i]->file);
			write(sprintf("�㻨%s������һ%s%s��\n",
				chinese_value(value),
				all_furnitures[i]->file->query("unit"),
				all_furnitures[i]->file->name() ));
			write(sprintf("%sЦ�����Ķ���˵���������ؼ�ѡһ������%s�ĵط��������ϸ�����ȥ����\n",
				name(),all_furnitures[i]->file->name()));
			return 1;
	}
}

int do_look(string arg)
{
	object env;
	int i,n;

	if(!(env = environment())
	|| base_name(env) != query("startroom") )
		return 0;

	if(!stringp(arg))
		return notify_fail("��Ҫ��ϸ�쿴�ļ��Ҿߣ�\n");

	if( !(n=sizeof(all_furnitures)) )
		return notify_fail("û����Ҫ�쿴������Ҿߡ�\n");

	for(i=0;i<n;i++)
		if(all_furnitures[i]->file->id(arg))
			break;

	if(i>=n)
		return notify_fail("��Ҫ��ϸ�쿴�ļ��Ҿߣ�\n");

	write(sprintf("%s\n%s\n",all_furnitures[i]->short,all_furnitures[i]->file->query("long")));
	return 1;
}
