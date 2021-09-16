// Room: sleeroom.c

inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
这里是华山派弟子的休息室。房中靠墙摆这一排通铺，屋子
洒扫的很干净，看起来一尘不染的。四周的窗户都紧闭着，光线
很暗，躺在铺上，你很快进入了梦乡。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"guodaoe2",
]));
	set("sleep_room", 1);
	set(SAFE_ENV,1);

	setup();
}
