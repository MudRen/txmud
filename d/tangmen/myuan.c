// Room: /d/tangmen/myuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�������Ƽұ�����Ժ��������Ժ��ׯ�����£����ܵĽ�����
��վ��һЩ��׳���ھ����Ѳ�ӡ�Ժ�����붫����ڷ�������
ʯ�⣬������Ƽұ����µ�ʱ�����ͷĿ���ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"yitong",
  "south" : __DIR__"gd5",
  "east" : __DIR__"ssl2",
  "west" : __DIR__"ssl1",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
