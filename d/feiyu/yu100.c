// Room: /u/w/wangs/a/yu100.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�������������С��԰����ֲ��һЩ�в�����������
��ľ�������԰��Ȼ���󣬵�����ľ������������ĳ�����
����һ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"yu101",
  "west" : __DIR__"yu67",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
