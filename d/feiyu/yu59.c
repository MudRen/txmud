// Room: /u/w/wangs/a/yu59.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ��ɽ·�ϣ�����ɽ����䣬�������ϪȪ
���٣��������ƣ��������ش�졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"yu58",
  "eastup" : __DIR__"yu60",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
