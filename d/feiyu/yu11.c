// Room: /u/w/wangs/a/yu11.c

inherit ROOM;

void create()
{
	set("short", "Сľ��");
	set("long", @LONG
������һ��Сľ��ǰ������ȥ�䲻�Ǻܺ��������Ե�ͦ
���¡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"yu12",
  "west" : __DIR__"yu10",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
