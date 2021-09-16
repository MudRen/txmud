// Room: /d/changan/hu_bank.c

inherit ROOM;

void create()
{
	set("short", "湖岸");
	set("long", @LONG
这里是小镜湖畔，也是文人骚客经常来吟诗作对的地方，偶
尔也有一些朝廷官员便装来到这里游玩。湖水清澈见底，据说是
西山的龙泉水通到这里，当年朝廷定都长安也是因为此湖的灵气
所至，人们离开京城之前都要来这里灌(fill)些水带着据说还能
保佑一路平安。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jinghu",
  "west" : __DIR__"sroad9",
]));

	set("outdoors","changan");
	set("resource/water",1);
	setup();
	replace_program(ROOM);
}
