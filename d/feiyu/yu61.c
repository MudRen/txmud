// Room: /u/w/wangs/a/yu61.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������ɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�����
���ƣ��������ش�졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"yu62",
  "westdown" : __DIR__"yu60",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
