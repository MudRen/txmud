// design by ���ֺ�(find) . all right reserved.

// Room: /d/changan/jiyuan2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�ϵ�¥���㷢������Է��Ȼ����Ϊ���ǵ�һ���Ժ��������
���ò��õ�������ۼ��ȴ�ֲ�ʧ��������֮������������ľ���Σ�
�����ʣ��޲������ǡ���ô���������ЩС����Ҥ��Ĵ���
�̿ɱȣ��ܹ�ס���������ȻҲ�����ɻ��˰����Ů�ˡ��뵽��
���㲻����������������
LONG
	);
	set("no_steal",1);
	set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"ji4",
  "down" : __DIR__"jiyuan",
  "west" : __DIR__"ji2",
  "north" : __DIR__"ji1",
  "south" : __DIR__"ji3",
]));
	set("NORIDE",1);

	set("objects",([
	__DIR__"npc/gui_nu" :1
]));
	setup();
}

void init()
{
	add_action("do_accept","accept");
	add_action("do_quit","quit");
}

int do_quit(string arg)
{
	object obj;
	if(this_player()->query_temp("jiyuan")) {
	if(obj = present("m_boss",find_object(__DIR__"jiyuan")))
		obj->delete_temp("have_full");
	return 0;
	}
	return 0;
}

int do_accept(string arg)
{
	object obj,me = this_player();

	if(!me->query_temp("jiyuan/order"))
		return 0;

	if(!arg)
		return notify_fail("��ū˵����Ҫ����λ���\n");

	if(!objectp(obj = present(arg,this_object()))
	|| (obj->query("class") != "jiyuan")
	|| (obj->query("gender") != "Ů��")
	|| (obj->query("id") == "m_boss") )
		return notify_fail("��ū˵����Ҫ����λ���\n");

	me->delete_temp("jiyuan/shangqian");
	me->set_temp("jiyuan/shangqian",obj->name());
	message_vision("$N��ɬ��һƳ$n���εε�˵��лү������ū������ү�ܲ�����ū�����ٽ����䡣\n",obj,me);
	return 1;
}

int valid_leave(object me,string dir)
{
	object obj;
	if(dir == "down")
	{
	if(!me->query_temp("jiyuan/order")) return 1;
	call_out("zou_ren",2);
	me->delete_temp("jiyuan");
	if(obj = present("m_boss",find_object(__DIR__"jiyuan")))
		obj->delete_temp("have_full");
	return 1;
	}

	return 1;
}

void zou_ren()
{
	object obj;
	if(obj = present("lian yu",this_object())) {
		tell_object(this_object(),obj->name()+"���ˡ�\n");
		destruct(obj);
		}
	if(obj = present("wan xiang",this_object())) {
		tell_object(this_object(),obj->name()+"���ˡ�\n");
		destruct(obj);
		}
	if(obj = present("xiang yu",this_object())) {
		tell_object(this_object(),obj->name()+"���ˡ�\n");
		destruct(obj);
		}
	if(obj = present("hong xiu",this_object())) {
		tell_object(this_object(),obj->name()+"���ˡ�\n");
		destruct(obj);
		}
}

void open_close_door(string msg,object user)
{
	object ob = present("gui nu",this_object());
	string fname = __DIR__"jiyuan";

	if(!msg || !user || !ob || user->query_temp("jiyuan/order"))
		return;
	if( msg == "begin_day")
	{
		tell_object(user,"��ū�ߵ�����ǰһ����˵������λ"+
			RANK_D->query_respect(user)+"�������ˣ�������Ҫ��Ϣ�ˡ�
˵�Ű����¥������������\n\n");
		user->move(fname);
		tell_room(__FILE__,user->name()+"�����뿪��\n");
		tell_room(fname,user->name()+"��¥������������\n",({ user }));
	}
}
