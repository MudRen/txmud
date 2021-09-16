// Room: /d/fengtian/w_gate.c

inherit ROOM;

void create()
{
	set("short", "奉天西门");
	set("long", @LONG
这里是奉天的西门户，也是奉天与关内以及蒙古地区连接干
道的门户，在城门的一旁，帖着一个布告(bugao)。西城门没有
北门那么宏伟，不过也是壁垒森严了，不少官兵在这里检查过往
的路人。
LONG
	);

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"guanlu1",
  "west" : __DIR__"out_fengtian_w",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["west" : __DIR__"out_fengtian_w"]) );
	set( "close_look",@LONG
这里是奉天的西门户，也是奉天与关内以及蒙古地区连接干
道的门户，在城门的一旁，帖着一个布告(bugao)。现在是宵禁
时间，城门已经关上了。静悄悄的只有守城的士兵们还警惕的站
在这里。
LONG
);
	set( "gate_name","奉天府西门" );
*/
	set("objects",([
		__DIR__"npc/city_guard" : 2,
]));

        set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
