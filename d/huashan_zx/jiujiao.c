// Room: jiujiao.c by pian

inherit ROOM;
void create()
{
	set("short","酒窖");
	set("long",@LONG
这是华山派储酒的酒窖，如果师傅叫你取酒你就可以来这里
拿了。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"eastup" : __DIR__"jiufang",
	//"south":__DIR__"guodaoe8",
]));
	set("indoors", "huashan_p");
	setup();
	replace_program(ROOM);
}