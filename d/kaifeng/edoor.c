// Room: /open/k/edoor.c

inherit ROOM;

void create()
{
	set("short", "开封东门");
	set("long", @LONG
这里就是开封的东城门了，开封是一座通渠大城，人口众多，
商业繁华，自古以来便是兵家必争之地。坚实的城楼有五丈多高，
数十名士兵整齐地站在城门边，警惕地审视着来往匆匆的行人。
这里不许摆摊设点，亦不准行人随便逗留，所以显得十分整洁、
严肃。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai147",
  "east" : __DIR__"out_kaifeng_e",
]));


        set("objects",([
        __DIR__"npc/guanbing" : 2,
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["east" : __DIR__"out_kaifeng_e"]) );
        set( "close_look",@LONG
这里就是开封的东城门了，开封是一座通渠大城，人口众多，
商业繁华，自古以来便是兵家必争之地。坚实的城楼有五丈多高。
LONG
);
        set( "gate_name","开封东门" );
*/
	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
