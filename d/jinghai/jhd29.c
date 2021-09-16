// Room: /d/jinghai/jhd29.c

inherit ROOM;

void create()
{
	set("short", "木匠作坊");
	set("long", @LONG
走进这里一股杉木的清香直冲胸臆，木匠是每个渔村里都少
不了的一种职业，渔民们要想在变幻莫测的大海里保住性命光靠
祈祷海神保佑还是不够的，最最要紧的是让自已的船能够经得起
海浪的拍打，所以几乎每个船夫都是一个优秀的木匠。这里整齐
的摆放着各种木工工具和刨得笔直光滑的圆木。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jhd28",
]));

	setup();
	replace_program(ROOM);
}
