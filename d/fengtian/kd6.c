// Room: /d/fengtian/kd6.c

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

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kd5",
  "northwest" : __DIR__"kd7",
]));

	set("objects",([
		NPC_DIR"xunpu" : 1,
]));

        set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
