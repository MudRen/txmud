// Room: /d/c/sdoor.c

inherit ROOM;

void create()
{
	set("short", "成都南门");
	set("long", @LONG
这里就是蜀中重镇成都的南城门，厚厚的城墙上斑驳的痕迹
可以看出城镇历经沧桑战乱的历史，但至今依然坚固地屹立着。
进出城门的人川流不息，显示着今日的繁华。城门官用警惕的眼
睛，扫视着来来往往的人流，不时还叫住几个人盘问一番。城门
旁边贴着一张布告(bugao)。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"out_chengdu_s",
  "north" : __DIR__"shizi",
]));

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["south" : __DIR__"out_chengdu_s"]) );
	set( "close_look",@LONG
这里就是蜀中重镇成都的北城门，现在是宵禁时间，城门已
经关上了。静悄悄的只有守城的士兵们还警惕的站在这里。
LONG
);
	set( "gate_name","成都北门" );
*/
	set("objects",([
		NPC_DIR"city_guard" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
