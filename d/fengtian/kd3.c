// Room: /d/fengtian/kd3.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����·�Ƿ����ϳǵ���Ҫ�ֵ�������·�ᴮ�����Ƿ���ǵ�
һ���Ͻ֣��ֵ�����ʯ�������ߵ���ͷ���˶�����ֻ���������
�������в���С�̵꣬��Ӫ������ʳס���Լ����ӵĻ��
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fruit",
  "west" : __DIR__"kd4",
  "east" : __DIR__"kd2",
  "north" : __DIR__"book",
]));
        set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
