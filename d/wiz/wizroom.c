// Room: /d/wiz/wizroom.c

inherit ROOM;

void create()
{
	set("short", "巫师交流区");
	set("long", @LONG
此地是巫师交流园地，巫师有什么问题、意见、建议均可在
此地留言。
LONG
	);

	set("exits",([
	"down" : "/d/changan/jiulou",
]));

	setup();
	set("valid_startroom", 1);
	load_board("board_wiz");
}
