// Room: /d/changan/jiulou2.c

inherit ROOM;

void create()
{
        set("short", "谪仙楼二层");
        set("long", @LONG
这里是谪仙楼的二楼，由于谪仙楼的名气，所以在京城来往
的达官贵人宴请、小酌都要来这里。窗外是熙熙攘攘的京城永泰
路，楼内是一片觥筹交错，老板在四处招呼着客人。
LONG
        );

        set("night_long",@LONG
这里是谪仙楼的二楼。现在已经打烊了。四处收拾得干干净
净，老板正靠在桌边打盹。
LONG
);
        set("no_clean_up", 0);
        set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 1 */
	"down" : __DIR__"jiulou",
	"up" : __DIR__"jiulou3",
]));
        set("objects",([
        __DIR__"npc/zuixiange_boss" : 1,
//	"/obj/gift/men" : 1,
]));
        set("NORIDE","小店楼梯太窄，您老骑着坐骑可是上不去。");
        setup();
        replace_program(ROOM);
}
