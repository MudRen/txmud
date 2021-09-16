// Room: /d/changan/sxg.c
// by Find.

#undef DEBUG

#include <ansi.h>
#include <room.h>

inherit ROOM;

int query_max_items() { return 100; }

protected int open,time;
protected string *colour = ({ HIY, HIG, HIM });

protected int have_food()
{
	mapping obj;
	object *tables;

	if( !mapp(obj = query_temp("objects"))
	|| !sizeof(obj)
	|| !sizeof(tables = obj[__DIR__"obj/table"]) )
		return -1;

	for(int i=sizeof(tables)-1; i>=0; i--)
		if(tables[i]->is_sxg()
		&& sizeof(filter_array(all_inventory(tables[i]),
			(: $1->is_food() || $1->is_liquid() :) )))
					return 1;
	return 0;
}

protected void begin_play()
{
	if(find_call_out("lasting"))
		remove_call_out("lasting");

	tell_room(this_object(),"\nһ�����ø�ʽ���������Ĺ������������̨��
��������������ġ�����ˡ����ӡ�����������\n\n");
	call_out("lasting",20);
}

protected void lasting()
{
	string *melody = ({
"��̨�ϴ����������ġ�����˼������",
"��������������ġ�����ˡ�����",
"̨�������������ġ���ͥԵ������"
 });

	if((time() - time) > 300 || !have_food())
	{
		object *tables, *inv;
		int i,n,j,k;
		mapping obj;

		if( mapp(obj = query_temp("objects"))
		&& sizeof(obj)
		&& (n = sizeof(tables = obj[__DIR__"obj/table"])) )
			for(i=0; i<n; i++)
				if(tables[i]->is_sxg()
				&& (k = sizeof(inv = all_inventory(tables[i]))) )
					for(j=0;j<k;j++)
						if(inv[j]->is_food() || inv[j]->is_liquid())
							destruct(inv[j]);

		tell_room(this_object(),"\n����ָ����С��ƽ������ϵĲи�ʣ��������ȥ��
��̨�ϵĹ����Ǳ����������ˡ�\n\n");
		return;
	}

	tell_room(this_object(),sprintf("\n%s%s ~ ~ ~ ~ ~ ~\n\n"NOR,
		colour[random(sizeof(colour))],melody[random(sizeof(melody))]));

	call_out("lasting",20);
}

void create()
{
	set("short", BWHT HIR"˫ϲ��"NOR);
	set("long", @LONG
����һ�����������ã���������ڷ������Ŵ�����ľ���ӣ�
��ǰ����һ��Ϸ̨����ſ���һ�߻���һ������Ϸ�����ſڵĺ�
��������Ƕ��һ����������(pai)��
LONG
	);

	set("item_desc",([
	"pai" : "����¥ר�ųа�(order)�����ϯ��ÿ�������ƽ�
"
]));

	set(SAFE_ENV,1);
	set("NONPC",1);

	set("exits", ([
  "westdown" : __DIR__"baoxiang",
]));

	set("objects",([
	__DIR__"obj/table" : 2,
]));

	setup();
	create_door("westdown", "��ľ��", "eastup", DOOR_CLOSED);
}

void init()
{
	add_action("do_order","order");
}

int do_order()
{
	object me = this_player();

	if(!me->query_temp("marry_bai")
#ifndef DEBUG
	|| wizardp(me)
#endif
	)
		return notify_fail("����˵����ֻ���»�򸾲�����������л����ϯ��\n");

	if(open)
		return notify_fail("����˵�����Ե�һ��������ż���\n");

	if(have_food())
		return notify_fail("����˵�����������ϻ���ô�ණ��û�����أ��ȳ�������˵�ɡ�\n");

	if(player_pay(me,50000) != 1)
		return notify_fail("����ҡҡͷ˵��������ϲ��ÿ�������ƽ�\n");

	write("����˵�����ã����Ե�һ�����\n");
	open = 1;
	call_out("do_open",3,me);
	return 1;
}

protected void do_open(object me)
{
	string *all;
	int i,n,j,k;
	object *tables;

	tables = filter_array(query_temp("objects")[__DIR__"obj/table"] - ({0}),
		(: $1->is_sxg() && (environment($1) == this_object()) :));

	if(!(k = sizeof(tables)))
	{
		if(objectp(me))
			tell_object(me,"\n����˵����������ô���˰�������������ʦ�ɣ���\n\n");
		return;
	}

	all = get_dir(sprintf("%shunyan/",NPC_DIR));

	if( !(n = sizeof(all)) )
	{
		if(objectp(me))
			tell_object(me,"\n����˵����ԭ�϶�û�ˣ���������ʦ����ɣ���\n\n");
		return;
	}

	tell_room(this_object(),"\n�������ſ�һվ��������������������ϯ������ඡ�����������\n\n
ֻ�����˵�С����Ǵ�����Ϣ����һ��������ϾͲ�����ɽ�亣ζ��\n\n");

	for(i=0;i<n;i++)
	{
		string file;

		if(file_size(file = sprintf("%shunyan/%s",NPC_DIR,all[i])) > 0)
		{
			for(j=0;j<k;j++)
			{
				object ob = new(file);
				ob->move(tables[j]);
			}
		}
	}

	shout(sprintf(HIR BWHT"\n��%s�ھ���˫ϲ������»�ϲ�����Ҳμӡ�\n\n" NOR,me->name()));

#ifdef __THIS_PLAYER_IN_CALL_OUT__
	tell_object(me,sprintf(HIR BWHT"\n��%s�ھ���˫ϲ������»�ϲ�����Ҳμӡ�\n\n" NOR,me->name()));
#endif

	begin_play();
	open = 0; time = time();
}
