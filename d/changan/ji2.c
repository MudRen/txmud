// Room: /d/changan/ji2.c

inherit ROOM;

string fname = __DIR__"jiyuan";

void create()
{
	set("short", "��ζ��");
	set("long", @LONG
���µĵ���ɫʹ����ɢ����һ��ŨŨ�Ĵ��⣬���֮��ɢ��
�ط��ż����飬���ߵ��ٴ�С��ǰ��һ��ѩ�׵���ֽ��趻�С��
�����˼���ʫ�䣬����ϸһ����ԭ����ʫ���еġ����ࡷ������
�˼����˻��Ǹ���Ů�ء�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jiyuan2",
]));
	set("no_clean_up", 0);
	set("no_sleep_room",1);

	setup();
}

void init()
{
	add_action("do_quit","quit");
}

int do_quit(string arg)
{
	object obj;
	if(this_player()->query_temp("jiyuan")) {
	if(obj = present("m_boss",find_object(fname)))
		obj->delete_temp("have_full");
	return 0;
	}
	return 0;
}

int valid_leave(object me,string dir)
{
	object obj;
	if(dir == "east" || dir == "e")
	{
	if(me->query_temp("jiyuan/sleep") != "����") return 1;
	call_out("zou_ren",1);
	me->delete_temp("jiyuan");
	if(obj = present("m_boss",find_object(fname)))
		obj->delete_temp("have_full");
	return 1;
	}

	return 1;
}

void zou_ren()
{
	object obj;

	if(obj = present("lian yu",this_object())) {
		tell_object(this_object(),obj->name()+"��Թ��̾��һ���������ˡ�\n");
		destruct(obj);
		}
}