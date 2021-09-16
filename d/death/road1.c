// Room: /d/death/road1.c

inherit ROOM;

void create()
{
	set("short", "望乡亭");
	set("long", @LONG
你来到一个破旧的小亭子前面，亭子上面有一块小木牌，上
写着“望乡亭”几个小子。你回头望去是一片青山绿水，隐约中
还能看到京城长安里熙熙攘攘的人群，回想起在世时候的生活你
不禁灿然泪下。向前看是灰蒙蒙的一片。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : "/d/death/road2",
		"south" : "/d/death/gateway",
	]));

	set("no_magic", 1);

	setup();
}