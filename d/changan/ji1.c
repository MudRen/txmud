// Room: /d/changan/ji1.c

inherit ROOM;

string fname = __DIR__"jiyuan";

void create()
{
	set("short", "登仙阁");
	set("long", @LONG
鹅黄色的登仙阁中处处是锦被罗垫，其轻如云，其软如绵，
淡淡幽香轻触鼻端，尚未见人已是如登仙境，若是斜卧锦榻之上，
怀拥如花美人，真是给个神仙也不做了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jiyuan2",
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
	if(dir == "south" || dir == "s")
	{
	if(me->query_temp("jiyuan/sleep") != "红秀") return 1;
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

	if(obj = present("hong xiu",this_object())) {
		tell_object(this_object(),obj->name()+"幽怨的叹了一口气，走了。\n");
		destruct(obj);
		}
}
