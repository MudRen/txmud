// Room: /d/path5/e01.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ������С·��������ï�ܵ����֣�ϡ�ϵĹ���������
Ҷ��ҡ��һ��һ������ϡ���Կ���·�ĺۼ������ϵ����г�����
���ֹ�ľֲ�С�Ĳ�Ҫ�����Լ�Ŷ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"kch03",
  "east" : __DIR__"e02",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
