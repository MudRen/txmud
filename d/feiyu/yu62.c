// Room: /u/w/wangs/a/yu62.c

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
  "eastdown" : __DIR__"yu61",
  "northup" : __DIR__"yu63",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
