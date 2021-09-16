// Room: /d/changan/sroad5.c

inherit ROOM;

void create()
{
	set("short", "华瑞街");
	set("long", @LONG
长安城的南大街，而这一段是长安较繁华的地段，街面上人
来人往，不单是各地来的客旅，还有一些外国来的使节，也在这
里看看中国的民风，满街的做小买卖的生意人，忙的不亦乐乎。
北面有小镜湖，在繁华的京都里也算是一大景观。
LONG
	);
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"sroad6",
  "west" : __DIR__"sroad4",
  "north" : __DIR__"jinghu",
]));

	setup();
	replace_program(ROOM);
}
