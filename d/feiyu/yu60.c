// Room: /u/w/wangs/a/yu60.c

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
  "westdown" : __DIR__"yu59",
  "eastup" : __DIR__"yu61",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
