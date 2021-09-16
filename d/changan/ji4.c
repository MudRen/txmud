// Room: /d/changan/ji4.c

inherit ROOM;

string fname = __DIR__"jiyuan";

void create()
{
	set("short", "ů���");
	set("long", @LONG
�����ڴˣ��㲻����ǽ��֣��ݽǴ�����һ���̿������һ
�ҽԴ�����Ƶĵƹ���һ�����˵�Ů������ʹ���������ԣ�����
����Ѱ���������������һ��ɾ���ȴ����ʧ�����޴����ڵİ���
����֮���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jiyuan2",
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
	if(dir == "west" || dir == "w")
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

	if(obj = present("xiang yu",this_object())) {
		tell_object(this_object(),obj->name()+"��Թ��̾��һ���������ˡ�\n");
		destruct(obj);
		}
}