// Room: /d/fengtian/lang1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ͨ����԰�����ȣ��������ԶԶ�����������ĺ�Ժ
������һ����Ϳ����ȵ������ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"chufang",
  "north" : __DIR__"jjf3",
]));

	setup();
	replace_program(ROOM);
}
