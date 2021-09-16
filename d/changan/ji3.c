// Room: /d/changan/ji3.c

inherit ROOM;

string fname = __DIR__"jiyuan";

void create()
{
	set("short", "����");
	set("long", @LONG
�����е����ж�����Ⱦ�ɷۺ���ɫ��ʹ��һ���˴�������
���٣��鲻���ѣ������и����ŵ�һ����������㣬����ʹ��Ѫ
�����ţ����Ϣ�ȶ�������ͨ����۾�����Ѱ�ҿɹ���й��Ŀ�ꡣ
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jiyuan2",
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
	if(dir == "north" || dir == "n")
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

	if(obj = present("wan xiang",this_object())) {
		tell_object(this_object(),obj->name()+"��Թ��̾��һ���������ˡ�\n");
		destruct(obj);
		}
}