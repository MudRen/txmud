// Room: /d/fengtian/s_gate.c

inherit ROOM;

void create()
{
	set("short", "奉天南门");
	set("long", @LONG
奉天南门高三丈，宽约二丈有余，尺许厚的城门上镶满了拳
头般大小的柳钉。门洞长约四丈，大约每隔两个时辰就换官兵把
守。洞侧帖满了悬赏捉拿之类的官府布告(bugao)。
LONG
	);

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guanlu3",
  "south" : __DIR__"out_fengtian_s",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["south" : __DIR__"out_fengtian_s"]) );
	set( "close_look",@LONG
奉天南门高三丈，宽约二丈有余，尺许厚的城门上镶满了拳
头般大小的柳钉。城门已经关上了。静悄悄的只有守城的士兵们
还警惕的站在这里。
LONG
);
	set( "gate_name","奉天府南门" );
*/
	set("objects",([
		__DIR__"npc/city_guard" : 2,
]));

	set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
