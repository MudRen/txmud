// Room: /d/fengtian/kd1.c

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

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"kd2",
  "east" : __DIR__"lf1",
  "north" : __DIR__"ll4",
]));

	set("objects",([
		NPC_DIR"xunpu" : 2,
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
