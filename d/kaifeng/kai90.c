// Room: /u/w/wangs/b/kai90.c

inherit ROOM;

void create()
{
	set("short", "巡捕房");
	set("long", @LONG
开封城人口众多，民风剽悍，又兼身为商业重镇，鸡鸣狗盗
之流多如牛毛，巡捕房的捕头们每年都忙得昏天黑地、焦头烂额。
但自从新来的府尹大嘴巴狼一到，便大力整饬，肃法正典，作奸
犯科之辈不论情节轻重，全都罪加三等。一月之内，便将诺大一
个开封城整治得路不拾遗，夜不闭户。现如今巡捕房已经是形如
虚设了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai89",
]));

	setup();
	replace_program(ROOM);
}
