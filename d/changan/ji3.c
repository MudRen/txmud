// Room: /d/changan/ji3.c

inherit ROOM;

string fname = __DIR__"jiyuan";

void create()
{
	set("short", "醉花轩");
	set("long", @LONG
醉花轩中的所有东西都染成粉红颜色，使人一到此处便心跳
加速，情不自已，空气中浮动着的一股腻腻的甜香，更是使人血
脉贲张，你鼻息扇动，瞪着通红的眼睛到处寻找可供发泄的目标。
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
	if(me->query_temp("jiyuan/sleep") != "婉香") return 1;
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
		tell_object(this_object(),obj->name()+"幽怨的叹了一口气，走了。\n");
		destruct(obj);
		}
}