// Room: /d/changan/jiulou3.c
// by Find.

#undef DEBUG

#include <ansi.h>

inherit ROOM;
inherit F_SAVE;

class top
{
	string cname;
	string id;
	int gold;
}

protected class top *my_top = ({});
protected nosave string now;
protected nosave int fd;

string query_save_file() { return __DIR__"jiulou3"; }
protected int sort_topten(class top t1, class top t2);
string pai_msg();

int query_max_items() { return 100; }

protected nosave int open,time;
protected nosave string *colour = ({ HIY, HIG, HIM });

protected void do_refresh()
{
	set("short", "����¥����");
	now = 0;
	fd = 0;
	open = 0;
}

protected int have_food()
{
	mapping obj;
	int j,k;
	object *tables, *inv;

	if( !mapp(obj = query_temp("objects"))
	|| !sizeof(obj)
	|| !sizeof(tables = obj[__DIR__"obj/table"]) )
		return -1;

	for(int i=sizeof(tables)-1; i>=0; i--)
		if(tables[i]->is_sxg()
		/*
		&& sizeof(filter_array(all_inventory(tables[i]),
			(: $1->is_food() || $1->is_liquid() :) )))
		*/
		&& (k = sizeof(inv = all_inventory(tables[i]))) )
			for(j=0;i<k;j++)
				if(inv[j]->is_food() || inv[j]->is_liquid())
					return 1;
	return 0;
}

protected void begin_play()
{
	if(find_call_out("lasting"))
		remove_call_out("lasting");

	tell_room(this_object(),"\nһ�����ø�ʽ���������Ĺ������������̨��
������������������ӡ���ɽ��ˮ��������������\n\n");
	call_out("lasting",20);
}

protected void lasting()
{
	string *melody = ({
"��̨�ϴ��������������ӡ�����ɢ��",
"������������������ӡ���������",
"̨�����������������ӡ�ϲ����"
 });

	if(((time() - time) > 360) || !have_food())
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
		do_refresh();
		return;
	}

	tell_room(this_object(),sprintf("\n%s%s ~ ~ ~ ~ ~ ~\n\n"NOR,
		colour[random(sizeof(colour))],melody[random(sizeof(melody))]));

	call_out("lasting",20);
}

void create()
{
	restore();

	set("short", "����¥����");
	set("long", @LONG
����һ�����������ã���������ڷ������Ŵ�����ľ���ӣ�
��ǰ����һ��Ϸ̨����ſ���һ�߻���һ������Ϸ�����ſ�����
һ�ź�ֽ(paper)������ǽ�Ϲ���һ���ľ��(pai)��
LONG
	);

	set("item_desc",([
	"pai" : (: pai_msg :),
	"paper" : "
����¥ר�ųа�(order)ϲ���ϯ
       ÿ��ʮ���ƽ�

  ������ϯ	order sr
  ���Ѿ���	order fd

",
]));

	set(SAFE_ENV,1);
	set("NONPC",1);

	set("exits", ([
  "down" : __DIR__"jiulou2",
]));

	set("objects",([
	__DIR__"obj/table" : 3,
]));

	setup();
	if(my_top && (sizeof(my_top) > 1))
		my_top = sort_array(my_top, (: sort_topten :));
}

void init()
{
	add_action("do_order","order");
}

int do_order(string arg)
{
	object me = this_player();

	if((arg != "fd") && (arg != "sr"))
		return notify_fail("����˵�����Բ�������ֻ����������᡹�͡����Ѿۻ᡹��\n");

	if(now && (me->query("id") != now))
		return notify_fail(sprintf("����˵�������ȵ�һ����ɣ�������������ٰ�%s�ء�\n",fd?"���Ѿۻ�":"�������"));

	if(open)
		return notify_fail("����˵�����Ե�һ��������ż������Ͼ�����\n");

	if(have_food())
		return notify_fail("����˵�����������ϻ���ô�ණ��û�����أ��ȳ�������˵�ɡ�\n");

	if(player_pay(me,100000) != 1)
		return notify_fail(sprintf("����ҡҡͷ˵����%sÿ��ʮ���ƽ�\n",arg=="fd"?"���Ѿۻ�":"�������"));


	now = me->query("id");
	me->add("pai_in_dxl",10);
	call_out("add_to_top",1,me);

	if(arg == "fd")
	{
		set("short", "������");
		fd = 1;
	}
	else
		set("short", "������");
	open = 1;
	write("����˵�����ã����Ե�һ�����\n");

	if(find_call_out("do_open") > 0)
		remove_call_out("do_open");
	call_out("do_open",3,me);
	return 1;
}

protected void do_open(object me)
{
	string *all;
	int i,n,j,k;
	object *tables;

	if(!objectp(me))
	{
		do_refresh();
		return;
	}

	tables = filter_array(query_temp("objects")[__DIR__"obj/table"] - ({0}),
		(: $1->is_sxg() && (environment($1) == this_object()) :));

	if(!(k = sizeof(tables)))
	{
		if(objectp(me))
			tell_object(me,"\n����˵����������ô���˰�������������ʦ�ɣ���\n\n");
		do_refresh();
		return;
	}

	all = get_dir(__DIR__"foods/");

	if( !(n = sizeof(all)) )
	{
		if(objectp(me))
			tell_object(me,"\n����˵����ԭ�϶�û�ˣ���������ʦ����ɣ���\n\n");
		return;
	}

	tell_room(this_object(),"\n�������ſ�һվ��������������������ϯ������ඡ�����������\n\n
ֻ�����˵�С����Ǵ�����Ϣ����һ��������ϾͲ�����ɽ�亣ζ��\n\n");

	if(environment(me) == this_object())
	{
		string ey;

		if(me->query("gender") == "����")
			ey = me->query("age")<=25?"����":"��ү";
		else
			ey = me->query("age")<=25?"��С��":"������";
		tell_room(__FILE__,sprintf("\n�����ߵ�%s��ǰһ��˵����\n\t��ף%s%s%s����\n\n",
			me->name(),
			me->name()[0..1],
			ey,
			fd?"������ѳ��ۣ������н��գ������н�":"���綫�����ٱ���ɽ"));
	}

	for(i=0;i<n;i++)
	{
		string file;

		if(file_size(file = sprintf(__DIR__"foods/%s",all[i])) > 0)
		{
			for(j=0;j<k;j++)
			{
				object ob = new(file);
				ob->move(tables[j]);
			}
		}
	}

	if(!fd)
	{
		all = get_dir(__DIR__"shou/");
		if(n = sizeof(all))
			for(i=0;i<n;i++)
			{
				string file;
		
				if(file_size(file = sprintf(__DIR__"shou/%s",all[i])) > 0)
				{
					for(j=0;j<k;j++)
					{
						object ob = new(file);
						ob->move(tables[j]);
					}
				}
			}
	}

	shout(sprintf(HIR BWHT"\n��%s�ھ�������¥%s���Ҳμӡ�\n\n" NOR,me->name(),
		fd?"�����д���������":"�����������"));

#ifdef __THIS_PLAYER_IN_CALL_OUT__
	tell_object(me,sprintf(HIR BWHT"\n��%s�ھ�������¥%s���Ҳμӡ�\n\n" NOR,me->name(),
		fd?"�����д���������":"�����������"));
#endif

	begin_play();
	open = 0; time = time();
}

string pai_msg()
{
	string out;
	int n;

	out = HIY"\n  ������¥ʮ��ƶ���\n"NOR;

	if(!(n = sizeof(my_top)))
	{
		out += "  (Ŀǰ��δ�����˹���)\n\n";
		return out;
	}

	if(n < 10)
		out += sprintf("  [ֻ��%s����������]\n\n",chinese_number(n));

	foreach(class top tmp in my_top)
		out += sprintf("%s(%s)\n\t���ڴ˻��� %d ���ƽ�\n",
			tmp->cname,capitalize(tmp->id),tmp->gold);

	return (out + "\n");
}

protected int sort_topten(class top t1, class top t2)
{
	if(t1->gold > t2->gold)
		return -1;
	return 1;
}

protected void add_to_top(object me)
{
	int i,n;
	class top nt;

	if(!me)
		return;

	nt = new(class top);
	nt->cname = me->name();
	nt->id = me->query("id");
	nt->gold = me->query("pai_in_dxl");

	if(!my_top || !(n = sizeof(my_top)))
	{
		my_top = ({ nt });
		save();
		return;
	}

	if(n < 10)
	{
		for(i=0;i<n;i++)
			if(my_top[i]->id == nt->id)
			{
				my_top[i]->gold = nt->gold;
				if(my_top[i]->cname != nt->cname)
					my_top[i]->cname = nt->cname;
				if(n > 1)
					my_top = sort_array(my_top, (: sort_topten :));
				save();
				return;
			}
		my_top += ({ nt });
		my_top = sort_array(my_top, (: sort_topten :));
		save();
		return;
	}

	if(nt->gold <= my_top[9]->gold)
		return;

	for(i=0;i<n;i++)
	{
		if(my_top[i]->id == nt->id)
		{
			my_top[i]->gold = nt->gold;
			if(my_top[i]->cname != nt->cname)
				my_top[i]->cname = nt->cname;
			my_top = sort_array(my_top, (: sort_topten :));
			save();
			return;
		}
	}

	my_top[9] = nt;
	my_top = sort_array(my_top, (: sort_topten :));
	save();
}
