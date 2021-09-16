// Room: /d/changan/ji2.c

inherit ROOM;

string fname = __DIR__"jiyuan";

void create()
{
	set("short", "回味轩");
	set("long", @LONG
清新的淡绿色使这里散发着一股浓浓的春意，几榻之上散乱
地放着几本书，你走到临窗小几前，一张雪白的宣纸上瓒花小楷
提着了几行诗句，你仔细一看，原来是诗经中的《燕燕》。看来
此间主人还是个才女呢。
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
	if(me->query_temp("jiyuan/sleep") != "怜玉") return 1;
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
		tell_object(this_object(),obj->name()+"幽怨的叹了一口气，走了。\n");
		destruct(obj);
		}
}